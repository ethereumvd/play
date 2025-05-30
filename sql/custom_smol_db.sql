use MyDatabase;

create table employees (
    id int not null,
    name varchar(50) not null,
    manager_id int ,
    constraint pk_employees primary key (id)
);

insert into employees
select 
    id,
    first_name, 
    manager_id
from customers;

select * from employees;
