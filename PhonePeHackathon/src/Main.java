import controllers.ProblemAPI;
import controllers.UserAPI;
import dto.requests.AddProblemRequest;
import dto.requests.AddUserRequest;
import entities.Problem;
import entities.User;

import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello PhonePe!");

        UserAPI userAPI = new UserAPI();
        ProblemAPI problemAPI = new ProblemAPI();

        userAPI.addUser(new AddUserRequest("Vijay", "Computer Science"));
        userAPI.addUser(new AddUserRequest("Shankar", "Information Technology"));

//        List<User> users = userAPI.getAllUsers();
//        for (User user : users) {
//            System.out.println("Got user with id: " + user.getId() + " and name: " + user.getName());
//        }
//
//        User user = userAPI.getById(1);
//        System.out.println("Got user with id: " + user.getId());

        problemAPI.addProblem(new AddProblemRequest("This is problem no. 1", Arrays.asList("DP", "Array"), "EASY", 10));
        problemAPI.addProblem(new AddProblemRequest("This is problem no. 2", Arrays.asList("Binary Search", "Tree", "Array"), "MEDIUM", 20));
        problemAPI.addProblem(new AddProblemRequest("This is problem no. 3", Arrays.asList("Graph", "String", "Sliding Window"), "HARD", 30));
        problemAPI.addProblem(new AddProblemRequest("This is problem no. 4", Arrays.asList("Tree", "Bit Masking"), "EASY", 10));

        List<Problem> problems = problemAPI.getAllProblems();
        for (Problem problem : problems) {
            System.out.println("Got problem with id: " + problem.getId() + " with description: " + problem.getDescription());
        }

        List<Problem> problemsByTag = problemAPI.getAllProblemsWithTag("Array");
        for (Problem problem : problemsByTag) {
            System.out.print("Got problem with id: " + problem.getId() + " with description: " + problem.getDescription() + " with tags");
            for (String tag : problem.getTags()) {
                System.out.print(tag + ", ");
            }
            System.out.println();
        }

        List<Problem> problemsWithDifficultyLevel = problemAPI.getAllProblemsByDifficultyLevel("EASY");
        for (Problem problem : problemsWithDifficultyLevel) {
            System.out.println("Got problem with id: " + problem.getId() + " with description: " + problem.getDescription() + " with difficulty level: " + problem.getDescription());
        }

        problemAPI.solveProblem(1, 1);
        problemAPI.solveProblem(2, 1);
        problemAPI.solveProblem(3, 2);
        problemAPI.solveProblem(4, 2);

        List<Problem> problemsSolvedByUserId1 = problemAPI.getAllProblemsSolved(1);
        for (Problem problem : problemsSolvedByUserId1) {
            System.out.println("For userId: 1 Got problem with id: " + problem.getId() + " with description: " + problem.getDescription() + " with difficulty level: " + problem.getDescription());
        }

        List<Problem> problemsSolvedByUserId2 = problemAPI.getAllProblemsSolved(1);
        for (Problem problem : problemsSolvedByUserId2) {
            System.out.println("For userId: 2 Got problem with id: " + problem.getId() + " with description: " + problem.getDescription() + " with difficulty level: " + problem.getDescription());
        }
    }
}
