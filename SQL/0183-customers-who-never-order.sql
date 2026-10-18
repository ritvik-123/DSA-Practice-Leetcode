-- 183. Customers Who Never Order (Easy)
-- https://leetcode.com/problems/customers-who-never-order/
-- Approach: LEFT JOIN Customers to Orders, WHERE Orders.id IS NULL finds no-match rows

SELECT c.name as Customers
FROM Customers AS c
LEFT JOIN Orders AS o
    ON c.id = o.customerId
WHERE o.id IS NULL;
