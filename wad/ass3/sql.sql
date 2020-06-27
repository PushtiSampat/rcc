CREATE TABLE Client_master (
Clientno varchar(6) primary key CHECK ,
Name varchar(25) not null,
Address1 varchar(20),
Address2 varchar(20),
City varchar(15),
Pincode int(8),
State int(15),
Bal_due decimal(10,2),
CONSTRAINT chk_Clientno CHECK (Clientno LIKE 'C%')
);