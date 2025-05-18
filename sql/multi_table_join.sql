--for each order display :
--order id , customers name , product name , sales ,prices, sales person name

--a good entity relationship diagram must be present in the database 

select 
    o.OrderID,
    o.Sales,
    c.FirstName,
    c.LastName,
    p.Product as ProductName
    e.FirstName,
    e.LastName
from Sales.Orders as o
left join Sales.Customers as c
on o.CustomerID = c.CustomerID
left join Sales.Products as p
on o.ProductId = p.ProductID
left join Sales.Employees as e
on o.SalesPersonID = e.EmployeeID


