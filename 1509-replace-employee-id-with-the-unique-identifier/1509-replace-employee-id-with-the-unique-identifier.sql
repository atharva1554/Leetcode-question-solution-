# Write your MySQL query statement below
SELECT  EI.unique_id ,E.name FROM   Employees E LEFT JOIN EmployeeUNI EI ON E.id =EI.id 