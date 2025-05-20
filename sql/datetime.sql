use SalesDB;

select 
    year(ord_datetime) as yr,
    month(ord_date) as mon,
    day(ord_date) as dt,
    week(ord_date) as wk,
    weekday(ord_date) as wk_idx,
    dayname(ord_date) as dayname,
    quarter(ord_date) as quart,
    hour(ord_time) as hr,
    monthname(ord_date) as mn_name
from mytable
order by wk_idx ;

--group orders by year
select 
    year(ord_date) as year,
    count(*) as tot_ord
from mytable
group by year(ord_date);

select 
    name ,
    ord_id,
    dayname(ord_date) as day_name
from mytable
where weekday(ord_date) = 1;
--comparison by integer always better than comparison with strings

--group data by days

select 
    name,
    dayname(ord_date) as day_of_ord,
    count(*) as ord_cnt
from mytable
group by dayname(ord_date);
