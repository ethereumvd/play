use SalesDB;

select 
    price_category,
    sum(Price) as tot_price
from(
    select 
        ProductID as id,
        Product as pdct,
        Price as price,
        case 
            when Price > 25 then 'high'
            when Price >= 15 then 'medium'
            else 'low'
        end price_category
    from Products
) as some_name
group by price_category;


select 
    CustomerID as id,
    trim(FirstName) as f_n,
    case 
        when Country = 'Germany' then 'DE'
        when Country = 'USA' then 'US'
        when Country = 'England' then 'UK'
        else 'N/A'
    end abbr_ctry
from Customers;

--another way to use case to avoid redundancy is case <col_name>
--where <col_name> is the column name to be evaluated
--but only for one column and for equal to condition (like no >= types condition)
select  
    CustomerID as id,
    trim(FirstName) as f_n,
    case Country
        when 'Germany'  then 'DE'
        when 'USA'      then 'US'
        when 'England'  then 'UK'
        else 'N/A'
    end abbr_ctry
from Customers;
