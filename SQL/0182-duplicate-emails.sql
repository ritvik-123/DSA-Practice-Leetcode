-- 182. Duplicate Emails (Easy)
-- https://leetcode.com/problems/duplicate-emails/
-- Approach: subquery groups by email, COUNT(*) > 1 identifies duplicate emails

SELECT email
FROM
(
    SELECT email, count(*) AS ctr FROM Person GROUP BY email
) AS duplicate_email
where ctr>1;
