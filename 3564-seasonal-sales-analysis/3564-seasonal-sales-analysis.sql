# Write your MySQL query statement below
WITH cte1 AS (
    SELECT
        CASE
            WHEN MONTH(s.sale_date) IN (9, 10, 11) THEN 'Fall'
            WHEN MONTH(s.sale_date) IN (3, 4, 5) THEN 'Spring'
            WHEN MONTH(s.sale_date) IN (6, 7, 8) THEN 'Summer'
            ELSE 'Winter'
        END AS season,
        p.category,
        SUM(s.quantity) AS total_quantity,
        SUM(s.quantity * s.price) AS total_revenue 
        FROM Sales s
        JOIN Products p
            ON s.product_id = p.product_id
        GROUP BY season, p.category
),
cte2 AS (
    SELECT
        season,
        category,
        total_quantity,
        total_revenue,
        ROW_NUMBER() OVER (
            PARTITION BY season
            ORDER BY total_quantity DESC, total_revenue DESC, category ASC
        ) AS rnk
    FROM cte1
)

SELECT 
    season,
    category,
    total_quantity,
    total_revenue
FROM cte2
WHERE rnk = 1
ORDER BY season;