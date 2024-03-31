package controllers;

import dto.requests.AddProblemRequest;
import dto.responses.AddProblemResponse;
import entities.Problem;
import service.ProblemService;

import java.util.ArrayList;
import java.util.List;

public class ProblemAPI {

    private final ProblemService problemService;

    public ProblemAPI() {
        this.problemService = new ProblemService();
    }

    public AddProblemResponse addProblem(AddProblemRequest request) {
        AddProblemResponse response = new AddProblemResponse();
        try {
            response = problemService.addProblem(request);
        } catch (Exception e) {
            System.out.println("Exception occurred while adding problem with message: " + e.getMessage());
        }
        return  response;
    }

    public List<Problem> getAllProblems() {
        return problemService.getAllProblems();
    }

    public List<Problem> getAllProblemsWithTag(String tag) {
        return problemService.getAllProblemsWithTag(tag);
    }

    public List<Problem> getAllProblemsByDifficultyLevel(String level) {
        List<Problem> problems = new ArrayList<>();
        try {
            problems = problemService.getAllProblemsByDifficultyLevel(level);
        }
        catch (Exception e) {
            System.out.println("Exception occurred while fetching all problems with tag with message: " + e.getMessage());
        }
        return problems;
    }

    public void solveProblem(int problemId, int userId) {
        try {
            problemService.solveProblem(problemId, userId);
        } catch (Exception e) {
            System.out.println("Exception occurred while solving problem with message: " + e.getMessage());
        }
    }

    public List<Problem> getAllProblemsSolved(int userId) {
        List<Problem> problems = new ArrayList<>();
        try {
            problems = problemService.getAllProblemsSolved(userId);
        } catch (Exception e) {
            System.out.println("Exception occurred while fetching all problem solved by userId: " + userId + " with message: " + e.getMessage());
        }
        return problems;
    }
}
