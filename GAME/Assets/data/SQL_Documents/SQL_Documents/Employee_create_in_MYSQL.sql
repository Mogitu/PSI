CREATE SCHEMA Employee;

USE Employee;

-- Create Table: afdeling
CREATE TABLE Department
(
  depno numeric(2) NOT NULL,
  depname varchar(14) NOT NULL,
  location varchar(13) NOT NULL,
  CONSTRAINT department_pkey PRIMARY KEY (depno)
);

-- Create Table: Prive
CREATE TABLE Privateinfo
(
  empno numeric(4) NOT NULL,
  ename varchar(10) NOT NULL,
  initials varchar(6),
  address varchar(25),
  postalcode varchar(6),
  city varchar(15),
  CONSTRAINT privateinfo_pkey PRIMARY KEY (empno)
);


-- Create Table: s_schaal
CREATE TABLE s_scale
(
  scale numeric NOT NULL,
  lowerlimit numeric NOT NULL,
  upperlimit numeric NOT NULL,
  CONSTRAINT scale_pkey PRIMARY KEY (scale)
);

-- Create table: werknemer
CREATE TABLE Employee
(
  empno numeric(4) NOT NULL,
  ename varchar(10) NOT NULL,
  efunction varchar(10) NOT NULL,
  boss numeric(4),
  employed date NOT NULL,
  salary numeric(7,2) NOT NULL,
  commission numeric(7,2),
  depno numeric(2),
  CONSTRAINT employee_pkey PRIMARY KEY (empno)
);

ALTER TABLE `Employee`.`Employee` 
ADD INDEX `employee_department_fk_idx` (`depno` ASC),
ADD INDEX `employee_boss_fk_idx` (`boss` ASC);

ALTER TABLE `Employee`.`Employee` 
ADD CONSTRAINT `employee_department_fk`
  FOREIGN KEY (`depno`)
  REFERENCES `Employee`.`Department` (`depno`)
  ON DELETE RESTRICT
  ON UPDATE RESTRICT,
ADD CONSTRAINT `Employee_boss_fk`
  FOREIGN KEY (`boss`)
  REFERENCES `Employee`.`Employee` (`empno`)
  ON DELETE RESTRICT
  ON UPDATE SET NULL;

ALTER TABLE `Employee`.`Privateinfo` 
ADD CONSTRAINT `privateinfo_employee`
  FOREIGN KEY (`empno`)
  REFERENCES `Employee`.`Employee` (`empno`)
  ON DELETE CASCADE
  ON UPDATE CASCADE;