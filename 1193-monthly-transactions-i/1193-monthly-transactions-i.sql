select tt1.month,tt1.country,(coalesce(tt1.ca,0)+coalesce(tt2.cd,0))as trans_count,coalesce(tt1.ca,0) as approved_count,(coalesce(tt1.approved_total_amount,0)+coalesce(tt2.declined_total_amount,0)) as trans_total_amount,coalesce(tt1.approved_total_amount,0) as approved_total_amount from (
    select date_format(t1.trans_date, '%Y-%m') as month ,t1.country,count(t1.state) as ca,sum(t1.amount) as approved_total_amount from Transactions as t1
where t1.state="approved"
group by month,t1.country) as tt1

left join (
    select date_format(t2.trans_date, '%Y-%m') as month ,t2.country,count(t2.state) as cd,sum(t2.amount) as declined_total_amount from Transactions as t2
    where t2.state="declined"
    group by month,t2.country
) as tt2 on tt1.month=tt2.month and tt1.country=tt2.country
union
select tt2.month,tt2.country,(coalesce(tt1.ca,0)+coalesce(tt2.cd,0))as trans_count,coalesce(tt1.ca,0) as approved_count,(coalesce(tt1.approved_total_amount,0)+coalesce(tt2.declined_total_amount,0)) as trans_total_amount,coalesce(tt1.approved_total_amount,0) as approved_total_amount from (
    select date_format(t1.trans_date, '%Y-%m') as month ,t1.country,count(t1.state) as ca,sum(t1.amount) as approved_total_amount from Transactions as t1
where t1.state="approved"
group by month,t1.country) as tt1

right join (
    select date_format(t2.trans_date, '%Y-%m') as month ,t2.country,count(t2.state) as cd,sum(t2.amount) as declined_total_amount from Transactions as t2
    where t2.state="declined"
    group by month,t2.country
) as tt2 on tt1.month=tt2.month and tt1.country=tt2.country
