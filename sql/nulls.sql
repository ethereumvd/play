--nulls vs empty strings vs spaces

use SalesDB;

with orders as (
    select 1 id, 'A' category union 
    select 2 , null union
    select 3, '' union
    select 4, ' ' 
)

select 
    *,
    length(category) cat_len,
    length(trim(category)) as policy1,
    length(nullif(trim(category),'')) as policy2,
    coalesce(nullif(trim(category),''), 'unknown') as policy3
from orders;


