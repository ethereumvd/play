use MyDatabase;

create or replace table monthly_orders as (
    select 
        month(order_date) as ordermonth,
        count(*) as total_orders
    from orders
    group by month(order_date)
)
