source init.sql;

--get all customers along with orders
--but only for customers who have placed an order

select * 
from persons as p left join orders as o
on p.id = o.customer_id
where o.customer_id is not null;

--kind of a advanced inner join

drop table persons;
