delimiter $$

create or replace procedure err_example() 
begin

    declare exit handler for sqlexception
    begin
        select 'An Error Occured...' as msg;
    end;

    insert into test_table (id, name) values(1, 'First entry');
    insert into test_table (id, name) values(1, 'Duplicate entry');

end$$

delimiter ;
