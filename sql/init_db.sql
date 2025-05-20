CREATE TABLE mytable (
   `Order Date`       DATETIME NOT NULL,
   `Order ID`         INTEGER NOT NULL PRIMARY KEY,
   `Product`          VARCHAR(26) NOT NULL,
   `Product_ean`      BIGINT UNSIGNED NOT NULL,
   `catégorie`        VARCHAR(12) NOT NULL,
   `Purchase Address` VARCHAR(42) NOT NULL,
   `Quantity Ordered` INTEGER NOT NULL,
   `Price Each`       DECIMAL(6,2) NOT NULL,
   `Cost price`       DECIMAL(18,3) NOT NULL,
   `turnover`         DECIMAL(18,3) NOT NULL,
   `margin`           DECIMAL(18,3) NOT NULL
);
INSERT INTO mytable (`Order Date`,`Order ID`,Product,Product_ean,catégorie,`Purchase Address`,`Quantity Ordered`,`Price Each`,`Cost price`,turnover,margin) 
VALUES ('2019-01-22 21:25:00',141234,'iPhone',5638008983335,'Vêtements','944 Walnut St, Boston, MA 02215',1,700.00,231.000,700.000,469.000);

INSERT INTO mytable (`Order Date`,`Order ID`,Product,Product_ean,catégorie,`Purchase Address`,`Quantity Ordered`,`Price Each`,`Cost price`,turnover,margin) 
VALUES ('2019-01-28 14:15:00',141235,'Lightning Charging Cable',5563319511488,'Alimentation','185 Maple St, Portland, OR 97035',1,14.95,7.475,14.950,7.475);

INSERT INTO mytable (`Order Date`,`Order ID`,Product,Product_ean,catégorie,`Purchase Address`,`Quantity Ordered`,`Price Each`,`Cost price`,turnover,margin) 
VALUES ('2019-01-17 13:33:00',141236,'Wired Headphones',2113973395220,'Vêtements','538 Adams St, San Francisco, CA 94016',2,11.99,5.995,23.980,11.990);

INSERT INTO mytable (`Order Date`,`Order ID`,Product,Product_ean,catégorie,`Purchase Address`,`Quantity Ordered`,`Price Each`,`Cost price`,turnover,margin) 
VALUES ('2019-01-05 20:33:00',141237,'27in FHD Monitor',3069156759167,'Sports','738 10th St, Los Angeles, CA 90001',1,149.99,97.494,149.990,52.496);

INSERT INTO mytable (`Order Date`,`Order ID`,Product,Product_ean,catégorie,`Purchase Address`,`Quantity Ordered`,`Price Each`,`Cost price`,turnover,margin) 
VALUES ('2019-01-25 11:59:00',141238,'Wired Headphones',9692680938163,'Électronique','387 10th St, Austin, TX 73301',1,11.99,5.995,11.990,5.995);

INSERT INTO mytable (`Order Date`,`Order ID`,Product,Product_ean,catégorie,`Purchase Address`,`Quantity Ordered`,`Price Each`,`Cost price`,turnover,margin) 
VALUES ('2019-01-29 20:22:00',141239,'AAA Batteries (4-pack)',2953868554188,'Alimentation','775 Willow St, San Francisco, CA 94016',1,2.99,1.495,2.990,1.495);

INSERT INTO mytable (`Order Date`,`Order ID`,Product,Product_ean,catégorie,`Purchase Address`,`Quantity Ordered`,`Price Each`,`Cost price`,turnover,margin) 
VALUES ('2019-01-26 12:16:00',141240,'27in 4K Gaming Monitor',5173670800988,'Vêtements','979 Park St, Los Angeles, CA 90001',1,389.99,128.697,389.990,261.293);

INSERT INTO mytable (`Order Date`,`Order ID`,Product,Product_ean,catégorie,`Purchase Address`,`Quantity Ordered`,`Price Each`,`Cost price`,turnover,margin) 
VALUES ('2019-01-05 12:04:00',141241,'USB-C Charging Cable',8051736777568,'Vêtements','181 6th St, San Francisco, CA 94016',1,11.95,5.975,11.950,5.975);

INSERT INTO mytable (`Order Date`,`Order ID`,Product,Product_ean,catégorie,`Purchase Address`,`Quantity Ordered`,`Price Each`,`Cost price`,turnover,margin) 
VALUES ('2019-01-01 10:30:00',141242,'Bose SoundSport Headphones',1508418177978,'Électronique','867 Willow St, Los Angeles, CA 90001',1,99.99,49.995,99.990,49.995);

INSERT INTO mytable (`Order Date`,`Order ID`,Product,Product_ean,catégorie,`Purchase Address`,`Quantity Ordered`,`Price Each`,`Cost price`,turnover,margin) 
VALUES ('2019-01-22 21:20:00',141243,'Apple Airpods Headphones',1386344211590,'Électronique','657 Johnson St, San Francisco, CA 94016',1,150.00,97.500,150.000,52.500);
