source init.sql;

--no join 
select * from persons;
select * from customers;

--inner join default type is inner

select * from orders;
select * from persons;

--good practice to do <table_name>.<column_name> in select

select 
    p.id,
    p.name,
    o.order_id,
    o.sales
from persons as p
inner join orders as o
on p.id = o.customer_id;
--can use aliases like this as well

--left join

select
    p.id,
    p.name,
    p.country,
    o.order_id,
    o.sales
from persons as p 
left join orders as o
on o.customer_id = p.id;
--left is primary table

--unfortunately mariadb and mysql doesnt support full joins -_-

drop table persons;
