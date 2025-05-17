use MyDatabase;

create table persons (
    id int not null ,
    name varchar(50) not null,
    birth_date date ,
    email varchar(20) not null ,
    constraint pk_persons primary key (id)  
) ;

show tables;

alter table orders 
add email varchar(50) not null;

select * from orders;

alter table orders
drop email;

select * from orders;

drop table persons;

show tables;
