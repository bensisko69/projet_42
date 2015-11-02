SELECT titre, resum
FROM`db_lrenoud-`.film 
WHERE film.titre LIKE '%42%' OR film.resum LIKE '%42%'
ORDER BY duree_min ASC;
