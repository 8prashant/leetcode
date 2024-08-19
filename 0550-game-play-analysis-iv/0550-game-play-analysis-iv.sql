select round(count(*)/at3.co,2) as fraction from Activity as at1
join (select player_id as id,min(event_date) as date from Activity
group by player_id ) as at2 on at1.event_date-at2.date=1 and at2.id=at1.player_id
cross join (select count(distinct player_id) as co from Activity) as at3