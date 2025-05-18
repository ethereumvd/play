use MyDatabase;

create table persons (
    id int not null,
    name varchar(50) not null,
    country varchar(20),
    email varchar(20) not null
);

insert into persons
values (11, 'Alice', 'Spain', 'alice@gmail.com'),
       (6, 'bob', null, 'bob@gmail.com')
;

insert into persons
select
    id,
    first_name,
    country,
    'Unknown'
from customers;

update persons
    set email = 'mull@gmail.com'
where id = 4;
