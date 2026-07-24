# Write your MySQL query statement below
WITH cte AS (
    SELECT *, ROW_NUMBER() OVER (PARTITION BY email ORDER BY id) rn
    FROM Person
)
DELETE 
FROM Person 
WHERE id NOT IN (
    SELECT id 
    FROM cte
    WHERE rn = 1
);