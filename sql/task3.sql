use SalesDB;

--find customers whose first name contains leading or trailing spaces

select 
    lower(FirstName) as name
from Customers as c 

except

select 
    lower(trim(FirstName))
from Customers as cc;

--alternate way

select 
    FirstName 
from Customers
where FirstName != trim(FirstName);

