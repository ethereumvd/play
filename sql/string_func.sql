--manipulation, calculation, string extraction

use SalesDB;

select 
    upper(concat(FirstName,' ', LastName)) as name,
    lower(country) as ctry
from Customers;

select 
    lower(concat(FirstName,' ', LastName)) as name,
    upper(country) as ctry
from Customers;

select 
    trim(lower(concat(FirstName,' ', LastName))) as name,
    upper(country) as ctry
from Customers;

--replace replaces all occurences of provided char

select 
    'report.txt' as filename,
    replace('report.txt', '.txt', '.csv') as new_filename;

select 
    BirthDate ,
    replace(Birthdate, '-', '/') as new_birthdate
from Employees;

select 
    trim(lower(concat(FirstName,' ', LastName))) as name,
    lower(Country) as ctry,
    length(trim(lower(concat(FirstName,' ', LastName)))) as name_len,
    length(lower(Country)) as country_len
from Customers;

--left(string, val) and right(string, val) operators

select 
    trim(lower(concat(FirstName,' ', LastName))) as name,
    lower(Country) as ctry,
    length(trim(lower(concat(FirstName,' ', LastName)))) as name_len,
    length(lower(Country)) as country_len,
    left(trim(lower(concat(FirstName,' ', LastName))), 5) as left_name,
    right(trim(lower(concat(FirstName,' ', LastName))), 8) as right_name
from Customers;

--substring(string, st_pos, length) end_pos = st_pos+length

select 
    trim(lower(concat(FirstName,' ', LastName))) as name,
    lower(Country) as ctry,
    length(trim(lower(concat(FirstName,' ', LastName)))) as name_len,
    left(trim(lower(concat(FirstName,' ', LastName))), 5) as left_name,
    right(trim(lower(concat(FirstName,' ', LastName))), 8) as right_name,
    substring(trim(lower(concat(FirstName,' ', LastName))), 5, 5) as sub_name,
    substring(trim(lower(concat(FirstName,' ', LastName))), 2, length(trim(lower(concat(FirstName,' ', LastName))))) as trick_name
from Customers;

--dynamic length for substring() using len function
