# Write your MySQL query statement below

SELECT s.machine_id, ROUND(AVG(e.timestamp-s.timestamp),3) AS processing_time
FROM Activity s
JOIN Activity e
ON e.machine_id=s.machine_id 
AND e.process_id=s.process_id
AND s.activity_type='start'
AND e.activity_type='end'
GROUP BY s.machine_id;


