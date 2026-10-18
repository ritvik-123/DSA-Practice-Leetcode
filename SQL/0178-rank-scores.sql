-- 178. Rank Scores (Medium)
-- https://leetcode.com/problems/rank-scores/
-- Approach: DENSE_RANK() window function ordered by score desc, no gaps on tied scores

SELECT score,
DENSE_RANK() OVER (ORDER BY score DESC) AS 'rank'
FROM Scores
ORDER BY score DESC;
