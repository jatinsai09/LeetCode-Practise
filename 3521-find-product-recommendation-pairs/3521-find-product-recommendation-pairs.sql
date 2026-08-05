# Write your MySQL query statement below
WITH cte AS (
    SELECT 
        pp.user_id,
        pp.product_id,
        pi.category
    FROM ProductPurchases pp
    JOIN ProductInfo pi
        ON pp.product_id = pi.product_id
),
cte1 AS (
    SELECT 
        c1.user_id,
        c1.product_id AS product1_id,
        c2.product_id AS product2_id,
        c1.category AS product1_category,
        c2.category AS product2_category
    FROM cte c1
    JOIN cte c2
        ON c1.user_id = c2.user_id
        AND c1.product_id < c2.product_id
)

SELECT 
    product1_id,
    product2_id,
    product1_category,
    product2_category,
    COUNT(*) AS customer_count
FROM cte1 
GROUP BY product1_id, product2_id
HAVING customer_count > 2
ORDER BY customer_count DESC, product1_id, product2_id;