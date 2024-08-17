-- select student_id,subject_name,count(subject_name) from Examinations
-- group by student_id,subject_name
-- order by student_id asc

-- select Students.student_id,Students.student_name,Subjects.subject_name,count(Examinations.subject_name) from Students
-- cross join Subjects
-- left join Examinations on Students.student_id=Examinations.student_id and Subjects.subject_name=Examinations.subject_name
-- group by Examinations.student_id,Examinations.subject_name;


SELECT s.student_id,s.student_name,su.subject_name,COALESCE(et.attended_exams, 0) as attended_exams
FROM Students as s
cross JOIN Subjects as su
left join (
select student_id as id,subject_name as sn,count(subject_name) as attended_exams from Examinations 
group by id,sn

) as et on s.student_id=et.id and su.subject_name=et.sn
order by s.student_id,su.subject_name
