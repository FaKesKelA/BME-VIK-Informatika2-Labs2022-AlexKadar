DROP DATABASE IF EXISTS zh ;

CREATE DATABASE zh
	DEFAULT CHARACTER SET utf8
	DEFAULT COLLATE utf8_general_ci;

use zh;

CREATE TABLE terem(
	id int not null auto_increment primary key,
	epulet varchar(50) not null,
	terem_nev varchar(50) not null,
	ferohely int not null
);

INSERT INTO terem (epulet, terem_nev, ferohely) VALUES ('I', 'IE007', 200);
INSERT INTO terem (epulet, terem_nev, ferohely) VALUES ('I', 'IB028', 400);
INSERT INTO terem (epulet, terem_nev, ferohely) VALUES ('St', 'StNagy', 380);
INSERT INTO terem (epulet, terem_nev, ferohely) VALUES ('Ch', 'ChMax', 550);