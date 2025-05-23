--window functions used to get more details about rows
--more info than group by
use MyDatabase;

--find total sales for each customer
select 
    customer_id as id,
    sum(sales) as tot
from orders
group by customer_id;

--additionally give the order id and date for each product
--now group by wont be enough

select 
    customer_id as id,
    order_id as ord_id,
    sum(sales) over() as tot_sales,
    sum(sales) over(partition by customer_id) as tot_pdct_sales
from orders
order by customer_id, order_id;


--rank each customers orders by their highest to lowest

select  
    customer_id as id,
    order_id as ord_id,
    order_date as ord_dt,
    rank() over(partition by customer_id order by sales desc) as rank_sales
from orders;
--for rank() function have to give a ordering
--infact for all rank and value window functions have to give order by

--frame clause is kinda hard
--is pretty cool tho
--dayummmmm!
select  
    customer_id as c_id,
    order_id as ord_id,
    order_date as ord_dt,
    sales,
    sum(sales) over(partition by customer_id order by sales rows between unbounded preceding and current row) as lol,
    sum(sales) over(partition by customer_id order by sales rows between 1 preceding and current row) as lol1,
    sum(sales) over(partition by customer_id order by sales rows between unbounded preceding and unbounded following) as lol2,
    sum(sales) over(partition by customer_id order by sales) as lol3
from orders;

--hidden or default frame is used if order by is used
--differences have been shown below for
--1 no order by
--2 order by with frame specified
--3 order by withour frame specified
--2 and 3 gives identical results

select  
    customer_id as c_id,
    order_id as ord_id,
    order_date as ord_dt,
    sales,
    sum(sales) over(partition by customer_id) as tot,
    sum(sales) over(partition by customer_id order by sales rows between unbounded preceding and current row) as lol,
    sum(sales) over(partition by customer_id order by sales) as lol1
from orders
where customer_id in (1, 3)
order by tot;

--rules for window functions :- 
--win func only allowed to use with select and order by
--win func cannot be nested inside another window function
--win func executed after filtering data from where clause
--win func can be used along with group by if they use the same columns

--rank customers based on their total sales
select 
    customer_id as c_id, 
    sum(sales) as tot_sales,
    rank() over(order by tot_sales desc) as rank_cust
from orders
group by customer_id;

--partition by not used because already data has been grouped
--now if we do partition by it will show rank 1 for all
--as it will take one customer id with its tot sales to be one window
