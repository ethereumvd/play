--show employee heirarchy by displaying employees level within organization
--use recursive cte

use MyDatabase;

with recursive cte_employee_heirarchy as (
    select 
        id,
        name, 
        manager_id,
        1 as levell
    from employees 
    where manager_id is null

    union all 

    select 
        e.id, 
        e.name,
        e.manager_id,
        ceh.levell + 1 as levell
    from employees as e
    inner join cte_employee_heirarchy as ceh
    on e.manager_id = ceh.id
 
)

select * from cte_employee_heirarchy;
