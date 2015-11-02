SELECT nom, prenom, DATE(date_naissance) AS 'date de naissance'
FROM`db_lrenoud-`.fiche_personne
WHERE EXTRACT(YEAR FROM fiche_personne.date_naissance) = 1989
ORDER BY nom;