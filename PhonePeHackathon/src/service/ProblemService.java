package service;

import constants.DifficultyLevelEnum;
import dto.requests.AddProblemRequest;
import dto.responses.AddProblemResponse;
import entities.Problem;
import entities.User;
import repositories.ProblemRepository;

import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

public class ProblemService {

    private final ProblemRepository problemRepository;

    private final UserService userService;

    public ProblemService() {
        this.problemRepository = new ProblemRepository();
        this.userService = new UserService();
    }

    public AddProblemResponse addProblem(AddProblemRequest request) throws Exception {
        Optional<DifficultyLevelEnum> difficultyLevelEnum = DifficultyLevelEnum.getByName(request.getDifficultyLevel());
        if (difficultyLevelEnum.isPresent()) {
            Problem problem = new Problem();
            problem.setDescription(request.getDescription());
            problem.setTags(request.getTags());
            problem.setDifficultyLevel(difficultyLevelEnum.get());
            problem.setScore(request.getScore());
            Problem dbProblem = problemRepository.save(problem);
            return new AddProblemResponse(dbProblem.getId(), dbProblem.getDescription());
        }
        else {
            throw new Exception("Invalid difficulty level");
        }
    }

    public List<Problem> getAllProblems() {
        return problemRepository.findAll();
    }

    public List<Problem> getAllProblemsWithTag(String tag) {
        return problemRepository.findAllByTag(tag);
    }

    public List<Problem> getAllProblemsByDifficultyLevel(String difficultyLevel) throws Exception {
        Optional<DifficultyLevelEnum> difficultyLevelEnum = DifficultyLevelEnum.getByName(difficultyLevel);
        if (difficultyLevelEnum.isPresent()) {
            return problemRepository.findAllByDifficultyLevel(difficultyLevelEnum.get());
        }
        else {
            throw new Exception("Invalid difficulty level");
        }
    }

    public void solveProblem(int problemId, int userId) throws Exception {
        Optional<Problem> problem = problemRepository.findById(problemId);
        if (problem.isPresent()) {
            try {
                problem.get().getUsersSolved().add(userService.findById(userId).orElseThrow(() -> new Exception("User does not exit with id: " + userId)));
            } catch (Exception e) {
                System.out.println("Exception occurred while solving problem with userId: " + userId + " with message: " + e.getMessage());
            }
        }
        else {
            throw new Exception("Problem does not exist with id: " + problemId);
        }
    }

    public List<Problem> getAllProblemsSolved(int userId) throws Exception {
        Optional<User> user = userService.findById(userId);
        if (user.isPresent()) {
            return problemRepository.findAll().stream()
                    .filter(p -> p.getUsersSolved().stream()
                            .anyMatch(u -> u.getId() == userId)).collect(Collectors.toList());
        }
        else {
            throw new Exception("User does not exist with id: " + userId);
        }
    }
}
