# Write your MySQL query statement below
select pt1.id as product_id , (
    case
        when new_price is not null
        then new_price 
        else 10
    end
) as price  from (
    select distinct product_id as id from Products
) as pt1 
left join (
    select product_id as id,max(change_date)as date from Products
    where  change_date <='2019-08-16'
    group by id
) as pt2 on pt1.id=pt2.id
left join Products as pt3 on pt3.product_id=pt2.id and pt3.change_date=pt2.date