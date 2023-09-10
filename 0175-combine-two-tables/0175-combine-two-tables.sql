# Write your MySQL query statement below
select firstname,lastname,CITY,STATE from Person left join Address ON Person.personId = Address.personId;