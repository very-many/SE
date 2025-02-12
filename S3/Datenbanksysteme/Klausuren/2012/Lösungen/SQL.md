```SQL
-- 2-1 a In welchen St�dten gibt es eine Filiale der Kette gut&g�nstig?
Select distinct name from stadt natural join filiale where kette ='gut&guenstig';
-- 1' 2P Anm. stadt ist nicht notwendig, wenn name der stadt schluessel ist

-- 2-2 b Wie viele Filialen gibt es in Stuttgart?
select count(*) as anz_filialen
from filiale
where stadt='Stuttgart'
-- 0,75' 2P

-- 2-3 c Wie viele Eink�ufe enthielten ein Produkt, dessen Mindesthaltbarkeit zum Zeitpunkt des Einkaufs bereits abgelaufen war.
select count (distinct einkaufid)
from einkauf natural join einkaufprodukt natural join lebensmittel
where zeitpunkt > mhd;
-- 2' 5P

-- 2-4 d Erzeugen Sie eine Liste aller Eink�ufte einer bestimmten Filiale. Geben Sie dabei f�r jeden Einkauf die Anzahl der gekauften Produkte und den Gesamtwert des Einkaufs an.
select einkaufid, zeitpunkt, count(produktid), sum(anzahl * preis)
from einkauf natural join einkaufprodukt natural join produkt
where filialid = '123'
group by einkaufid
order by zeitpunkt; -- Sortierung ist optional 
-- 2,5' 6P

-- 2-5 e Geben Sie Filialen an, die Elektroartikel f�hren.
select distinct filialid
from filiale natural join angebot natural join elektroartikel;
-- 0,75' 3P 

-- 2-6 f Geben Sie Filialen an, die keine Elektroartikel f�hren.
select filialid -- distinct nicht notwendig, weil null nur einmal vorkommen kann
from angebot natural join elektroartikel right join filiale using (kette)
where produktid is null;
-- 2-6a fx 3' 6P  alternativ: 
select filialid -- distinct nicht notwendig, weil null nur einmal vorkommen kann
from angebot natural join elektroartikel right join filiale using (kette)
group by filialid having count(produktid)=0;

-- 2-7 g Nennen Sie die Bezeichnung(en) des oder der Elektroartikel mit dem h�chsten Preis.
select bezeichnung, preis -- preis nicht gefordert
from produkt natural join elektroartikel
where preis >= all (
   select preis from produkt natural join elektroartikel)
-- 2' 5P

-- 2-8 h Welche Kunden haben in Filialen aus mehr als einer Stadt eingekauft?
select kartencode, kname
from kunde natural join einkauf natural join filiale
group by kartencode having count(distinct stadt) > 1;
-- 2,5' 6P

-- 2-9 i Welche Filiale bzw. Filialen haben den h�chsten Umsatz erzielt? Sie erhalten 4 Zusatzpunkte, wenn Sie den Rabatt ber�cksichtigen, der bei Einsatz der Rabattkarte gew�hrt wird.
-- einfach
select filialid, 
   sum (anzahl * preis) as einkaufswert -- Umsatz selbst war nicht gefragt
from einkauf natural join einkaufprodukt natural join produkt
group by filialid 
having sum (anzahl * preis) >= all
	  (select sum (anzahl * preis) 
	  from einkauf natural join einkaufprodukt natural join produkt
		group by filialid );

-- mit Rabattber�cksichtigung		
select filialid, 
   sum (anzahl * preis * 
      case when kartencode is null then 1 else 0.98 end) as einkaufswert
from einkauf natural join einkaufprodukt natural join produkt
group by filialid 
having sum (anzahl * preis * 
      case when kartencode is null then 1 else 0.98 end) >= all
	  (select sum (anzahl * preis * 
      case when kartencode is null then 1 else 0.98 end) 
	  from einkauf natural join einkaufprodukt natural join produkt
		group by filialid );
-- 4'
		
-- 2-10 j Listen Sie alle Filialen mit der Anzahl ihrer Kunden. (Ein Kunde ist Kunde der jeweilgen Kette (Filiale) wenn er dort mindestens einmal eingekauft hat.)
select filialid, count (distinct kartencode)
from filiale left join einkauf using (filialid)
group by filialid
-- 2'

-- 2-10a jx Listen Sie alle Filialen mit der Anzahl ihrer treuen Kunden. (Ein Kunde ist treuer Kunde der jeweilgen Kette (Filiale), wenn er dort mehr als f�nfzig mal eingekauft hat.)
-- Variante 1 (erst treue Kunden einer Filiale ermitteln)
select filialid, count (kartencode) 
from filiale left join (
select kartencode, filialid
from einkauf
group by kartencode, filialid
having count(kartencode) > 50) as treue_kunden using (filialid)
group by filialid;
-- 3,5'

-- nicht gestellt: Geben Sie Filialen an, die mehr Umsatz durch Eink�ufe mit als durch Eink�ufe ohne Rabattkarte gemacht haben. Den Rabatt selbst brauchen Sie nicht zu ber�cksichtigen.
select filialid
from einkauf natural join einkaufprodukt natural join produkt
group by filialid
having sum (case when kartencode is not null then anzahl*preis end) >
       sum (case when kartencode is null then anzahl*preis end) ;
-- 4'
```
