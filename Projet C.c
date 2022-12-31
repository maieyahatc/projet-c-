
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define true 0
#define false 1

struct produit
	{
		char idn[10];
		int  numSold;
		float ventes;
		char nom[20];
		int remise;
		int  qntt;
		float prix;

	};
	struct produit prod[30];
	int compt = 0;
 	FILE *f;

 	int writefile()
{
    int i;
    f = fopen("base_donnee.txt", "w");
    if (f == NULL)
        return -1;
    fprintf(f, "%d\n", compt);
    for (i = 0; i < compt; ++i)
    {

        fputs(prod[i].idn, f);
        fprintf(f, "\n");
        fputs(prod[i].nom, f);
        fprintf(f, "\n");
        fprintf(f, "%d\n", prod[i].qntt);
        fprintf(f, "%d\n", prod[i].numSold);
        fprintf(f, "%f\n", prod[i].prix);
        fprintf(f, "%d\n", prod[i].remise);
        fprintf(f, "%f\n", prod[i].ventes);
    }
    fclose(f);
    return 0;
}
int readFile()
{
    int N = 0, i;
    f = fopen("base_donnee.txt", "r");
    if (f == NULL)
        return -1;
    fscanf(f, "%d\n", &N);
    for (i = 0; i < N ; ++i)
    {
        fgets(prod[i].idn, 10, f);
        prod[i].idn[strlen(prod[i].idn) - 1] = 0;
        fgets(prod[i].nom, 20, f);
        prod[i].nom[strlen(prod[i].nom)-1] = 0;
        fscanf(f, "%d", &prod[i].qntt);
        fscanf(f, "%d", &prod[i].numSold);
        fscanf(f, "%f", &prod[i].prix);
        fscanf(f, "%d", &prod[i].remise);
        fscanf(f, "%f\n", &prod[i].ventes);
    }
    fclose(f);
    return N;
}



void AddProd(){

  	printf("Saisir un nouveau produit\n");
	readFile();
  	    if (compt>0) {
  	    compt=readFile();
  		IDCheck(0,compt);
		}
	else{
		printf("\nL'identifiant du produit: ");
		fflush(stdin);
		gets(prod[compt].idn);
		}
		printf("Le nom du produit: ");gets(prod[compt].nom);
		printf("La quantité du produit: ");scanf("%d",&prod[compt].qntt);
		printf("Le prix du produit: ");scanf("%f",&prod[compt].prix);
		printf("La remise du produit: ");scanf("%d",&prod[compt].remise);
		++compt;
	writefile();
}



int IDCheck(int i, int j)
{
	compt=readFile();
    printf("Identifiant du produit: ");
    fflush(stdin);
	gets(prod[compt].idn);
    if (strcmp(prod[i].idn,prod[j].idn)==0){
        printf("Identifiant déjà existant!!");
        return IDCheck(i++,j--);
		}
}


void Affichprod(){
	int i;

  compt = readFile();
  if (compt < 0)
    puts("Fichier inouvrable");
	printf(" \t\t\t\t *****  Base de données *****\n");
   printf("-------------------------------------------------------------------------------------------\n");
   printf("S.N.|    Nom     |  Identifiant  |  Quantité  |  Solde  |   Prix   |   Remise   |  Ventes   |\n");
   printf("--------------------------------------------------------------------------------------------\n");

   for (i=0;i<compt;i++){ // getting the details on each product updates.
   printf("%d     %-10s       %-8s     %-5d        %-3d       %-6.2f      %-5d%%       P%.2lf\n",i+1,prod[i].nom,prod[i].idn,prod[i].qntt,prod[i].numSold,prod[i].prix,prod[i].remise,prod[i].ventes);
	}

}

void Supprod(){
	compt=readFile();
	char id[10];
	int i,j;
	int B=false;
printf("Saisir l'identifiant du produit à supprimer : ");
fflush(stdin);
gets(id);

for(i=0;i<compt;i++){
	if(strcmp(prod[i].idn,id)==0){
	    B=true;
        for( j=i; j<(compt-1); j++)
			{
				prod[j]=prod[j+1];
			}
			compt--;
	}
}
if(B==false){
	printf("L'identifiant %s du produit n'existe pas.",id);
}
writefile();
}





void ModifProd(){
	char id[10];
    int test,i,choix;
    printf("Modifier un produit!");
    printf("\nSaisir l'identifiant du produit : ");
	fflush(stdin);
	gets(id);
	test=checkID(id);
    if (test == 0)
 {
  printf("L'identifiant %s untrouvable.", id);
 }
 else
 {
 		readFile();
  {
	for(i=0;i<compt;i++){

  if(strcmp(id,prod[i].idn)!=0)
	writefile();
   else
   {
    printf("\n1. Modifier l'identifiant du produit?");
    printf("\n2. Modifier le nom du produit? ");
    printf("\n3. Modifier la quantuté du produit?");
    printf("\n4. Modifier le prix du produit?");
    printf("\n5. Modifier la remise sur le produit?");
    printf("\nSaisir votre choix:");
    fflush(stdin);
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:

     printf("Saisir le nouveau identifiant: ");
 		fflush(stdin);
        gets(prod[i].idn);
     break;
    case 2:
     printf("Saisir le nouveau nom: ");
    	fflush(stdin);
        gets(prod[i].nom);
     break;
    case 3:
     printf("Saisir la nouvelle quantité: ");
    scanf("%d",&prod[i].qntt);
    break;
    case 4:
     printf("Saisir le nouveau prix: ");
    scanf("%f",&prod[i].prix);
     break;
     case 5:
     	 printf("Saisir la nouvelle remise: ");
   scanf("%d",&prod[i].remise);
    default:
     printf("Selection invalide");
     break;
    }
   writefile();
   }

   }
  }
  fclose(f);
  f = fopen("base_donnee.txt", "r");
 readFile();
 {
   writefile();
  }
  fclose(f);
 }
}

int checkID(char id[]){
	int i;
    compt=readFile();
    readFile();
    for(i=0;i<compt;i++){

	if(strcmp(id,prod[i].idn)!=0){

			 fclose(f);

		}
		return 1;

    }

 fclose(f);
 return 0;
}


void Recherche(char id[20]){
	 int i, B=false;
     for(i=0;(i<compt)&&(B==false);i++)
     {
          if(strcmp(prod[i].idn, id) == 0)
                B=true;

     }
     if (B==true)
     {
         printf("L'identifiant %s existe. \nle nom: %s \nQuantité restante: %d \nNombre de produits vendus: %d \nPrix du produit: %.2f \nLa remise sur le produit: %d %% \nTotal des ventes: %.2lf\n",prod[i].idn,prod[i].nom,prod[i].qntt,prod[i].numSold,prod[i].prix,prod[i].remise,prod[i].ventes);

     }
     else
     {
         printf("L'identifiant %s n'existepas.",prod[i].idn);
     }



}

void AchatProd(){// fonction  achat d'un produit
	int quant,i;
    char id[10];
    int B=false;
    compt=readFile();
	printf("Vente d'un article ");
    printf("\nIdentifiant du produit: ");
    fflush(stdin);
	gets(id);
    for (i=0; i<compt; i++){
        if (strcmp(id,prod[i].idn)==0)
        {
        	B=true;
        printf("\nProduit trouvé! Contenant: \n");
	   	printf("\nNom du produit: %s",prod[i].nom);
		printf("\nPrix du produit: %.2lfphp\n\n",prod[i].prix);

            printf("Saisir la quantité à acheter : ");
            fflush(stdin);
			scanf("%d",&quant);
            if (quant>prod[i].qntt){
               puts("\nQuantité insuffusante\nVeuillez restocker.\n ");
             break;
				}

            float tempventes = prod[i].ventes;  // will be executed if the quantity is greater than the users selected quantity.
            prod[i].numSold += quant;
            prod[i].qntt -= quant;
            prod[i].ventes = quant*(prod[i].prix*(prod[i].remise/100.0));
            prod[i].ventes += tempventes;
			}

	}
 if(B==false){

	printf("Identifiant untrouvable: %s.",id);
}
	writefile();


}

void DisZeroQte(){
		int i;

       compt= readFile();
         printf("\nProduit hors stock: ");
        for (i=0; i<compt; i++){
            if(prod[i].qntt==0){
                    printf("\nLe nom du produit: %s \nProduit Id: %s \nQuantité restante: %d \nNombre de produits vendus: %d \nPrix du produit: %.2f \nLa remise sur le produit: %d %% \nTotal des ventes: %.2lf\n",prod[i].nom,prod[i].idn,prod[i].qntt,prod[i].numSold,prod[i].prix,prod[i].remise,prod[i].ventes);
            }
        }
writefile();


}


int main (){
	int choix;
	char id[20];
	compt = readFile();
	if(compt < 0)
		printf("Fichier non localisé\n");
do {
	printf("\n");
	printf("\t\t\t  =================================================\n");
	printf("\t\t\t     Programme de la base de donnée des produits\n");
	printf("\t\t\t  =================================================");

	printf("\n\nCliquer:");
	printf("\n 1.) Enregistrer un nouveau produit.");
	printf("\n 2.) Modifier un produit.");
	printf("\n 3.) supprimer un produit");
	printf("\n 4.) Afficher tous les produits existants.");
	printf("\n 5.) Faire un achat.");
	printf("\n 6.) Rechercher un produit.");
	printf("\n 7.) Afficher les produits hors stock.");
	printf("\n 8.) Quitter le programme.");
	printf("\nChoix--> ");
	scanf("%d", &choix);
	     switch(choix){
        case 1 :
                AddProd();
                break;
        case 2:
		    	ModifProd();
				break;
        case 3:
                Supprod();
               	 break;
        case 4:
               Affichprod();
                break;
       	case 5:
                AchatProd();
		 break;
	   	case  6:
	   	    {
	   	        fflush(stdin);
                gets(id);
                Recherche(id);
                break;
	   	    }

		case 7:
                DisZeroQte();
		 	break;
		case 8:
		 	  exit(1);
			   break;
		 default :
                printf("Votre choix est invalide veuillez réessayer");
            break;
      }
  }while(choix!=8);
  printf("Merci d'avoir choisi ce programme.");
}


