package dto.requests;

public class AddUserRequest {
    private String name;
    private String departmentName;

    public AddUserRequest() {}

    public AddUserRequest(String name, String departmentName) {
        this.name = name;
        this.departmentName = departmentName;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDepartmentName() {
        return departmentName;
    }

    public void setDepartmentName(String departmentName) {
        this.departmentName = departmentName;
    }

}
