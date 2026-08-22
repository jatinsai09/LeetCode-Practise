# Write your MySQL query statement below
WITH cte1 AS (
    SELECT 
        employee_id,
        DATEDIFF(meeting_date, "1900-01-01") DIV 7 AS week,
        SUM(duration_hours) AS hours
    FROM meetings
    GROUP BY employee_id, week
),
cte2 AS (
    SELECT
        employee_id,
        COUNT(*) AS meeting_heavy_weeks
    FROM cte1
    WHERE hours > 20
    GROUP BY employee_id
)

SELECT
    e.employee_id,
    e.employee_name,
    e.department,
    meeting_heavy_weeks
FROM employees e
JOIN cte2
ON e.employee_id = cte2.employee_id
WHERE meeting_heavy_weeks > 1
ORDER BY meeting_heavy_weeks DESC, e.employee_name;