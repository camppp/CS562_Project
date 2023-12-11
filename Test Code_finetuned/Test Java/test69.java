import java.util.Map;

public class Employee {
    private String name;
    private int id;
    private double salary;

    // Constructor and other methods are not shown for brevity

    public void setSalary(Map<String, String> record) {
        if (record.containsKey("Salary")) {
            this.salary = Double.parseDouble(record.get("Salary"));
        } else {
            throw new IllegalArgumentException("Record does not contain a Salary value");
        }
    }
}