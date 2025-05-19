select 
    '3.5129147' ,
    round(3.5129147, 0) as round_0,
    round(3.5129147, 2) as round_2,
    round(3.5129147, 3) as round_3,
    round(3.5129147, 5) as round_5
;

select 
    -10.91286 as num,
    round(-10.91286) as round,
    abs(-10.91286) as _abs,
    round(abs(-10.91286), 3) as roundabs
;
