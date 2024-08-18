# Write your MySQL query statement below
select s1.user_id,COALESCE((COALESCE(c1.a1,0)/(COALESCE(c1.a1,0)+COALESCE(c2.a2,0))),0) as confirmation_rate from Signups as s1
left join 
    (select user_id as id1 ,count(action) as a1 from Confirmations
where action="confirmed"
group by user_id)  as c1 on s1.user_id=c1.id1
left join 
    (select user_id as id2 ,count(action) as a2 from Confirmations
where action="timeout"
group by user_id)  as c2 on c1.id1=c2.id2