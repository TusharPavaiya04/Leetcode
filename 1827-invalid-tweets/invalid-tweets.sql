# Write your MySQL query statement below
select tweet_id from Tweets group by content having CHAR_LENGTH(content)>15;