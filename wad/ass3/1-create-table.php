<!-- http://master-gtu.blogspot.com/2012/03/ivan-bayross-programs-sql.html -->

<!-- http://programforamitystudent.blogspot.com/2009/11/client-master.html -->

<!-- http://programforamitystudent.blogspot.com/2009/11/salesman-master.html -->

<?php

require_once('config.php');

$query = "

SELECT * 
FROM information_schema.tables
WHERE table_schema = '$database' 
AND table_name = 'client_master'
LIMIT 1;

";

$is = mysqli_query($conn, $query);

if(mysqli_num_rows($is)) {
	echo "client_master Table Already Exists";
} else {
	$query = "CREATE table if not exists client_master(
	client_no varchar(6) primary key,
	name varchar(20) NOT NULL,
	address1 varchar(30),
	address2 varchar(30),
	city varchar(15),
	pincode int(8),
	state varchar(15),
	bal_due decimal(10,2));";

	$is = mysqli_query($conn, $query);
	if($is) {
		echo "client_master Table Created";
	} else {
		echo "<br>" . $query . "<br>";
		echo "client_master Create Table Failed";	
	}
}

$arr = array(
	"INSERT into client_master values('C00001','Ivan Bayross','','','Bombay',400054,'Maharashtra',15000);",
	"INSERT into client_master values('C00002','Vandana Saitwal','','','Madras',780001,'Tamil Nadu',0);",
	"INSERT into client_master values('C00003','Pramada Jaguste','','','Bombay',400057,'Maharashtra',5000);",
	"INSERT into client_master values('C00004','Basu Navindgi','','','Bombay',400056,'Maharashtra',0);",
	"INSERT into client_master values('C00005','Ravi Sreedharan','','','Delhi',100001,'Delhi',2000);",
	"INSERT into client_master values('C00006','Rukmini','','','Bombay',400050,'Maharashtra',0);"
);

echo "<br>===================<br>";
foreach ($arr as $key) {
	$query = $key;
	$is = mysqli_query($conn, $query);
	if($is) {
		echo "SUCCESS -> " . $key;
	} else {
		echo "FAILURE(Duplicate Record Possibililty) -> " . $key;
	} echo "<br>";

}



echo "<br>===================<br>";
$query = "

SELECT * 
FROM information_schema.tables
WHERE table_schema = '$database' 
AND table_name = 'product_master'
LIMIT 1;

";

$is = mysqli_query($conn, $query);

if(mysqli_num_rows($is)) {
	echo "product_master Table Already Exists";
} else {
	$query = "
	CREATE table product_master
	(
	product_no varchar(6) primary key,
	description varchar(20) NOT NULL,
	profit_percent decimal(5,2) NOT NULL,
	unit_measure varchar(10) NOT NULL,
	qty_on_hand int(8) NOT NULL,
	recorder_lvl int(8) NOT NULL,
	sell_price decimal(8,2) NOT NULL,
	cost_price decimal(8,2) NOT NULL
	);
	";

	$is = mysqli_query($conn, $query);
	if($is) {
		echo "product_master Table Created";
	} else {
		echo "<br>" . $query . "<br>";
		echo "product_master Create Table Failed";	
	}
}

$arr = array(
	"INSERT into product_master values('P00001','1.44 Floppies',5,'Piece',100,20,525,500)",
	"INSERT into product_master values('P03453','Monitors',6,'Piece',10,3,12000,11280)",
	"INSERT into product_master values('P06734','Mouse',5,'Piece',20,5,1050,1000)",
	"INSERT into product_master values('P07865','1.22 Floppies',5,'Piece',100,20,525,500)",
	"INSERT into product_master values('P07868','Keyboards',2,'Piece',10,3,3150,3050)",
	"INSERT into product_master values('P07885','CD Drive',2.5,'Piece',10,3,5250,5100)",
	"INSERT into product_master values('P07965','540 HDD',4,'Piece',10,3,8400,8000)",
	"INSERT into product_master values('P07975','1.44 Drive',5,'Piece',10,3,1050,1000)",
	"INSERT into product_master values('P08865','1.22 Drive',5,'Piece',2,3,1050,1000)"
);

echo "<br>===================<br>";
foreach ($arr as $key) {
	$query = $key;
	$is = mysqli_query($conn, $query);
	if($is) {
		echo "SUCCESS -> " . $key;
	} else {
		echo "FAILURE(Duplicate Record Possibililty) -> " . $key;
	} echo "<br>";

}




echo "<br>===================<br>";
$query = "

SELECT * 
FROM information_schema.tables
WHERE table_schema = '$database' 
AND table_name = 'salesman_master'
LIMIT 1;

";

$is = mysqli_query($conn, $query);

if(mysqli_num_rows($is)) {
	echo "salesman_master Table Already Exists";
} else {
	$query = "
	CREATE table salesman_master
	(
	salesman_no varchar(6) primary key,
	salesman_name varchar(20) NOT NULL,
	address1 varchar(30) NOT NULL,
	address2 varchar(30),
	city varchar(20),
	pincode varchar(6),
	state varchar(20),
	sal_amt decimal(8,2) NOT NULL,
	tgt_to_get decimal(6,2) NOT NULL,
	ytd_sales decimal(6,2) NOT NULL,
	remarks varchar(60)
	);
	";

	$is = mysqli_query($conn, $query);
	if($is) {
		echo "salesman_master Table Created";
	} else {
		echo "<br>" . $query . "<br>";
		echo "salesman_master Create Table Failed";	
	}
}

$arr = array(
	"INSERT into salesman_master values('S00001','Kiran','A/14','Worli','Bombay',400002,'MAH',3000,100,50,'Good')",
	"INSERT into salesman_master values('S00002','Manish','65','Nariman','Bombay',400001,'MAH',3000,200,100,'Good')",
	"INSERT into salesman_master values('S00003','Ravi','P-7','Bandra','Bombay',400032,'MAH',3000,200,100,'Good')",
	"INSERT into salesman_master values('S00004','Ashish','A/5','Juhu','Bombay',400044,'MAH',3000,200,150,'Good')"
);

echo "<br>===================<br>";
foreach ($arr as $key) {
	$query = $key;
	$is = mysqli_query($conn, $query);
	if($is) {
		echo "SUCCESS -> " . $key;
	} else {
		echo "FAILURE(Duplicate Record Possibililty) -> " . $key;
	} echo "<br>";

}




echo "<br>===================<br>";
$query = "

SELECT * 
FROM information_schema.tables
WHERE table_schema = '$database' 
AND table_name = 'sales_order'
LIMIT 1;

";

$is = mysqli_query($conn, $query);

if(mysqli_num_rows($is)) {
	echo "sales_order Table Already Exists";
} else {
	$query = "
	CREATE table sales_order
	(
	s_order_no varchar(6) primary key,
	s_order_date date,
	client_no varchar(6) references client_master(client_no),
	dely_addr varchar(25),
	salesman_no varchar(6) references salesman_master(salesman_no),
	dely_type char(1),
	billed_yn char(1),
	dely_date date,
	order_status varchar(10)
	);
	";

	$is = mysqli_query($conn, $query);
	if($is) {
		echo "sales_order Table Created";
	} else {
		echo "<br>" . $query . "<br>";
		echo "sales_order Create Table Failed";	
	}
}

$arr = array(
	"INSERT into sales_order values('O19001','1996-01-12','C00001','','S00001','F','N','1996-01-20','IP')",
	"INSERT into sales_order values('O19002','1996-01-25','C00002','','S00002','P','N','1996-01-27','C')",
	"INSERT into sales_order values('O46865','1996-02-18','C00003','','S00003','F','Y','1996-02-20','F')",
	"INSERT into sales_order values('O19003','1996-04-03','C00001','','S00001','F','Y','1996-04-07','F')",
	"INSERT into sales_order values('O46866','1996-05-20','C00004','','S00002','P','N','1996-05-22','C')",
	"INSERT into sales_order values('O10008','1996-05-24','C00005','','S00004','F','N','1996-05-26','IP')"
);

echo "<br>===================<br>";
foreach ($arr as $key) {
	$query = $key;
	$is = mysqli_query($conn, $query);
	if($is) {
		echo "SUCCESS -> " . $key;
	} else {
		echo "FAILURE(Duplicate Record Possibililty) -> " . $key;
	} echo "<br>";

}




echo "<br>===================<br>";
$query = "

SELECT * 
FROM information_schema.tables
WHERE table_schema = '$database' 
AND table_name = 'sales_order_details'
LIMIT 1;

";

$is = mysqli_query($conn, $query);

if(mysqli_num_rows($is)) {
	echo "sales_order_details Table Already Exists";
} else {
	$query = "
	create table sales_order_details
	(
	s_order_no varchar(6) references sales_order(s_order_no),
	product_no varchar(6) references product_master(product_no),
	qty_ordered decimal(8),
	qty_disp decimal(8),
	product_rate decimal(10,2)
	);
	";

	$is = mysqli_query($conn, $query);
	if($is) {
		echo "sales_order_details Table Created";
	} else {
		echo "<br>" . $query . "<br>";
		echo "sales_order_details Create Table Failed";	
	}
}

$arr = array(
	"INSERT into sales_order_details values('O19001','P00001',4,4,525)",
	"INSERT into sales_order_details values('O19001','P07965',2,1,8400)",
	"INSERT into sales_order_details values('O19001','P07885',2,1,5250)",
	"INSERT into sales_order_details values('O19002','P00001',10,0,525)",
	"INSERT into sales_order_details values('O46865','P07868',3,3,3150)",
	"INSERT into sales_order_details values('O46865','P07885',3,1,5250)",
	"INSERT into sales_order_details values('O46865','P00001',10,10,525)",
	"INSERT into sales_order_details values('O46865','P03453',4,4,1050)",
	"INSERT into sales_order_details values('O19003','P03453',2,2,1050)",
	"INSERT into sales_order_details values('O19003','P06734',1,1,12000)",
	"INSERT into sales_order_details values('O46866','P07965',1,0,8400)",
	"INSERT into sales_order_details values('O46866','P07975',1,0,1050)",
	"INSERT into sales_order_details values('O10008','P00001',10,5,525)",
	"INSERT into sales_order_details values('O10008','P07975',5,3,1050)"
);

echo "<br>===================<br>";
foreach ($arr as $key) {
	$query = $key;
	$is = mysqli_query($conn, $query);
	if($is) {
		echo "SUCCESS -> " . $key;
	} else {
		echo "FAILURE(Duplicate Record Possibililty) -> " . $key;
	} echo "<br>";

}




?>