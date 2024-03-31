package constants;

import java.util.Arrays;
import java.util.Optional;

public enum DifficultyLevelEnum {
    EASY("EASY"), MEDIUM("MEDIUM"), HARD("HARD");

    final String name;

    DifficultyLevelEnum(String name) {
        this.name = name;
    }

    public static Optional<DifficultyLevelEnum> getByName(String name) {
        return Arrays.stream(DifficultyLevelEnum.values()).filter(e -> e.getName().equalsIgnoreCase(name)).findFirst();
    }

    public String getName() {
        return this.name;
    }
}
