SELECT klienci_txt.imie, klienci_txt.nazwisko, 
SUM(uslugi_dodatkowe.cena_uslugi), klienci_txt.nr_dowodu FROM 
(klienci_txt INNER JOIN noclegi_txt ON klienci_txt.nr_dowodu = noclegi_txt.nr_dowodu)
INNER JOIN uslugi_dodatkowe ON uslugi_dodatkowe.id_pobytu = noclegi_txt.id_pobytu
GROUP BY klienci_txt.nr_dowodu
ORDER BY nazwisko;