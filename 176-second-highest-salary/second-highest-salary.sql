-- select distinct salary as SecondHighestSalary from Employee order by salary desc limit 1 offset 1;
-- SELECT DISTINCT salary as SecondHighestSalary
-- FROM Employee
-- ORDER BY salary DESC
-- LIMIT 1 OFFSET 1;

SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary < (SELECT MAX(salary) FROM Employee);