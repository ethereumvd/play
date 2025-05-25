use MyDatabase;

select
    customer_id as id,
    count(sales) over(partition by customer_id) as no_sales,
    sum(sales) over(partition by customer_id) as tot_sales,
    count(1) over() as tot
from orders;

--use case - data quality check
--maybe to check for duplicates in primary key

select
    customer_id as id,
    count(1) over(partition by customer_id) as k_check,
    count(1) over(partition by order_id) as pk_check
from orders;
--if some entry here is not 1 then in pk duplicates present


select
    order_id,
    customer_id,
    order_date,
    sum(sales) over(partition by customer_id) as sales_cust,
    sum(sales) over() as tot_sales
from orders;

--find percentage of each customers sales over total sales
select
    customer_id as id,
    sales,
    sum(sales) over(partition by customer_id) as sales_cust,
    sum(sales) over() as total_sales,
    cast(sales as float) / sum(sales) over() * 100 as percent
from orders;


--average sales for each customer
--and also overall sales
--coalesce(<col_name>, val) replaces all occurences of null in <col_name> with val

select
    order_id,
    customer_id,
    avg(coalesce(sales)) over(partition by customer_id) as salesavgcust,
    round(avg(sales) over(), 2) as salesavg
from orders;

--find all customers whose average sales is greater than total average

select *
from (
    select
        customer_id ,
        avg(sales) over(partition by customer_id) as avgsalescust,
        avg(sales) over() as avgsalestot
    from orders
) as lol
where avgsalescust > avgsalestot;

--min() and max() functions

select
    customer_id as id,
    sales,
    max(sales) over(partition by id) as maxsalescust,
    min(sales) over(partition by id) as minsalescust,
    max(sales) over() as maxsales,
    min(sales) over() as minsales
from orders;

--show details about orders which have sales equal to maxsales
select *
from (
    select
        *,
        max(sales) over(partition by customer_id) as maxsalescust,
        max(sales) over() as maxsales
        from orders
) as lol
where sales = maxsales;

--deviation from min

select
    * ,
    sales - min(sales) over() as deviationmin,
    max(sales) over() - sales as deviationmax
from orders
order by customer_id;

--running total : total from beginning to current
--rolling total : total between a fixed window
--rows between unbounded preceeding and current row -> for running total
--rows between <val> preceeding and current row -> for rolling total


--find the running total of orders tables by the date

select
    order_id,
    order_date,
    sum(sales) over(order by order_date rows between unbounded preceding and current row) as running,
    sum(sales) over(order by order_date rows between 2 preceding and current row) as rolling,
    avg(sales) over(order by order_date rows between 2 preceding and current row) as rollingavg
from orders;

--you can specify the frame clause like this according to requirements
