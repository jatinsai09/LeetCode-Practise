# Write your MySQL query statement below
WITH FirstExams AS (
    SELECT student_id, subject, MIN(exam_date) AS first_date
    FROM Scores
    GROUP BY student_id, subject
    HAVING COUNT(exam_date) > 1
),
LatestExams AS (
    SELECT student_id, subject, MAX(exam_date) AS latest_date
    FROM Scores
    GROUP BY student_id, subject
    HAVING COUNT(exam_date) > 1
)

SELECT
    f.student_id,
    f.subject,
    s1.score AS first_score,
    s2.score AS latest_score
FROM FirstExams f
JOIN LatestExams l
    ON f.student_id = l.student_id AND f.subject = l.subject
JOIN Scores s1
    ON f.student_id = s1.student_id AND f.subject = s1.subject AND f.first_date = s1.exam_date
JOIN Scores s2
    ON l.student_id = s2.student_id AND l.subject = s2.subject AND l.latest_date = s2.exam_date
WHERE s2.score > s1.score
ORDER BY f.student_id, f.subject;
