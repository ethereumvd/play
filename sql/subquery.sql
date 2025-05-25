--scalar query : only returns a single value
--row query : returns multiple rows from single column
--table query : returns multiple rows and columns

use MyDatabase;

--find all orders that have sales higher than average sales

select 
    order_id, 
    sales
from (
    select 
        order_id,
        sales,
        avg(sales) over() as avgsales
    from orders
)as t
where sales > avgsales;

--rank customers based on their total sales

--example of from subquery
select 
    customer_id,
    total_sales,
    rank() over(order by total_sales desc) as ranking
from(
    select 
        customer_id,
        sum(sales) as total_sales
    from orders
    group by customer_id
) as lol;

--show order id, order date and number of total orders
--could be done using window functions
--but use subquery

select 
    order_id as id, 
    order_date,
    (select count(*) from orders) as tot_orders
from orders;
--subquery inside select clause can only return scalar vaule(single value)

--alternative using window function
-- select 
--     order_id, 
--     order_date,
--     count(*) over() as tot_sales
-- from orders;

--show all customer details and find the total orders of each customer
--using join

select 
    c.*
from customers as c
left join (
    select 
        customer_id as id,
        count(*) as tot_ord
    from orders
    group by customer_id
) as o
on c.id = o.id;

--now with where clause 
--here also only scalar subqueries allowed

select 
    * ,
    (select avg(sales) from orders) as avgsales
from orders
where sales > (select avg(sales) from orders);


--another example for where subquery
--retrieve all info about orders made by people from not germany
select *
from orders
where customer_id not in (
    select 
        id
    from customers
    where country = 'Germany'
);


--now with any and all operators
--example (although no data for this)
--show all female employees who have salary greater than any one male employee

-- select 
--     id,
--     first_name,
--     salary
-- from employees
-- where gender = 'F'
-- and salary > any (select salary from employees where gender = 'M');

--similiarly for all operator
--show all female employees whose salary is higher than all male employees

-- select 
--     id, 
--     first_name,
--     salary
-- from employees 
-- where gender = 'F'
-- and salary > all (select salary from employees where gender = 'M');


--very very important 
--correlated subquery
--retreive customer details and number of orders made by them

select 
    * ,
    (select count(*) from orders as o where o.customer_id = c.id) as tot_ord
from customers as c;
--this subquery going to be executed for each row
