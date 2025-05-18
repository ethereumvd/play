source init.sql;

--left anti join
--get all customers who haven't placed any orders
select * 
from persons as p left join orders as o
on p.id = o.customer_id 
where o.customer_id is null;
--this where clause makes effect of left anti join

--get all orders without matching customers
select * 
from orders as o left join persons as p
on o.customer_id = p.id 
where p.id is null;

--cross join (crazy broo)

select * 
from persons cross join orders;

drop table persons;
