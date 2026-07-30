CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      WITH cte AS (
        SELECT salary,
               DENSE_RANK() OVER (ORDER BY salary DESC) as rnk
        FROM Employee
      )
      SELECT DISTINCT salary
      FROM cte
      WHERE rnk = N
  );
END