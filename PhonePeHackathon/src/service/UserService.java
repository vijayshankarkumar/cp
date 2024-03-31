package service;

import dto.requests.AddUserRequest;
import dto.responses.AddUserResponse;
import entities.Department;
import entities.User;
import exceptions.InvalidDepartmentException;
import exceptions.UserAlreadyExistException;
import repositories.DepartmentRepository;
import repositories.UserRepository;

import java.util.List;
import java.util.Optional;

public class UserService {

    private final UserRepository userRepository;
    private final DepartmentRepository departmentRepository;

    public UserService() {
        this.userRepository = new UserRepository();
        this.departmentRepository  = new DepartmentRepository();
    }

    public Optional<User> findById(int userId) {
        return userRepository.findById(userId);
    }

    public AddUserResponse addUser(AddUserRequest addUserRequest) throws UserAlreadyExistException, InvalidDepartmentException {
        Optional<Department> department = departmentRepository.findByName(addUserRequest.getDepartmentName());
        if (department.isPresent()) {
            User user = new User();
            user.setName(addUserRequest.getName());
            user.setDepartment(department.get());
            User dbUser = userRepository.save(user);
            return new AddUserResponse(dbUser.getId(), dbUser.getName());
        }
        else {
            throw new InvalidDepartmentException("Department with name: " + addUserRequest.getDepartmentName() + " does not exist");
        }
    }

    public List<User> getAllUsers() {
        return userRepository.findAll();
    }
}
