SELECT rodzaj, COUNT(id_pobytu) 
FROM `uslugi_dodatkowe`
GROUP BY rodzaj