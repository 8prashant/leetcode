# Write your MySQL query statement below
select st1.id,(
    case
        when st1.id=(select max(id) from Seat) and st1.id%2!=0
        then st1.student 
        when st1.id%2=0
        then st3.student
        else st2.student
    end
) as student from Seat as st1
left join Seat as st2 on st1.id+1=st2.id
left join Seat as st3 on st1.id-1=st3.id