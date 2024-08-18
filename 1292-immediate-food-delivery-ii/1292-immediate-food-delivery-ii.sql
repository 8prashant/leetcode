# Write your MySQL query statement below
select round((count(
    case
        when d.order_date=d.customer_pref_delivery_date 
        then 1
        else null
    end
)/count(*))*100,2) as immediate_percentage  from Delivery as d
join (select d1.customer_id as id,min(d1.order_date) as date from Delivery as d1
group by d1.customer_id)as dt1 on d.customer_id =dt1.id and d.order_date =dt1.date