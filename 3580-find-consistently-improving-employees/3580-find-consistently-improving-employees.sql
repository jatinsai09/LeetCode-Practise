# Write your MySQL query statement below
WITH cte1 AS (
    SELECT
        pr.employee_id,
        e.name,
        pr.rating,
        RANK() OVER (PARTITION BY pr.employee_id ORDER BY pr.review_date DESC) AS rnk
    FROM performance_reviews pr
    JOIN employees e 
    ON pr.employee_id = e.employee_id
),
cte2 AS (
    SELECT 
        employee_id,
        name,
        MAX(CASE WHEN rnk = 1 THEN rating END) AS latest_rating,
        MAX(CASE WHEN rnk = 2 THEN rating END) AS second_rating,
        MAX(CASE WHEN rnk = 3 THEN rating END) AS third_rating
    FROM cte1
    GROUP BY employee_id
)

SELECT 
    employee_id,
    name,
    latest_rating - third_rating AS improvement_score
FROM cte2
WHERE third_rating IS NOT NULL
    AND latest_rating > second_rating
    AND second_rating > third_rating
ORDER BY improvement_score DESc, name;