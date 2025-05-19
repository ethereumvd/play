use SalesDB;
--first query controls name of column
select 
    FirstName as f,
    CustomerID as id,
    Score as sc
from Customers

union

select 
    FirstName,
    LastName,
    BirthDate
from Employees;

--wow !! data types in mysql dont need to be compatible to use union
--just number of cols should be same

--union only selects unique rows

select  
    'cust' as src,
    FirstName,
    LastName
from Customers

union all

select 
    'emp' as src,
    FirstName,
    LastName
from Employees;

--does not filter out duplicates , hence faster

select 
    FirstName,
    LastName
from Customers

except

select 
    FirstName,
    LastName
from Employees;

--all records from first that are not in second

select 
    FirstName,
    LastName
from Customers

intersect

select 
    FirstName,
    LastName
from Employees;

--only records that match both are returned
