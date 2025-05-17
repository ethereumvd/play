-- task :
-- find avg of score for each country 
-- considering only customers with score not 0
-- return only those countries with avg score greater then 500

use SalesDB;

select 
    Country as country,
    avg(Score) as average_score
from Customers

where 
    Score != 0
group by 
    country
having 
    average_score > 500
order by
    average_score desc;

limit 2 ;
