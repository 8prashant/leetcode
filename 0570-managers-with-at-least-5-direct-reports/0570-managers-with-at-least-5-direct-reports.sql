select e.name from Employee as e
inner join (select managerId as id from Employee
where managerId is not NULL 
group by managerId
having count(managerId)>=5) as et on e.id=et.id