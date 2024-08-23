# Write your MySQL query statement below
delete pt1 from Person as pt1,Person as pt2
where pt1.email=pt2.email and pt1.id>pt2.id