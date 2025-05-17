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
    count(Country) as total_customers
from Customers
group by Country
order by 
    total_score desc ,
    total_customers desc;

select 
    Country,
    sum(Score) as total_score
from Customers
where Score >= 500
group by Country
having total_score >= 350
order by 
    total_score desc;
-- having is used after group by
-- where clause is used after from clause to filters 
-- where clause used b/w from ans group by    

--where used before aggregating
--having used after aggregating

--distinct clause example :-

select distinct 
    Country
from Customers;

-- do not use distinct unless necessary 
--slows down the query

-- top clause example :-

select 
    Country,
    FirstName,
    Score
from Customers
where Score >= 350
order by Score asc
limit 3 ;
-- this query will show first 3 rows in asc order
-- in mysql and mariadb it is limit and in mssql it is top
-- limit should be at the very bottom of the query


-- the execution order of sql statements is : -

-- from (retreives table)
-- where (filters rows)
-- group by (aggregates)
-- having (filters rows again after aggregation)
-- order by (sorts rows)
-- select distinct (finally select which cols to display)
-- limit # / top # (first # number of rows)
