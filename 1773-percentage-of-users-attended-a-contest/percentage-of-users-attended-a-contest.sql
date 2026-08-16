# Write your MySQL query statement below
select r.contest_id,ROUND(COUNT(r.user_id)*100.0/(select COUNT(*) from Users),2) as percentage from  Register  r group by r.contest_id order by percentage desc, r.contest_id asc;

