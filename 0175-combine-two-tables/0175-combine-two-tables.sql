# Write your MySQL query statement below
# select firstName,lastName,city,state from person left join address using(personid)
SELECT Person.firstName, Person.lastname, Address.city, Address.state FROM Person
LEFT JOIN Address ON Person.personId = Address.personId;