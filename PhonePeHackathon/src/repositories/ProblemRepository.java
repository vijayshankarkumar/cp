package repositories;

import constants.DifficultyLevelEnum;
import entities.Problem;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

public class ProblemRepository {

    private static int nextId = 1;

    //Database
    List<Problem> problems;

    private int id;

    public ProblemRepository() {
        this.problems = new ArrayList<>();
        this.id = nextId++;
    }

    public Problem save(Problem problem) {
        Optional<Problem> dbProblem = problems.stream()
                .filter(q -> q.getId() == problem.getId())
                .findAny();
        if (dbProblem.isPresent()) {
            dbProblem.get().setDescription(problem.getDescription());
            dbProblem.get().setScore(problem.getScore());
            dbProblem.get().setDifficultyLevel(problem.getDifficultyLevel());
        }
        else {
            problem.setId(id++);
            problems.add(problem);
        }
        return problem;
    }

    public Optional<Problem> findById(int id) {
        return problems.stream()
                .filter(problem -> id == problem.getId())
                .findFirst();
    }

    public List<Problem> findAll() {
        return problems;
    }

    public List<Problem> findAllByDifficultyLevel(DifficultyLevelEnum difficultyLevel) {
        return problems.stream()
                .filter(problem -> problem.getDifficultyLevel() == difficultyLevel).collect(Collectors.toList());
    }

    public List<Problem> findAllByTag(String tag) {
        return problems.stream()
                .filter(problem -> problem.getTags().stream()
                        .anyMatch(t -> t.equalsIgnoreCase(tag))).collect(Collectors.toList());
    }

    public List<Problem> findAllByUserId(int userId) {
        return problems.stream()
                .filter(problem -> problem.getUsersSolved().stream()
                        .anyMatch(user -> user.getId() == userId)).collect(Collectors.toList());
    }
}
