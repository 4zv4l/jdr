# jdr
aide pour jeu de rôle

## stats.h
* contient les structures des personnages
* contient les données relatives aux mobs

## show.c
affiche les personnages et mobs dans un tableau

## save.c
contient save() et load()

## f.c
contient la plupart des fonctions pour la gestions des perso et des combats

# TODO
- [x] afficher les perso
- [x] créer les structures
- [x] changer l'odre de la team
- [ ] retirer item de l'inventaire 
- [x] sauvegarde avec inventaire
- [ ] ajouter des mobs
- [ ] mettre les bonnes caractéristiques aux mobs
- [x] tour par tour
- [ ] gérer les attaques/défenses/autres

# To compile
`make all`   for common usage <br/>
`make obj`   to compile dependences to object files <br/>
`make debug` to compile with debug informations <br/>
`make clean` clear the binary and object files <br/>
