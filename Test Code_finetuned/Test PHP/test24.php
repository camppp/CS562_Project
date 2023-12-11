async function populateTable() {
    const response = await fetch('https://api.example.com/departments');
    const data = await response.json();

    const table = document.getElementById('departmentTable');

    data.forEach(department => {
        const row = document.createElement('tr');

        const nameCell = document.createElement('td');
        nameCell.textContent = department.name;
        row.appendChild(nameCell);

        const employeesCell = document.createElement('td');
        employeesCell.textContent = department.employees;
        row.appendChild(employeesCell);

        const salaryCell = document.createElement('td');
        salaryCell.textContent = department.averageSalary;
        row.appendChild(salaryCell);

        table.appendChild(row);
    });
}