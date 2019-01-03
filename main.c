#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"
/**********************************************************************/
/*                      Date : 01/01/2019                             */
/*                      Auteur : C. chevtchouk                        */
/**********************************************************************/
int main (int argc, char **argv){

  int choice;
  int exit = 1;

  do {
    //Affichage du Menu
    system("cls");
    printf("\nPoint stocker\n");

    printf("\n\n---------------------- MENU ---------------------");
    printf("\n| Enregistrez une nouvelle carte de fidelite: [1] |");
    printf("\n| Supprimer une carte de fidelite           : [2] |");
    printf("\n|  : [3] |");
    //Saisie du choix
    fflush(stdin);
    printf("Saisie du choix: ");
   	scanf("%d",&choice);

    //Boucle Switch pour exécuter les programmes
   	switch(choice){
      case 1: function1();
     	break;
      case 2: function2();
        break;
      case 3: function3();
     	break;
      //Message d'erreur si l'utilisateur tape autre chose
      default:
     	  printf("\nERREUR : Votre demande ne figure pas sur la liste du menu.\n");
     	  break;
   	}
    //Message de relancement ou de sortie du programme
   	printf("Rentrez 1 pour continuer ou 0 pour sortir.\n" );
   	scanf("%d",&exit);
  }while(exit == 1);
    return 0;
}
