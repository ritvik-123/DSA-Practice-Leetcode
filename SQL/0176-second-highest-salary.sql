-- 176. Second Highest Salary (Medium)
-- https://leetcode.com/problems/second-highest-salary/
-- Approach: DISTINCT salaries ordered desc, LIMIT 1 OFFSET 1 to skip the top salary

SELECT
(
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1
)
AS SecondHighestSalary;
