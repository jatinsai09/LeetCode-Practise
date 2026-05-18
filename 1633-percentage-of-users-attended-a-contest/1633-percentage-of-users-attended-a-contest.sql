# Write your MySQL query statement below
SELECT contest_id,
       round(count(user_id) * 100 / (select count(user_id) FROM users), 2) AS percentage
FROM register 
GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC;       