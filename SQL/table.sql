-- INSERT INTO uslugi_dodatkowe(data_wykonania, id_pobytu, rodzaj, cena_uslugi) VALUES
-- (2022-09-15, 1035, 2 , 30),
-- (2022-10-126, 1042, 2 , 30)
-- (FLOOR((RAND()*10)%6)+1, FLOOR((RAND()*1000)%1030)+1, 30),
-- (FLOOR((RAND()*10)%6)+1, FLOOR((RAND()*1000)%1030)+1, 20),
-- (FLOOR((RAND()*10)%6)+1, FLOOR((RAND()*1000)%1030)+1, 40),
-- (FLOOR((RAND()*10)%6)+1, FLOOR((RAND()*1000)%1030)+1, 50),
-- (FLOOR((RAND()*10)%6)+1, FLOOR((RAND()*1000)%1030)+1, 20);

-- UPDATE `uslugi_dodatkowe`
-- SET cena_uslugi = CASE 
--     WHEN rodzaj = 1 THEN 40
--     WHEN rodzaj = 2 THEN 30
--     WHEN rodzaj = 4 THEN 35
--     WHEN rodzaj = 5 THEN 40
--     ELSE 20
-- END;

SELECT imie, nazwisko, noclegi_txt.nr_dowodu, noclegi_txt.nr_pokoju, SUM(cena) 
FROM 
((noclegi_txt LEFT JOIN `pokoje_txt`
ON `noclegi_txt`.nr_pokoju = `pokoje_txt`.nr_pokoju) 
LEFT JOIN `klienci_txt` ON  noclegi_txt.nr_dowodu = `klienci_txt`.nr_dowodu)
GROUP BY nr_dowodu
ORDER BY nr_dowodu;