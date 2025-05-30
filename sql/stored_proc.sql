--write a query to find total number of us customers and their avg score
--but now change it to get for any country

delimiter $$

create or replace procedure get_country_cust(p_country varchar(20))
begin 

    declare tot_cust int default 0;
    declare avg_score int default 0;

    declare exit handler for sqlexception
    begin
        select 'An Error Occurred...' as msg;
    end;

    if p_country is null or p_country = '' then
        set p_country = 'USA';
    end if;

    select 'Starting Procedure...' as msg;

    if exists (select 1 from customers where score is null and country = p_country) then
        select 'Updating nulls...' as msg;
        update customers
        set score = 0
        where score is null and country = p_country;
    else 
        select 'No null scores found...' as msg;
    end if;

    select concat('Country queried is : ', p_country) as msg;

    select count(*), avg(score)
    into tot_cust, avg_score
    from customers
    where country = p_country;

    select tot_cust as total_customers, avg_score as average_score;

    select 
        count(order_id) as total_orders,
        sum(sales) as total_sales
    from customers as c 
    left join orders as o
    on o.customer_id = c.id
    where c.country = p_country;

    select 'Finished Procedure...' as msg;

end$$

delimiter ;
