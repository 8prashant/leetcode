# Write your MySQL query statement below
select rt3.id,sum(rt3.cnt) as num from (
    select rt1.requester_id as id,count(rt1.requester_id) as cnt from RequestAccepted as rt1
group by rt1.requester_id
union all 
    select accepter_id as id,count(rt2.accepter_id) as cnt from RequestAccepted as rt2
group by rt2.accepter_id
) as rt3
group by rt3.id
order by num desc limit 1