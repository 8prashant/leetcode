# Write your MySQL query statement below
select p.product_id,round(coalesce(sum(p.price*us.units)/sum(us.units),0),2)as average_price from Prices as p
left join UnitsSold as us on p.product_id=us.product_id and us.purchase_date between p.start_date and p.end_date
group by p.product_id