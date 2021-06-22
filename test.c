while (team_joueur != mort || team_ennemis != mort)
{
  print("c'est au tour de *perso x*") //(se trouve dans la file)
  print("quelle action décide-t'il?\n 1: attaque physique;\n 2: attaque magique;\n 3 autre\n")
  switch
    case 1: attaque;
    case 2: magie;
    case 3: //passer au perso suivant
    case autre: redemander
  file++;
}


void magie (int* perso x)
{
  int donnee;
  int coeff, complex, sort, dist, ennemis;
  char magie;
  print("entrez la complexite du sort: 1 facile; 2 normal; 3 difficile:");
  scanf("%d", &donnee);
  switch donnee
    case 1: complex = 0.8;
    case 2: complex = 1;
    case 3: complex = 1.5;
    case autre: retour au print;
  
  print("entrez le type de magie (feu, eau, air, terre, vie, nature):");
  scanf("%c", &magie);
  
  print("entrez le niveau du sort (de 1 à 4):");
  scan("%d", &sort);
  
  print("entrez la distance à la cible:");
  scan("%d", &donnee);
  if 0<donnee<=30: dist = 10;
  if 30<donnee<=75: dist = 18;
  if 75<donnee<=200: dist = 36;
  if 200<donnee: dist = 80;
  
  print("entrez le nombre d'ennemis visés:")
  scan("%d", &ennemis)
  
  coeff = coeff_magie(complex, sort, magie, dist, ennemis)
  
  
  
  int coeff_magie (int complex, int sort, char magie, int dist, int ennemis)
  {
    return (20*complex*perso->niveau_magie(magie))/(sort*dist*math.ln(ennemis+1))
  }
