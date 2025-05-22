--use orders table from MyDatabase 
--count how many times a customer has made an order of greater than 35

use MyDatabase;

select 
    customer_id,
    case 
        when sales > 35 then 1
        else 0
    end flag
from orders;

select 
    customer_id as id,
    count(*) as tot_orders,
    sum(
        case 
            when sales > 35 then 1
            else 0
        end
    ) as orders_above_35
from orders
group by customer_id;
