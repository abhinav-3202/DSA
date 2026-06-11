# Write your MySQL query statement below
select distinct class from courses c1 where 
5<= (select count(student) from courses c2 where c1.class=c2.class);