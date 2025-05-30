use MyDatabase;

create or replace view sales_by_cust as (

    select 
        customer_id,
        tot_sales,
        rank() over(order by tot_sales desc) as cust_rank
    from (
        select 
            customer_id,
            sum(sales) as tot_sales
        from orders
        group by customer_id
    ) as s

)
