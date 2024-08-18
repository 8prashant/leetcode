# Write your MySQL query statement below
select r.contest_id , round((count(r.user_id)/u.c)*100,2) as percentage from Register as r
cross join (
    select count(user_id) as c from Users
) as u
group by r.contest_id 
order by percentage desc,r.contest_id asc