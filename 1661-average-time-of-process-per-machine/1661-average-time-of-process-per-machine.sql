# Write your MySQL query statement below
select machine_id,round(avg(processing_time),3) as processing_time  from
(
    select a1.machine_id as machine_id ,(a1.timestamp-a2.timestamp) as processing_time from Activity as a1
    join Activity as a2 on a1.machine_id=a2.machine_id and a1.process_id=a2.process_id and a1.activity_type="end" and a2.activity_type="start"
) as t1
group by machine_id