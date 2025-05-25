select 
    * 
from customers as c
left join (
    select 
        customer_id, 
        count(*) as tot_ord
    from orders 
    group by customer_id
) as o
on o.customer_id = c.id;
--above is non correlated subquery


--very very important 
--correlated subquery
--retreive customer details and number of orders made by them

select 
    * ,
    (select count(*) from orders as o where o.customer_id = c.id) as tot_ord
from customers as c;
--this subquery going to be executed for each row


--another example 
--retreive order details for orders made by people in germany

select 
    *
from orders as o
where exists (
    select 1 
    from customers as c
    where country = 'Germany' and c.id = o.customer_id
);
