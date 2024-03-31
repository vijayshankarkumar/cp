package dto.requests;

import java.util.List;

public class AddProblemRequest {
    private String description;
    private List<String> tags;
    private String difficultyLevel;
    private int score;

    public AddProblemRequest() {}

    public AddProblemRequest(String description, List<String> tags, String difficultyLevel, int score) {
        this.description = description;
        this.tags = tags;
        this.difficultyLevel = difficultyLevel;
        this.score = score;
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

    public void setTag(List<String> tag) {
        this.tags = tag;
    }

    public String getDifficultyLevel() {
        return difficultyLevel;
    }

    public void setDifficultyLevel(String difficultyLevel) {
        this.difficultyLevel = difficultyLevel;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score = score;
    }
}
