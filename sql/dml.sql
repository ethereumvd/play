use MyDatabase;

create table persons (
    id int not null,
    name varchar(50) not null,
    country varchar(10) ,
    email varchar(20) not null ,
    constraint pk_persons primary key (id)
);

--manual entry

insert into persons (id, name, country, email) 
values 
    (11, 'alice', 'usa' ,'alice@gmail.com') ,
    (21, 'bob', null, 'bob@gmail.com')
;

--now insert from customers table instead of manual
insert into persons (id, name, country, email)
select 
    id ,
    first_name ,
    country,
    'Unknown'
from customers ;
--if here primary key conflicts then wont insert
select * from persons;

update persons
    set email = 'martin@gmail.com'
where id = 4;
--very careful to add the where clause o/w will update entire column    

update persons
    set name = 'blake' ,
        country = 'UK' ,
        email = 'bl@gmail.com'
where id = 4;

select * from persons;

delete from persons 
where id < 4;
--again very imp to add where clause
select * from persons;

truncate table persons;
--empties the entire table (does not delete it)

select * from persons;
drop table persons;
