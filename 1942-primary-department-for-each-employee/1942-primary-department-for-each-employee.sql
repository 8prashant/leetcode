# Write your MySQL query statement below
select et1.employee_id,et1.department_id from Employee as et1
where et1.primary_flag='Y' or et1.employee_id in (
    select employee_id from Employee
    group by employee_id
    having count(primary_flag)=1
)