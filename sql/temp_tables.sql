use MyDatabase;

create or replace temporary table order_tmp (
    select 
        * 
    from orders
)
