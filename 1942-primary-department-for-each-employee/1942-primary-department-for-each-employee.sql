# Write your MySQL query statement below
select et1.employee_id,et1.department_id from Employee as et1
join (
    select * from Employee
    group by employee_id
    having count(primary_flag)=1
) as et2 on et1.employee_id=et2.employee_id
union
select et1.employee_id,et1.department_id from Employee as et1
join (
    select * from Employee
    where primary_flag='Y'
) as et3 on et1.employee_id=et3.employee_id and et1.primary_flag=et3.primary_flag