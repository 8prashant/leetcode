# Write your MySQL query statement below
select q.query_name,round(sum(q.rating/q.position)/count(q.rating),2) as quality,coalesce(round((qt1.r/count(q.rating))*100,2),0) as poor_query_percentage from Queries as q
left join (
    select query_name as qn,count(rating) as r from Queries
    where rating<3
    group by query_name
) as qt1 on q.query_name=qt1.qn
where q.query_name is not null
group by q.query_name