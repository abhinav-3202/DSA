# Write your MySQL query statement below
SELECT 
    (SELECT DISTINCT SALARY FROM EMPLOYEE E WHERE 
        2=(SELECT COUNT(DISTINCT SALARY) FROM EMPLOYEE E2 
            WHERE E.SALARY<=E2.SALARY
        )
    )
             AS SecondHighestSalary;