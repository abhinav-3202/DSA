# Write your MySQL query statement below
select a1.machine_id , round(avg(a2.timestamp-a1.timestamp),3) as processing_time
from activity a1 
join 
activity a2 
on a1.machine_id=a2.machine_id 
and a1.process_id=a2.process_id
and a1.activity_type='start'
and a2.activity_type='end'
group by machine_id;

-- means the join is made such that we take from a1 table just the activity start and from a2 table we just take the activity end , and then a1.timestamp will directly point to start time of a1 , a2.timestamp will point to the end time of with same process_id