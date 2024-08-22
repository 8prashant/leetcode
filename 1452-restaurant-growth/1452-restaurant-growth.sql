# Write your MySQL query statement below
 with newt as (
    select customer_id,name,visited_on,sum(amount) as amount from Customer
    group by visited_on
    ORDER BY visited_on
)
select ct1.visited_on,sum(ct2.amount) as amount,round(sum(ct2.amount)/7,2) as average_amount from newt as ct1
join newt as ct2 on 
ct2.visited_on BETWEEN DATE_SUB(ct1.visited_on, INTERVAL 6 DAY) AND ct1.visited_on
group by ct1.visited_on
having count(ct2.visited_on)>=7
ORDER BY 
    ct1.visited_on;
