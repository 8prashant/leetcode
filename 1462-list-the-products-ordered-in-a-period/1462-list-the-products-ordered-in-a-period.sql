# Write your MySQL query statement below
select pt1.product_name,pt2.sum as unit from products as pt1
join (select product_id as id,sum(unit) as sum from Orders
where date_format(order_date,'%Y-%m')="2020-02"
group by product_id
having sum(unit)>=100) as pt2 on pt1.product_id=pt2.id