### The commercial bank wants keep track of the customer’s account information. 
### Each customer may have any number of accounts and account can be shared by any number of customers. 
### The system will keep track of the date of last transaction. We store the following details. 
### Account: unique account-number, type and balance 
### Customer: unique customer-id, name and several addresses composed of street, city and state
### a) Establish the database by normalizing up to 3NF and considering all schema level constraints 
### b) Write SQL insertion query to insert few tuples to all the relations 
### c) Add 5% interest to the customer who have less than 10000 balances and 6% interest to remaining customers.
### d) List joint accounts involving more than three customers 
### e) Write a insertion trigger to allow only current date for date of last transaction field. 
### f) Write a procedure to find the customer who has highest number of accounts, the customer who has lowest balance, 
###    the customer who involved in most of joint accounts.

create database banking;
use banking;

CREATE TABLE Bank (
 BankID VARCHAR(10) NOT NULL PRIMARY KEY,
 Name VARCHAR(50) NOT NULL,
 Street VARCHAR(50) NOT NULL,
 City VARCHAR(50) NOT NULL,
 State VARCHAR(2) NOT NULL,
 CONSTRAINT UC_Bank_Name UNIQUE (Name)
);
CREATE TABLE Branch (
 BranchID VARCHAR(10) NOT NULL PRIMARY KEY,
 Name VARCHAR(50) NOT NULL,
 Street VARCHAR(50) NOT NULL,
 City VARCHAR(50) NOT NULL,
 State VARCHAR(2) NOT NULL,
 BankID VARCHAR(10) NOT NULL,
 CONSTRAINT FK_Branch_Bank FOREIGN KEY (BankID)
 REFERENCES Bank (BankID),
 CONSTRAINT UC_Branch_Name UNIQUE (Name)
);
CREATE TABLE Customer (
 CustomerID VARCHAR(10) NOT NULL PRIMARY KEY,
 Name VARCHAR(50) NOT NULL,
 Street VARCHAR(50) NOT NULL,
 City VARCHAR(50) NOT NULL,
 State VARCHAR(2) NOT NULL,
 CONSTRAINT UC_Customer_Name UNIQUE (Name)
);
CREATE TABLE Account (
 AccountID INT NOT NULL PRIMARY KEY,
 AcctNo VARCHAR(20) NOT NULL,
 Type VARCHAR(20) NOT NULL,
 Balance DECIMAL(10 , 2 ) NOT NULL,
 LastTransactionDate DATE NOT NULL,
 CustomerID VARCHAR(10) NOT NULL,
 BranchID VARCHAR(10) NOT NULL,
 CONSTRAINT FK_Account_Customer FOREIGN KEY (CustomerID)
 REFERENCES Customer (CustomerID),
 CONSTRAINT FK_Account_Branch FOREIGN KEY (BranchID)
 REFERENCES Branch (BranchID)
);
-- Insert sample values into the Bank table
INSERT INTO Bank (BankID, Name, Street, City, State) VALUES
 ('B001', 'Bank of America', '123 Main St', 'New York', 'NY'),
 ('B002', 'Chase Bank', '456 5th Ave', 'Los Angeles', 'CA'),
 ('B003', 'Wells Fargo', '789 Broadway', 'Chicago', 'IL'),
 ('B004', 'Citibank', '321 Oak St', 'Houston', 'TX'),
 ('B005', 'HSBC', '555 Pine St', 'San Francisco', 'CA');
-- Insert sample values into the Branch table
INSERT INTO Branch (BranchID, Name, Street, City, State, BankID) VALUES
 ('BR001', 'Bank of America NYC', '123 Main St', 'New York', 'NY', 'B001'),
 ('BR002', 'Chase Bank LA', '456 5th Ave', 'Los Angeles', 'CA', 'B002'),
 ('BR003', 'Wells Fargo Chicago', '789 Broadway', 'Chicago', 'IL', 'B003'),
 ('BR004', 'Citibank Houston', '321 Oak St', 'Houston', 'TX', 'B004'),
 ('BR005', 'HSBC San Francisco', '555 Pine St', 'San Francisco', 'CA', 'B005');
 
 -- Insert sample values into the Customer table
INSERT INTO Customer (CustomerID, Name, Street, City, State) VALUES
 ('C001', 'John Smith', '111 Park Ave', 'New York', 'NY'),
 ('C002', 'Jane Doe', '222 Maple St', 'Los Angeles', 'CA'),
 ('C003', 'Bob Johnson', '333 Elm St', 'Chicago', 'IL'),
 ('C004', 'Alice Brown', '444 Pine St', 'Houston', 'TX'),
 ('C005', 'David Lee', '555 Oak St', 'San Francisco', 'CA');
-- Insert sample values into the Account table
INSERT INTO Account (AccountID, AcctNo, Type, Balance, LastTransactionDate, CustomerID, BranchID) VALUES
 (1, 'A10001', 'Savings', 5000.00, '2022-01-01', 'C001', 'BR001'),
 (2, 'A10002', 'Checking', 2000.00, '2022-02-15', 'C002', 'BR002'),
 (3, 'A10003', 'Savings', 10000.00, '2022-03-23', 'C003', 'BR003'),
 (4, 'A10004', 'Checking', 7500.00, '2022-04-30', 'C004', 'BR004'),
 (5, 'A10005', 'Savings', 15000.00, '2022-05-15', 'C005', 'BR005');
 INSERT INTO Account (AccountID, AcctNo, Type, Balance, LastTransactionDate, CustomerID, BranchID) VALUES
(6, 'A10008', 'joint', 7500.00, '2022-04-30', 'C001', 'BR004'),
(7, 'A10008', 'joint', 7500.00, '2022-04-30', 'C002', 'BR004'),
(8, 'A10008', 'joint', 7500.00, '2022-04-30', 'C003', 'BR004');
 
SET SQL_SAFE_UPDATES = 0;
UPDATE Account 
SET 
 Balance = Balance * (CASE
 WHEN Balance < 10000 THEN 1.05
 ELSE 1.06
 END);
SELECT *FROM Account;
SELECT 
 Account.AcctNo, COUNT(*) AS NumCustomers
FROM
 Account
WHERE
 Account.Type = 'Joint'
GROUP BY Account.AcctNo
HAVING COUNT(*) > 2;
#query-e
DELIMITER $$
CREATE TRIGGER trg_insert_last_transaction
BEFORE INSERT ON Account
FOR EACH ROW
BEGIN
 SET NEW.LastTransactionDate = CURRENT_DATE();
END$$
DELIMITER ;
#query-f
DELIMITER //
CREATE PROCEDURE find_customers()
BEGIN
 -- Find the customer who has the highest number of accounts
 SELECT c.Name, COUNT(*) AS num_accounts
 FROM Customer c
 JOIN account a ON c.CustomerID= a.CustomerID
 GROUP BY c.CustomerID
 ORDER BY num_accounts DESC
 LIMIT 1;
 
 -- Find the customer who has the lowest balance
 SELECT c.Name, MIN(a.balance) AS min_balance
 FROM Customer c
 JOIN account a ON c.CustomerID = a.CustomerID
 GROUP BY c.CustomerID
 ORDER BY min_balance ASC
 LIMIT 1;
 
 -- Find the customer who is involved in the most joint accounts
 SELECT c.Name, COUNT(*) AS num_joint_accounts
 FROM Customer c
 JOIN account a ON c.CustomerID = a.CustomerID
 WHERE a.type = 'joint'
 GROUP BY c.CustomerID
 ORDER BY num_joint_accounts DESC
 LIMIT 1;
END //
DELIMITER ;
CALL find_customers()