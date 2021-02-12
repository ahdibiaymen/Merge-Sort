#include <stdio.h>
void triFusion(int i, int j, int tab[], int tmp[]) {
    if(j <= i){ return;}

    int m = (i + j) / 2;

    triFusion(i, m, tab, tmp);     //trier la moitie gauche recursivement //sorting the left part recursively
    triFusion(m + 1, j, tab, tmp); //trier la moitie droite recursivement //sorting the right part recursively
    int pg = i;     //pg pointe au debut du sous-tableau de gauche //pg points on the left sub-array
    int pd = m + 1; //pd pointe au debut du sous-tableau de droite //pd points on the right sub-array
    int c;          //compteur //counter
// on boucle de i a j pour remplir chaque element du tableau final fusionne
// loop from i to j to fill every element of the final sorted array
    for(c = i; c <= j; c++) {
        if(pg == m + 1) { //le pointeur du sous-tableau de gauche a atteint la limite //left sub-array pointer reached the limit
            tmp[c] = tab[pd];
            pd++;
        }else if (pd == j + 1) { //le pointeur du sous-tableau de droite a atteint la limite //right sub-array pointer reached the limit
            tmp[c] = tab[pg];
            pg++;
        }else if (tab[pg] < tab[pd]) { //le pointeur du sous-tableau de gauche pointe vers un element plus petit //left sub-array pointer points on smaller element
            tmp[c] = tab[pg];
            pg++;
        }else {  //le pointeur du sous-tableau de droite pointe vers un element plus petit //right sub-array pointer points on smaller element
            tmp[c] = tab[pd];
            pd++;
        }
    }
    for(c = i; c <= j; c++) {  //copier les elements de tmp[] vers tab[] //copy elements from temporary tmp[] to original tab[]
        tab[c] = tmp[c];
    }
}
int main() {
  int  nbr, i, tab[100], tmp[100];

  //provide array's length
  printf(" Entrez le nombre d'elements dans le tableau: ");
  scanf("%d", &nbr);


  /*Manual data filling */
  /** remplissage de tableau avec des valeurs saisi manuellement */
  /*
  printf(" Entrez %d entiers : ", nbr);

  for (i = 0; i < nbr; i++)
    scanf("%d", &tab[i]);
  triFusion(0, nbr-1, tab, tmp);
  */
    /*Automatic data filling */
  /** remplissage de tableau avec des valeurs automatiques */

  for (i = 0; i < nbr; i++)
    //scanf("%d", &tab[i]);
    tab[i]=rand()%32; //Can be changed //changeable
  //Printing non-sorted 1D Array
  printf("\n Tableau non trie : ");
  for(i = 0; i < nbr; i++)  {
     printf(" %4d", tab[i]);
  }
//calling Sorting method
  triFusion(0, nbr-1, tab, tmp);

  //Printing sorted 1D Array
  printf("\n Tableau trie : ");
  for(i = 0; i < nbr; i++)  {
     printf(" %4d", tab[i]);
  }
  printf("\n");
  return 0;
}
