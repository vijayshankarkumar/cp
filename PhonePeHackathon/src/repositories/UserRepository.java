package repositories;

import entities.User;
import exceptions.UserAlreadyExistException;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class UserRepository {
    List<User> users;

    public UserRepository() {
        this.users = new ArrayList<>();
    }

    public User save(User user) throws UserAlreadyExistException {
        Optional<User> dbUser = users.stream().filter(u ->u.getId() == user.getId()).findAny();
        if (dbUser.isPresent()) {
            throw new UserAlreadyExistException("User already exist with userId: " + user.getId());
        }
        else {
            users.add(user);
        }
        return user;
    }

    public Optional<User> findById(int userId) {
        System.out.println(users.size());
        for (User user : users) {
            System.out.println("Got user with id: " + user.getId());
        }
        return users.stream().filter(u -> u.getId() == userId).findFirst();
    }

    public List<User> findAll() {
        return users;
    }
}
