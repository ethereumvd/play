--practice of case statement
--find average scores of customers and treat nulls as zeroes
use SalesDB;

select 
    CustomerID as id,
    FirstName as f_n,
    Score,
    avg(
        case 
            when Score is null then 0
            else Score
        end
    ) as avg_clean_score
from Customers;

--in mariadb cannot use case statement aliases inside avg() 
