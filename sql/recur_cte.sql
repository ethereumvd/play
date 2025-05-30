--task to generate sequence of numbers from 1 to 20

with recursive series as ( 
    select 
        1 as mynum

    union all
    
    select 
        mynum + 1
    from series
    where mynum < 20
)
select * from series;
