-- 175. Combine Two Tables (Easy)
-- https://leetcode.com/problems/combine-two-tables/
-- Approach: LEFT JOIN Person to Address on personID to include persons with no address

SELECT
    p.firstName,
    p.lastName,
    a.city,
    a.state
FROM Person p
LEFT JOIN Address a
    ON p.personID = a.personID;
