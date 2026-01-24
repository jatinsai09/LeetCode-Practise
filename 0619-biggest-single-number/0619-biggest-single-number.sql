# Write your MySQL query statement below
-- SELECT MAX(num) AS num
-- FROM MyNumbers
-- WHERE num IN (
--     SELECT num
--     FROM MyNumbers
--     GROUP BY num
--     HAVING COUNT(*) = 1
-- );

SELECT (
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(*) = 1
    ORDER BY num DESC
    LIMIT 1
) AS num