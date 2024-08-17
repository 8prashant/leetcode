SELECT s.student_id,s.student_name,su.subject_name,
(case 
    when et.attended_exams is NULL
    then 0
    else et.attended_exams
    end) as attended_exams
FROM Students as s
cross JOIN Subjects as su
left join (
select student_id as id,subject_name as sn,count(subject_name) as attended_exams from Examinations 
group by id,sn

) as et on s.student_id=et.id and su.subject_name=et.sn
order by s.student_id,su.subject_name
