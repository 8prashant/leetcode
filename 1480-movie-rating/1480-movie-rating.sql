# Write your MySQL query statement below
-- with ut1 as (select MovieRating.user_id,count(MovieRating.rating) as cnt,Users.name from MovieRating
with ut1 as (select Users.name as results from MovieRating
join Users on Users.user_id=MovieRating.user_id
group by MovieRating.user_id
order by count(MovieRating.rating) desc,Users.name asc limit 1
),

-- with mt1 as (select MovieRating.*,avg(MovieRating.rating) as av,Movies.title from MovieRating
 mt1 as (select Movies.title as results from MovieRating
join Movies on Movies.movie_id=MovieRating.movie_id
where date_format(MovieRating.created_at,'%Y-%m')='2020-02'
group by MovieRating.movie_id
order by avg(MovieRating.rating) desc,Movies.title asc limit 1
)

select * from ut1
UNION all
select * from mt1

-- select (Users.name) as results from Users
-- inner join (select user_id as id,count(rating) as cnt from MovieRating
-- group by user_id
-- order by count(rating) desc limit 1
-- ) as ut1 on Users.user_id=ut1.id
-- select (Movies.title) as results from Movies
-- inner join (select movie_id as id,avg(rating) as av from MovieRating
-- group by movie_id
-- order by av desc limit 1
-- ) as mt1 on Movies.movie_id=mt1.id