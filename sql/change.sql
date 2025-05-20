ALTER TABLE mytable
ADD COLUMN Order_Date DATE,
ADD COLUMN Order_Time TIME,
ADD COLUMN Order_Timestamp DATETIME;
UPDATE mytable
SET 
  Order_Date = DATE(`Order Date`),
  Order_Time = TIME(`Order Date`),
  Order_Timestamp = `Order Date`;
ALTER TABLE mytable
DROP COLUMN `Order Date`;
