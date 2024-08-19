-- # Write your MySQL query statement below
-- select num from MyNumbers
-- group by num 
-- having count(num)=1
-- order by num desc limit 1
select max(mt1.num) as num from 
(
    select * from MyNumbers
    group by num
    having count(num)=1
) as mt1