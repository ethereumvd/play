use SalesDB; -- select shows in the exact order you give it

select 
    Firstname,
    CustomerID,
    Score
from Customers ;

-- where filters data based on condition

select 
    Firstname,
    CustomerID,
    Score,
    Country
from Customers 
where Score >= 500 ;
-- where Country = "Germany";
-- where Firstname != "Anna"

-- order by sorts data by ascending or descending 

select 
    Firstname,
    CustomerID,
    Score,
    Country
from Customers 
where Score != 0
order by FirstName desc;

-- nested order by

select 
    FirstName ,
    Country ,
    Score
from Customers
where Score != 0
order by 
    Country asc,
    Score desc ;


--group by mushes two rows

select 
    Country as country,
    sum(Score) as total_score -- alias
from Customers
group by country
order by 
   Score desc;

select 
    Country as country,
    FirstName as first_name,
    sum(Score) as total_score -- alias
from Customers
group by country , first_name
order by total_score desc;
--sql now grouping data by two columns
--if both columns contain same row entry then only it will merge

--find total customers and score of each country

--count function returns the number of rows we are merging

select 
    Country ,
    sum(Score) as total_score ,
    count(Country) as total_customers--you are aggregating it
from Customers
group by Country
order by 
    total_score desc ,
    total_customers desc;
    



