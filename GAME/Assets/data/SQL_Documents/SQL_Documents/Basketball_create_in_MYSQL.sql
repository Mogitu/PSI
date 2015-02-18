CREATE SCHEMA Basketball;


CREATE TABLE Basketball.Fine
(
  paymentnumber smallint NOT NULL,
  membernumber smallint(6),
  finetype varchar(1),
  dateofoffence date,
  amount decimal(10,2),
  CONSTRAINT fine_pkey PRIMARY KEY (paymentnumber)
);

CREATE TABLE Basketball.Member
(
  memberno smallint NOT NULL,
  lastname varchar(25) NOT NULL,
  initials varchar(6) NOT NULL,
  lastnameprefix varchar(7),
  birthdate date NOT NULL,
  sex varchar(1) NOT NULL,
  year smallint NOT NULL,
  street varchar(50) NOT NULL,
  houseno varchar(4) NOT NULL,
  addition varchar(4),
  postalcode varchar(7),
  city varchar(50) NOT NULL,
  telephone varchar(15),
  emailaddress varchar(50),
  plays_in varchar(10),
  reserve_player varchar(10),
  CONSTRAINT member_pkey PRIMARY KEY (memberno)
);

CREATE TABLE Basketball.Sportshall
(
  sportshallname varchar(25) NOT NULL,
  sportshallcity varchar(25) NOT NULL,
  numberofcourts smallint NOT NULL,
  CONSTRAINT sportshall_pkey PRIMARY KEY (sportshallname)
);

CREATE TABLE Basketball.Team
(
  teamcode varchar(10) NOT NULL,
  teamname varchar(50) NOT NULL,
  playclass varchar(8) NOT NULL,
  homehall varchar(25) NOT NULL,
  captain smallint(6),
  CONSTRAINT team_pkey PRIMARY KEY (teamcode)
);


CREATE TABLE Basketball.Game
(
  teamhome varchar(10) NOT NULL,
  playdate date NOT NULL,
  playtime time NOT NULL,
  court smallint(6) NOT NULL,
  playclass character(8) NOT NULL,
  teamaway varchar(10) NOT NULL,
  scorehome int NOT NULL,
  scoreaway int NOT NULL,
  CONSTRAINT game_pkey PRIMARY KEY (teamhome, playdate, playtime)
)