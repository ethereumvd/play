create table if not exists customerlogs(
    logid int auto_increment primary key,
    customerid int,
    logmessage varchar(255),
    logdate datetime default current_timestamp
);

delimiter $$

create or replace trigger trg_customer
after insert on customers
for each row
begin
    insert into customerlogs (customerid, logmessage, logdate)
    values (
        NEW.id,
        concat('New Customer added :', NEW.id),
        now()
    );
end$$

delimiter ;
