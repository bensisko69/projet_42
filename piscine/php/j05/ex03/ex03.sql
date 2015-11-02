INSERT INTO ft_table 
SELECT NULL, fiche_personne.nom, 'other', fiche_personne.date_naissance 
FROM fiche_personne
WHERE fiche_personne.nom LIKE '%a%' AND CHAR_LENGTH(fiche_personne.nom) < 9
ORDER BY fiche_personne.nom
LIMIT 10;