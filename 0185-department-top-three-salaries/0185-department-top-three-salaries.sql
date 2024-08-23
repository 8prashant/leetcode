with et3 as (
    select *,sum(et2.salary2) as sum from Employee as et1 
join(select distinct salary as salary2,departmentId as d_id from Employee) 
as et2 on et1.departmentId=et2.d_id and et1.salary<=et2.salary2 
group by et1.id 
having count(et2.salary2)<=3 
order by et1.departmentId, sum(et2.salary2) desc 
)

select distinct (Department.name)as Department,(et4.name) as Employee,et4.Salary from Employee as et4 
join (
    select et6.departmentId as id,et6.salary from et3 as et6 join (
    select departmentId,max(sum) as sum from et3
    group by departmentId ) as et7 on et6.departmentId=et7.departmentId and et6.sum=et7.sum
) as et5 on et4.departmentId=et5.id and et4.salary>=et5.salary
join Department on et5.id=Department.id
order by et4.departmentId