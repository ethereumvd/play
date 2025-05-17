use MyDatabase ; 

create table persons (
    id int not null,
    name varchar(50) not null,
    country varchar(10),
    email varchar(20) not null
);

insert into persons 
values (11, 'alice', 'UK', 'alice@gmail.com'),
       (21, 'bob', null , 'bob@gmail.com')
;

insert into persons
select 
    id,
    first_name,
    country,
    'Unknown'
from customers;

select * from persons
where country in ('Germany', 'UK', 'Romania');

select * from persons
where (id between 2 and 12) and country not in ('Germany', 'USA');

select * from persons
where name like '%o%';

select * from persons
where name like '_o%';

select * from persons
where name like '__o%';

drop table persons;
