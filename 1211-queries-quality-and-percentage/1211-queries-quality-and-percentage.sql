# Write your MySQL query statement below
SELECT
    query_name, 
    ROUND(
        AVG((1.0 * rating) / position),
        2
    ) AS quality,
    ROUND(
        (1.0 * SUM(rating < 3) / COUNT(*)) * 100,
        2
    ) AS poor_query_percentage
FROM Queries
GROUP BY query_name;