--find total sales for each customer
with cte_tot_sales as (
    select 
        customer_id as id,
        sum(sales) as tot_sales
    from orders
    group by customer_id
)
, cte_last_date as (
    select
        customer_id as id,
        max(order_date) as last_order
    from orders
    group by customer_id
)
, cte_cust_rank as (
    select 
        id,
        rank() over(order by tot_sales desc) as rankk
    from cte_tot_sales
)
, cte_cust_segment as (
    select 
        id,
        case 
            when tot_sales > 100 then 'High'
            when tot_sales > 50 then 'Medium'
            else 'Low'
        end cust_cat
    from cte_tot_sales
)


select
    c.id,
    c.first_name,
    c.country,
    c.score,
    cts.tot_sales,
    cld.last_order,
    ccr.rankk,
    ccs.cust_cat
from customers as c
left join cte_tot_sales as cts
on cts.id = c.id
left join cte_last_date as cld 
on cld.id = c.id
left join cte_cust_rank as ccr
on ccr.id = c.id
left join cte_cust_segment as ccs 
on ccs.id = c.id;
