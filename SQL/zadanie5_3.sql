SELECT nr_pokoju FROM `pokoje_txt`
WHERE standard = "N" AND 
nr_pokoju NOT IN
	(SELECT nr_pokoju FROM noclegi_txt
	INNER JOIN klienci_txt
	ON klienci_txt.nr_dowodu=noclegi_txt.nr_dowodu
	WHERE miejscowosc IN ("Opole", "Katowice")
   );
    