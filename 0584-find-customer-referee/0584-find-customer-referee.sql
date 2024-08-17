# Write your MySQL query statement below
select name from Customer
-- where NOT referee_id=2   In SQL, NULL represents an unknown value, and comparisons with NULL do not return TRUE or FALSE; they return NULL (which is treated as FALSE in filtering conditions).
where referee_id Is null or referee_id!=2