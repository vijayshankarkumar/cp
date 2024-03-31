package repositories;

import entities.Department;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class DepartmentRepository {
    List<Department> departments;

    public DepartmentRepository() {
        departments = new ArrayList<>();
        departments.add(new Department(0, "Computer Science"));
        departments.add(new Department(1, "Mechanical Engineering"));
        departments.add(new Department(2, "Information Technology"));
    }

    public Department save(Department department) {
        departments.add(department);
        return department;
    }

    public Optional<Department> findByName(String name) {
        return departments.stream()
                .filter(department -> department.getName().equalsIgnoreCase(name)).findFirst();
    }
}
