# Write your MySQL query statement below
SELECT e1.employee_id, e1.name,
count(e2.employee_id) as reports_count,
round(avg(e2.age)) as average_age
FROM employees e1, employees e2
WHERE e1.employee_id = e2.reports_to
GROUP BY e1.employee_id
ORDER BY e1.employee_id;