# Write your MySQL query statement below
select e.name as Employee from Employee as e 
join employee as e1 
on e.managerId=e1.id 
where e.salary>e1.salary;