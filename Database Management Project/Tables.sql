create table Users
(userID integer unsigned not null,
email varchar(50) unique not null,
firstName varchar(50),
lastName varchar(50),
dateOfBirth date,
hometown varchar(50),
gender varchar(1),
password varchar(50),
primary key(userID));
 
create table Friends
(followerID integer unsigned not null,
followedID integer unsigned not null,
dateOfFriendship date,
primary key(followerID, followedID),
foreign key(followerID) references Users(userID),
foreign key(followedID) references Users(userID));
  
create table Albums
(albumID integer unsigned not null,
ownerID integer unsigned not null,
albumName varchar(255),
dateOfCreation date,
primary key(albumID),
foreign key(ownerID) references Users(userID));
 
create table Photos
(photoID integer unsigned not null,
albumID integer unsigned not null,
caption varchar(255),
loc varchar(255),
primary key(photoID),
foreign key(albumID) references Albums(albumID) on delete cascade);

create table Likes
(userID integer unsigned not null,
photoID integer unsigned not null,
primary key(userID, photoID),
foreign key(userID) references Users(userID),
foreign key(photoID) references Photos(photoID) on delete cascade);

create table Tags
(photoID integer unsigned not null,
tag varchar(50),
primary key(photoID, tag),
foreign key(photoID) references Photos(photoID) on delete cascade);

create table Comments
(commentID integer unsigned not null,
ownerID integer unsigned not null,
photoID integer unsigned not null,
text varchar(255),
dateOfComment date,
primary key(commentID),
foreign key(ownerID) references Users(userID),
foreign key(photoID) references Photos(photoID) on delete cascade);

insert into Users values(1,'ssmith@gmail.com','Stan','Smith','1969-11-22','Langley','M','317ecd32308a1385e1d3cef0744eafbeb55366d15e2ae711085532132795675e');
insert into Users values(2,'fsmith@gmail.com','Francine','Smith','1971-09-26','Langley','F','84a80433438115091d00e90972b13b3b3e543bb0cb45ef2cd733bc2a2f043e4f');
insert into Users values(3,'rsmith@gmail.com','Roger','Smith','1947-06-14','Langley','M','893b1f8fc0fcc0587bb2f02fa8df1ca3039b9c8deae23935b6b3243e97e857a0');
insert into Users values(4,'jtoews@gmail.com','Jonathan','Toews','1988-04-29','Winnipeg','M','2739039447b291f27496ae177a4a030af57f7c9c6f7e8f95b0f4c83e2fd37a5f');
insert into Users values(5,'pkane@gmail.com','Patrick','Kane','1988-11-19','Buffalo','M','a3a7e7773e0bbe94360fa3dedce73212c074cc76590e6304dfa5934b7e38c178');
insert into Users values(6,'mhossa@gmail.com','Marian','Hossa','1979-01-12','Stara Lubovna','M','865a5505579febff8a58bfb2e8ed1a99d0b91575eb9fae277c51ebc569654fd2');
insert into Users values(7,'dkeith@gmail.com','Duncan','Keith','1983-07-16','Winnipeg','M','61fe0e2a1eda119b0c32a9d3b21d8cbbebf8b0d69d16c98034946946792dd7d2');
insert into Users values(8,'ccrawford@gmail.com','Corey','Crawford','1984-12-31','Montreal','M','f3cdc1043ba7dd24bfa2376404d2fd924771de7fa3b82742be05c294947a0954');
insert into Users values(9,'bseabrook@gmail.com','Brent','Seabrook','1985-04-20','Richmond','M','8ee73be67d6daa0fc31046d36a52863a6c6ce8c002e4114771f7fefdabfffb32');
insert into Users values(10,'nhjalmarsson@gmail.com','Niklas','Hjalmarsson','1987-06-06','Eksjo','M','b93d630c1986ae02804f29f30d09142fa7c3d8187cb4c168ae1d67bb965e680e');
insert into Users values(11,'kenobi@gmail.com','Obi-Wan','Kenobi','1977-05-04','Fresno','M','64fd3eb1d75f225adf99c153b1d8e8e6056d883bfb54eae9bc86dba3ec81b835');
insert into Users values(12,'skywalker@gmail.com','Anakin','Skywalker','1980-05-04','Fresno','M','de7215f049aa18bc2c5733c6f64c94cddc98d5a0fac51395b907bcc1cdb4bcd6');
insert into Users values(13,'tano@gmail.com','Ahsoka','Tano','1990-05-04','Fresno','F','e8423af404d90b8189df8fb5c3ef8f975c7f4e043b4d03e48b493442ba91268f');
insert into Users values(14,'vlatona@gmail.com','Vincent','Latona','2000-11-07','Phoenix','M','ae4282086b8ecbee5cd33be806a6f984ad5b4e292bcaedc30f97bb69cd4ea1b8');


insert into Friends values(1,2,'2023-01-01');
insert into Friends values(2,1,'2023-01-02');
insert into Friends values(4,5,'2023-01-31');
insert into Friends values(4,6,'2023-02-08');
insert into Friends values(4,14,'2023-04-12');
insert into Friends values(5,1,'2020-01-02');
insert into Friends values(5,2,'2021-02-27');
insert into Friends values(5,4,'2023-01-31');
insert into Friends values(5,6,'2023-02-08');
insert into Friends values(6,1,'2020-01-02');
insert into Friends values(6,4,'2023-02-03');
insert into Friends values(6,5,'2023-02-03');
insert into Friends values(8,9,'2023-01-05');
insert into Friends values(9,8,'2023-01-06');
insert into Friends values(11,1,'2022-11-01');
insert into Friends values(11,12,'2023-01-07');
insert into Friends values(11,13,'2023-01-08');
insert into Friends values(13,12,'2023-01-09');


insert into Albums values(1,1,'Classified','2023-01-02');
insert into Albums values(2,1,'Declassified','2023-02-01');
insert into Albums values(3,2,'Trip to Paris','2023-01-26');
insert into Albums values(4,3,'Trip to Vegas','2023-02-08');
insert into Albums values(5,4,'2010 Conn Smythe','2023-01-01');
insert into Albums values(6,5,'2013 Conn Smythe','2023-01-05');
insert into Albums values(7,6,'Jersey Retirement','2023-01-06');
insert into Albums values(8,7,'2015 Conn Smythe','2023-02-05');
insert into Albums values(9,8,'2015 Best Of','2023-01-19');
insert into Albums values(10,9,'2013 Semi-finals','2023-02-11');
insert into Albums values(11,11,'Padawan','2023-02-12');
insert into Albums values(12,11,'Master','2023-02-13');
insert into Albums values(13,13,'Mandalore','2023-02-14');


insert into Photos values(1,1,'CIA Battleplan','https://sneakernews.com/wp-content/uploads/2014/10/stan-smith-adidas-american-dad.jpg');
insert into Photos values(2,2,'CIA Profile Picture','https://m.media-amazon.com/images/M/MV5BNTY1ZGRkN2YtNjJjMi00OTE5LTgyMGUtODk2OGE2NzQ4OWVmXkEyXkFqcGdeQWRpZWdtb25n._V1_.jpg');
insert into Photos values(3,2,'CIA Cover Photo','https://i.ytimg.com/vi/Ua3ew6rNPJ8/maxresdefault.jpg');
insert into Photos values(4,5,'Conn Smythe','https://ontapsportsnet.com/.image/t_share/MTkwOTE2NDM5MjgyMjk2NDA1/jonathan-toews.jpg');
insert into Photos values(5,5,'Cup Celebration','https://cms.nhl.bamgrid.com/images/photos/285869510/1284x722/cut.jpg');
insert into Photos values(6,6,'Hart Trophy','https://www.taipeitimes.com/images/2016/06/24/p18-160624-a1.jpg');
insert into Photos values(7,6,'Ted Lindsey','https://cms.nhl.bamgrid.com/images/photos/281021960/1024x576/cut.jpeg');
insert into Photos values(8,6,'Calder Trophy','https://hockeygods.com/system/gallery_images/8011/original.jpg?1327055115');
insert into Photos values(9,7,'Retirement','https://pbs.twimg.com/media/Fcn9xZQXEAUhMgh?format=jpg&name=900x900');
insert into Photos values(10,7,'Hall of Fame','https://cms.nhl.bamgrid.com/images/photos/327900100/1024x576/cut.jpg');
insert into Photos values(11,11,'Qui-Gon','https://upload.wikimedia.org/wikipedia/en/a/ad/Qui-Gon_Jinn.png');
insert into Photos values(12,11,'Maul','https://upload.wikimedia.org/wikipedia/en/b/bb/MaulStarWars.jpg');
insert into Photos values(13,12,'Anakin','https://cdn.mos.cms.futurecdn.net/6CV6TdhEBA4KQce3aNmmx6-320-80.jpg');


insert into Likes values(4,1);
insert into Likes values(4,4);
insert into Likes values(5,4);
insert into Likes values(6,4);
insert into Likes values(5,5);
insert into Likes values(4,6);
insert into Likes values(6,6);
insert into Likes values(4,7);
insert into Likes values(6,7);
insert into Likes values(7,9);
insert into Likes values(4,10);
insert into Likes values(5,10);
insert into Likes values(7,10);
insert into Likes values(12,11);
insert into Likes values(13,11);
insert into Likes values(4,12);
insert into Likes values(13,13);


insert into Tags values(4,'blessed');
insert into Tags values(4,'champs');
insert into Tags values(4,'mvp');
insert into Tags values(4,'test');
insert into Tags values(5,'achievement');
insert into Tags values(5,'blessed');
insert into Tags values(5,'champs');
insert into Tags values(6,'achievement');
insert into Tags values(6,'blessed');
insert into Tags values(6,'mvp');
insert into Tags values(9,'legendary');
insert into Tags values(10,'forever');
insert into Tags values(10,'hof');
insert into Tags values(11,'blessed');


insert into Comments values(1,4,10,'Congrats Hoss!','2023-01-25');
insert into Comments values(2,4,9,'Welcome to the club!','2023-11-15');
insert into Comments values(3,5,10,'You are the best!','2022-12-15');
insert into Comments values(4,7,10,'Best 2-way forward ever','2022-01-02');
insert into Comments values(5,5,9,'Meet you there one day','2023-02-05');
insert into Comments values(6,6,5,'Thanks for thinking of me!','2023-03-01');
insert into Comments values(7,8,6,'Congrats Kaner!','2023-05-04');
insert into Comments values(8,9,5,'I am in this one!','2023-08-01');
insert into Comments values(9,10,10,'Well deserved!','2022-12-23');
insert into Comments values(10,10,5,'Sweet memories!','2022-11-07');
insert into Comments values(11,13,12,'I hate this guy','2022-11-08');
insert into Comments values(12,13,13,'I know this guy','2022-11-09');
insert into Comments values(13,12,11,'Been a long time','2022-11-10');
insert into Comments values(14,4,10,'Well deserved!','2020-11-11');
insert into Comments values(15,10,9,'Well deserved!','2021-11-02');

