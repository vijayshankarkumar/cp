package entities;

import constants.DifficultyLevelEnum;

import java.util.List;

public class Problem {
    private int id;
    private String description;
    private List<String> tags;
    private DifficultyLevelEnum difficultyLevel;
    private int score;
    private int like;
    private List<User> usersSolved;

    public Problem() {}

    public Problem(int id, String description, List<String> tags, DifficultyLevelEnum difficultyLevel, int score) {
        this.id = id;
        this.description = description;
        this.tags = tags;
        this.difficultyLevel = difficultyLevel;
        this.score = score;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public List<String> getTags() {
        return tags;
    }

    public void setTags(List<String> tags) {
        this.tags = tags;
    }

    public DifficultyLevelEnum getDifficultyLevel() {
        return difficultyLevel;
    }

    public void setDifficultyLevel(DifficultyLevelEnum difficultyLevel) {
        this.difficultyLevel = difficultyLevel;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score = score;
    }

    public int getLike() {
        return like;
    }

    public void setLike(int like) {
        this.like = like;
    }

    public List<User> getUsersSolved() {
        return usersSolved;
    }

    public void setUsersSolved(List<User> usersSolved) {
        this.usersSolved = usersSolved;
    }
}
