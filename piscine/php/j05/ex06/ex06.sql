SELECT  titre, resum 
FROM`db_lrenoud-`.film 
WHERE film.resum LIKE '%vincent%' 
ORDER BY id_film;