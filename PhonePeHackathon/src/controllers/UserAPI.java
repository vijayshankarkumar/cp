package controllers;

import dto.requests.AddUserRequest;
import dto.responses.AddUserResponse;
import entities.User;
import exceptions.InvalidDepartmentException;
import exceptions.UserAlreadyExistException;
import service.UserService;

import java.util.List;

public class UserAPI {

    private final UserService userService;

    public UserAPI() {
        this.userService = new UserService();
    }

    public AddUserResponse addUser(AddUserRequest addUserRequest) {
        AddUserResponse response = new AddUserResponse();
        try {
            response = userService.addUser(addUserRequest);
        }
        catch (UserAlreadyExistException e) {
            System.out.println("Raised UserAlreadyExistException with message: " + e.getMessage());
        } catch (InvalidDepartmentException e) {
            System.out.println("Raised InvalidDepartmentException with message: " + e.getMessage());
        }
        return response;
    }

    public List<User> getAllUsers() {
        return userService.getAllUsers();
    }

    public User getById(int id) {
        return userService.findById(id).get();
    }
}
