# Write your MySQL query statement below
select emp.name as Employee
from employee emp
join employee mngr
on emp.managerId=mngr.id  -- jo table join hua usme right table ki jo id hogi usko left table ke managerId ke equal kar do ...
where emp.salary>mngr.salary;
