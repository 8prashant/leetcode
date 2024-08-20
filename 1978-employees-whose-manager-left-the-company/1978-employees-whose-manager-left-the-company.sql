# Write your MySQL query statement below
-- select * from Employees as et1
-- join Employees as et2 on et1.employee_id!=et2.manager_id
select employee_id from Employees
where manager_id not in (
select employee_id from Employees
) and salary<30000
order by employee_id