select distinct lt3.num as ConsecutiveNums  from Logs as lt1
join Logs as lt2 on lt1.id-lt2.id=1 and lt1.num=lt2.num
join Logs as lt3 on lt3.id-lt1.id=1 and lt3.num=lt1.num