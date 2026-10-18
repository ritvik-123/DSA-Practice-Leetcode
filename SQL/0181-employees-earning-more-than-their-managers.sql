-- 181. Employees Earning More Than Their Managers (Easy)
-- https://leetcode.com/problems/employees-earning-more-than-their-managers/
-- Approach: self-join Employee on managerID=id; filter rows where salary > manager's salary

SELECT e.name as 'Employee'
From Employee as e
join Employee as m
on e.managerID = m.id
WHERE e.salary>m.salary;
