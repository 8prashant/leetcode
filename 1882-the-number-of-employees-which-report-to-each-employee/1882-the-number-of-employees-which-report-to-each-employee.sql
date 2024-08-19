select et1.employee_id,et1.name,et2.cnt as reports_count,et2.age as average_age from Employees as et1
join (select reports_to as id,count(reports_to) as cnt,round(avg(age),0) as age from Employees 
where reports_to is not null
group by reports_to) as et2 on et1.employee_id = et2.id
order by et1.employee_id