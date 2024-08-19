# Write your MySQL query statement below
select ct1.customer_id from Customer as ct1
-- cross join (select count(product_key) as cn from Product) as ct2
group by ct1.customer_id
having count(ct1.product_key)=(select count(product_key) from Product)

-- WE CANNOT USE SUBQUERY VALUE DIRECTLY IN HAVING THATSWHY WE HAVE TO INCLUDE THE QUERY ITSELF IN HAVING 