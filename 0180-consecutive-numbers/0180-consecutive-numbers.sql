select (lt4.num) as ConsecutiveNums  from
(select lt1.id as id1,lt2.id as id2 ,lt2.num as num
from Logs as lt1
join Logs as lt2 on lt1.id-lt2.id=1 and lt1.num=lt2.num ) as lt3
join (select lt1.id as id1,lt2.id as id2 ,lt2.num as num
from Logs as lt1
join Logs as lt2 on lt1.id-lt2.id=1 and lt1.num=lt2.num ) as lt4 on lt3.id1=lt4.id2
group by lt4.num
