# Write your MySQL query statement below
select qt1.person_name from Queue as qt1
cross join Queue as qt2 on qt1.turn>=qt2.turn
group by qt1.turn
having sum(qt2.weight)<=1000
order by qt1.turn desc limit 1