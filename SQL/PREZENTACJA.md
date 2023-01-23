# SQL - Jeden z najbardziej agresywnych jezyków
- język bazodanowy
- Całe tabele, na których są pokazywane przykłady:
    - **[Osoby](tabele/osoby.md)**,
    - **[noclegi_txt](tabele/noclegi_txt.md)**,
    - **[pokoje_txt](tabele/pokoje_txt.md)**,
    - **[klienci_txt](tabele/klienci_txt.md)**,
    - **[uslugi_dodatkowe](tabele/uslugi_dodatkowe.md)**,
<!-- TODO: WYPISAĆ WIĘCEJ PUNKTÓW -->
---
<!-- # podpowiedzi -> **HOCH** -->

## > ***SELECT*** <kolumna/kolumny> ***FROM*** \<tabela>
- wybiera ze wskazanej tabeli rekordy ze wskazanych kolumn
```sql
SELECT ID, imie, nazwisko FROM osoby; -- Wybiera dane z kolumn ID, imie, nazwisko 
SELECT * FROM osoby; -- Wybiera dane ze wszystkich kolumn
```

## > ***SELECT DISTINCT*** \<kolumna> ***FROM*** \<tabela>
- słowo **DISTINCT** dodane przed przed daną kolumną sprawia, że we wskazanej kolumnie nie pojawią się duplikaty,
```sql
SELECT DISTINCT plec FROM osoby; -- zwraca tylko 2 wartości: "K" i "M", które się nie powtarzają
SELECT COUNT(DISTINCT plec) FROM osoby; -- zwraca liczbę różnych wartości z kolumny plec(czyli 2);
```

## > ***SELECT*** \<kolumna> ***AS*** \<nazwa> ***FROM*** \<tabela>
- Zwraca kolumnę z podaną nazwą
```sql
SELECT imie, partner_ID AS "ID partnera" FROM osoby -- zwróci wartości z kolumn imie, partner_ID, ale druga kolumna będzie nazywać się "ID partnera" 
```

## > ... ***LIMIT/ TOP*** \<liczba>
- Zwraca podaną liczbę wierszy
- ***UWAGA:*** w Accesie prawdopodobnie ta funkcja nie istnieje, zamiast niej jest **TOP**, sposób używania jest taki sam
```sql
SELECT ID, imie, nazwisko FROM osoby LIMIT 5; -- zwróci tylko 5 rekordów
SELECT ID, imie, nazwisko FROM osoby TOP 5; -- zwróci tylko 5 rekordów
```

## > ... ***ORDER BY*** \<kolumna>
- Zwraca rekordy posortowane według wartości z **kolumna**
- dodając **DESC** rekordy będą posortowane malejąco, natomiast dodając **ASC** będą posortowane rosnąco(tak jest domyślnie)
```sql
SELECT * FROM osoby ORDER BY ID DESC; -- zwraca rekordy posortowane wg. ID malejąco
SELECT * FROM osoby ORDER BY nazwisko, imie; -- zwraca rekordy posortowane wg. nazwiska, a później wg imienia
```

## > ... ***WHERE*** \<warunek>
- zwraca rekordy, które spełniają podany warunek/podane warunki,
- warunki można łączyć używająć **OR** oraz **AND**,
- warunki mozna łączyć w nawiasy,
- można używać sformułowania **NOT**, jako zaprzeczenie danego warunku
- do porównywania liczb używa się: ">", "<", "=", "<>", jednak sprawdzić, czy dana kolumna jest pusta(wynosi **NULL**), używa się sformułowania **IS NULL**
```sql
SELECT imie, nazwisko FROM osoby WHERE plec = "K"; -- zwraca imie i nazwisko kobiet
SELECT imie, nazwisko FROM osoby WHERE id > 20; -- zwraca imie i nazwisko osób, których ID jest większe od 5
SELECT imie, nazwisko FROM osoby WHERE matka_ID = 2 AND partner_ID IS NOT NULL; -- zwraca imie i nazwisko osob, które mają partnera
SELECT imie, nazwisko FROM osoby WHERE (id > 20 AND plec="M") OR imie = "Monika"; -- zwraca imie i nazwisko osób, których ID jest większe od 5, albo plec = M;
SELECT imie, nazwisko FROM osoby WHERE NOT imie = "Monika"; -- zwraca imie i nazwisko osob, które nie mają na imię Monika
``` 

## > ... ***WHERE*** \<kolumna> ***BETWEEN*** \<liczba> ***AND*** \<liczba>
- zwraca rekordy, w których wartość z **\<kolumna>** należy do wskazanego przedziału (obustronnie domkniętego)
```sql
SELECT ID, imie, nazwisko FROM osoby WHERE ID BETWEEN 5 AND 15 -- zwraca ID, imie i nazwisko osób, których ID mieści się jest w przedziale <5,15>
```

## > ... ***WHERE*** \<kolumna> ***IN*** (*\<wartosc_1>, \<wartosc_2>, ...*)
- zwraca rekordy, których <u>wartość z **\<kolumna>**</u> znajduje się we wskazanym zbiorze
- zbiór można zdefiniować poprzez podawanie dokładnych wartości, lub poprzez użycie formuły wybierające wartości z innej tabeli ("***SELECT ... FROM ....***");
```sql
SELECT imie, nazwisko FROM osoby WHERE imie IN ("Monika", "Marek", "Joanna"); -- zwraca te osoby, które mają na imie Monika, Marek, albo Joanna
SELECT imie, nazwisko FROM osoby WHERE imie IN (SELECT imie FROM osoby WHERE plec = "K"); -- zwraca te osoby, które mają żeńskie imiona
```

## > ... ***WHERE*** \<kolumna> = ***ANY*** (***SELECT ...***)
- means that the condition will be true if the operation is true for any of thevalues in the range.
```sql
SELECT ProductName 
FROM Products
WHERE ProductID = ANY (SELECT ProductID FROM OrderDetails WHERE Quantity = 10);
```
## > ... ***WHERE*** \<kolumna> = ***ALL*** (***SELECT ...*** )
- używa się najczęściej wtedy, gdy kolumna ma wiele wartości,
- zwraca rekordy wtedy, gdy dana wartość sprawdza się dla wszystkich elementów w danym podzbiorze,
```sql
SELECT ProductName
FROM Products
WHERE ProductID = ALL
(SELECT ProductID FROM OrderDetails
WHERE Quantity = 10);
```

## > ... ***WHERE EXISTS (SELECT ... )***
- zwraca rekordy, które istnieją w danym podzbiorze
```sql
SELECT imie, nazwisko, miejscowosc
FROM `klienci_txt` 
WHERE NOT EXISTS(
    SELECT * FROM osoby 
    WHERE miejscowosc IN ("Katowice", "Opole")
    )
```

## > ... ***GROUP BY*** \<kolumna/kolumny>
- służy do grupowania rekordów wg. wartości z podanej kolumny lub kolumn;
- Najczęściej używane z funkcjami:
  - **COUNT()** - zlicza rekordy,
  - **MAX()** - zwraca największą wartość,
  - **MIN()** - zwraca minimalną wartość,
  - **SUM()** - zwraca sumę wartości, 
  - **AVG()** - wylicza średnią z danych wartości,
- Można te wymienione funkcje używać bez sformułowania **GROUP**;
```sql
SELECT plec, COUNT(plec) AS ile FROM osoby GROUP BY plec; -- zwraca ilość kobiet i mężczyzn
```

## > ... ***HAVING*** \<warunek>
- używane zamian za **WHERE**  wtedy, gdy jest grupowanie i pojawiają się funkcje zliczające/podsumowujące grupy, tj. **SUM, MIN, MAX, AVG, and COUNT**
```sql
SELECT imie, SUM(godziny_pracy) AS "Suma godzin pracy"    
FROM pracownicy    
GROUP BY imie    
HAVING SUM(godziny_pracy) > 6;    
```
Przykład używając tabele z matury 2022: **pokoje_txt, noclegi_txt, klienci_txt** 
```sql
SELECT imie, nazwisko, noclegi_txt.nr_dowodu, noclegi_txt.nr_pokoju, SUM(cena) 
FROM 
((noclegi_txt LEFT JOIN `pokoje_txt`
ON `noclegi_txt`.nr_pokoju = `pokoje_txt`.nr_pokoju) 
LEFT JOIN `klienci_txt` ON  noclegi_txt.nr_dowodu = `klienci_txt`.nr_dowodu)
GROUP BY nr_dowodu
HAVING SUM(cena) > 1000
ORDER BY `SUM(cena)` DESC;
```
imie | nazwisko | nr_dowodu | nr_pokoju | SUM(cena)
--- | --- | --- | --- | ---
Mateusz | Slomka | OTK325652 | 503 | 1470
Andrzej | Goerlich | EDJ564662 | 109 | 1380
Dominik | Rogoz | GMU219892 | 504 | 1300
Malgorzata | Mikocka | KLS689304 | 311 | 1260
Joanna | Lichorowicz | CAK316672 | 311 | 1200
Anna | Padol | DNH167930 | 508 | 1200
Marek | Szala | ARE827054 | 505 | 1120

---
## **Join** - łączenie rekordów z kilku tabel
```sql
-- Schemat łączenia dwóch tabel:
SELECT tabela_1.kolumna_1, tabela_2.kolumna_3 FROM tabela_1
INNER/LEFT/RIGHT/FULL JOIN tabela_2
ON tabela_1.pole_1 = tabela_2.pole_1;

-- Schemat łączenia trzech tabel:
SELECT tabela_1.kolumna_1, tabela_2.kolumna_3, tabela_3.kolumna_2
FROM
((tabela_1 
INNER/LEFT/RIGHT/FULL JOIN tabela_2 ON tabela_1.kolumna_1 = tabela_2.kolumna_2)
INNER/LEFT/RIGHT/FULL JOIN tabela_3 ON tabela_2.kolumna_4 = tabela_3.kolumna_3);
```

> ***ON** <tabela_1>.<pole_1> = <tabela_2>.<pole_1>* - warunek połaczenia, tworzenie relacji między polem z **<tabela_1>** i polem z **<tabela_2>**, pola muszą mieć taki sam typ

> Nie zawsze przed nazwą pola trzeba dodawać nazwę tabeli. Podajemy ją w przypadku, gdy nazwa kolumny nie jest jednoznaczna(pojawia się w obu tabelach)

### <u> Typy łączenia </u>:
- **(INNER) JOIN** - zwraca rekordy z dwóch tabel, pomiędzy którymi jest jakaś relacja(udało sie dopasować dane; pasujące do siebie wzajemnie)
```sql
SELECT id_pobytu, data_przyjazdu, data_wyjazdu, imie, nazwisko
FROM `noclegi_txt`
INNER JOIN `klienci_txt`
ON klienci_txt.nr_dowodu = `noclegi_txt`.nr_dowodu
```  
id_pobytu | data_przyjazdu | data_wyjazdu | imie | nazwisko
--- | --- | --- | --- | ---
1 | 2022-07-01 | 2022-07-02 | Krzysztof | Samek
2 | 2022-07-01 | 2022-07-02 | Joanna | Zwolinska
3 | 2022-07-01 | 2022-07-02 | Krzysztof | Tusinski
4 | 2022-07-01 | 2022-07-02 | Dariusz | Czaja
5 | 2022-07-01 | 2022-07-02 | Pawel | Walter
---
- **LEFT (OUTER) JOIN** - zwraca wszystkie rekordy z **lewej** tabeli pasujące i pasujące rekordy z **prawej** tabeli
```sql
SELECT noclegi_txt.id_pobytu, nr_dowodu, data_wykonania, rodzaj, cena_uslugi
FROM noclegi_txt
LEFT JOIN uslugi_dodatkowe
ON uslugi_dodatkowe.id_pobytu = noclegi_txt.id_pobytu
ORDER BY data_wykonania DESC, id_pobytu;
```
id_pobytu | nr_dowodu | data_wykonania | rodzaj | cena_uslugi
--- | --- | --- | --- | ---
242 | IYH931501 | 2022-07-14 | 5 | 40
213 | LKT701595 | 2022-07-10 | 6 | 20
154 | CCE703436 | 2022-07-08 | 1 | 40
108 | ANA920725 | 2022-07-06 | 5 | 40
51 | OLC411350 | 2022-07-02 | 3 | 20
44 | OWA866865 | 2022-07-01 | 4 | 35
2 | DAE905064 | 2022-06-30 | 1 | 40
1 | MZP112190 | NULL | NULL | NULL
3 | SZH897459 | NULL | NULL | NULL
4 | ARC412835 | NULL | NULL | NULL
---
- **RIGHT (OUTER) JOIN** - zwraca wszystkie rekordy  z **prawej** tabeli i pasujące do nich rekordy z **lewej** tabeli
```sql
SELECT noclegi_txt.id_pobytu, nr_dowodu, data_wykonania, rodzaj, cena_uslugi
FROM noclegi_txt
RIGHT JOIN uslugi_dodatkowe
ON uslugi_dodatkowe.id_pobytu = noclegi_txt.id_pobytu
ORDER BY data_wykonania DESC, id_pobytu;
```
id_pobytu | nr_dowodu | data_wykonania | rodzaj | cena_uslugi
--- | --- | --- | --- | ---
154 | CCE703436 | 2022-07-08 | 1 | 40
108 | ANA920725 | 2022-07-06 | 5 | 40
51 | OLC411350 | 2022-07-02 | 3 | 20
44 | OWA866865 | 2022-07-01 | 4 | 35
2 | DAE905064 | 2022-06-30 | 1 | 40
NULL | NULL | 0000-00-00 | 2 | 30
NULL | NULL | 0000-00-00 | 2 | 30
---
- **FULL (OUTER) JOIN** - zwraca wszystkie rekordy z **obu** tabel
<!-- TODO: Dodać schemat wymienionych joinów -->
```sql
SELECT id_pobytu, nr_dowodu, data_wykonania, rodzaj, cena_uslugi
FROM uslugi_dodatkowe
FULL JOIN noclegi_txt
ON id_pobytu
ORDER BY data_wykonania DESC, id_pobytu;
```
- **self Join** - ten sam join, ale odwołuje się do pól z tej samej tabeli, przykład:
```sql
-- Przykładowy "self join", przypisuje do osoby Imie jego matki na podstawie matka_ID
SELECT A.imie, A.nazwisko, B.imie as Imie_Matki
FROM osoby A, osoby B
WHERE A.matka_ID = B.ID
ORDER BY A.nazwisko, B.imie;
```

---
## ***CREATE TABLE*** nazwa(pole **typ**, ....)
- Tworzenie tabeli o wskazanej nazwie i z danymi polami,
- podstawowe typy danych: **INT, BOOL, DATE, TEXT** 
```sql
--- Tworzenie tabeli z zadania 5.4 z matury próbnej grudzień 2022
CREATE TABLE uslugi_dodatkowe(
    data_wykonania DATE,
    id_pobytu INT,
    rodzaj INT,
    cena_uslugi INT
);
```
---
# Zadania:
- [zadanie5_3](zadanie5_3.sql)
- [zadanie5_4](zadanie5_4.sql)
- [zadanie5_5](zadanie5_5.sql)