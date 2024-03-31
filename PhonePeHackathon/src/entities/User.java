package entities;

public class User {
    private static int nextId = 1;
    private int id;
    private String name;
    private Department department;

    public User() {
        this.id = nextId++;
    }

    public User(int id, String name, Department department) {
        this.id = nextId++;
        this.name = name;
        this.department = department;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Department getDepartment() {
        return department;
    }

    public void setDepartment(Department department) {
        this.department = department;
    }
}
