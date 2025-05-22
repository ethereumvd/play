use MyDatabase;

--total number of orders
select 
    customer_id, 
    count(*) as tot_orders,
    sum(sales) as tot_sales,
    avg(sales) as avg_sales,
    max(sales) as mx_sales,
    min(sales) as mn_sales,
    sum(
        case 
            when sales > 30 then 1
            else 0
        end
    ) as ord_ab_30
from orders
group by customer_id;
