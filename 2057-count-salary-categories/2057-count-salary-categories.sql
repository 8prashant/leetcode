-- # Write your MySQL query statement below
with Categories as (
    select "Low Salary" as category
    union 
    select "High Salary" as category
    union 
    select "Average Salary" as category
)
select ct1.category,count(at1.category) as accounts_count from Categories as ct1
left join ( 
select (
    case
        when income<20000
        then "Low Salary"
        when income>=20000 and income<=50000
        then "Average Salary"
        else "High Salary"
    end
) as category from Accounts
) as at1 on ct1.category=at1.category
group by ct1.category