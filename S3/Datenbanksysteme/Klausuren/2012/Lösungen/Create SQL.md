```SQL
create table ggr_stadt (  
name varchar (50) primary key,  
kategorie varchar(50)  
check (kategorie in ('klein', 'mittel', 'gross', 'metropol')));  

create table ggr_kette (  
name varchar(50) primary key);  

create table ggr_filiale (  
filialid int primary key,  
kette varchar(50) references ggr_kette (name),  
strasse varchar(100),  
stadt varchar(20) references ggr_stadt (name));  

create table ggr_kunde (  
kartencode varchar(20) primary key,  
kname varchar(50),  
plz varchar (20),  
ort varchar (50),  
strasse varchar(100),  
email varchar(100));  

create table ggr_produkt (  
produktid int primary key, -- besser als name  
bezeichnung varchar(100),  
preis float);  

create table ggr_elektroartikel (  
produktid int primary key references ggr_produkt,  
ce boolean,  
tuev varchar(50));  

create table ggr_lebensmittel (  
produktid int primary key references ggr_produkt,  
mhd date);  

create table ggr_einkauf (  
einkaufid int primary key,  
zeitpunkt timestamp not null,  
filialid int not null references ggr_filiale,  
kartencode varchar(20) references ggr_kunde);  

create table ggr_prodeinkauf (  
einkaufid int references ggr_einkauf,  
produktid int references ggr_produkt,  
anzahl int ); -- anzahl ist optional  

create table ggr_angebot (  
produktid int references ggr_produkt,  
kette varchar(50) references ggr_kette (name),  
primary key (produktid, kette));
```