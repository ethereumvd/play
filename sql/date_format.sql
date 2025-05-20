use SalesDB;

select 
    date_format(ord_date,'%w/%m/%y') as fmt_1,
    date_format(ord_date,'%W %m %y') as fmt_2,
    date_format(ord_date,'%W, %M %Y') as fmt_3,
    date_format(ord_date,'%w, %M') as fmt_4,
    date_format(ord_date, '%D %W %M %Y , %H:%i:%s') as fmt_5
from mytable;

select  
    ord_date ,
    ord_datetime
from mytable;

select 
    date_add(ord_date, interval 1 day) as n_dt,
    date_add(ord_date, interval '-11 +1' year_month) as n_dt2,
    datediff(date_add(ord_date, interval '-11 +1' year_month), ord_date) as diff,
    datediff(ord_date,date_add(ord_date, interval '-11 +3' year_month)) as diff2,
    datediff(ord_date, date_add(ord_date, interval -1 day)) as diff3
from mytable;
