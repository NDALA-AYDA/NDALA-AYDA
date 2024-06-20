#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choix;
    char numero_compte_unique[14];
    char client[100];

    printf("Menu\n");
    printf("========================================\n");
    do
    {
       printf("1.Creer un compte\n");
       printf("2.Effectuer un depot\n");
       printf("3.Effectuer un retrait\n");
       printf(".Quitter\n >>");

      scanf("%d", &choix);
    }
    while(choix != 0);

     while(choix != 4);
       if (choix == 1)

       printf("=========================================================================\n");
    printf("                      CREATION DU COMPTE BANCAIRE                        \n");
    printf("=========================================================================\n");

    int i;
    int result;
    int compt;
    struct Client client;
    time_t t = time(NULL); // R�cup�re le temps actuel (en secondes)
    struct tm* tm_info = localtime(&t); // Pour convertir le temps en heure locale
    srand(time(NULL));


    do{
        printf("Entrez 0 pour quitter ou 1 pour creer un compte : "); // Demande � l'utilisateur de faire le choix
        result = scanf("%d", &i);
        while(getchar() != '\n'); // On nettoie le buffer jusqu'� trouver le saut de ligne

        if (result == 1 && (i == 1 || i == 0)){
            break; // On sort de la boucle
        } else{
            printf("Entree invalide... \n"); // on demande � nouveau � l'utilisateur d'entrer
            compt ++; // Pendant ce temps, le compteur est incr�ment� de 1
        }
        if (compt == 5){
            printf("\n");
            printf("Vous avez atteint la limite de tentatives, Programme termine! \n");
            printf("------------------------------------------------------------\n");
            return 0; // Si le compteur atteint 5, on quitte le programme
        }
    } while(1);



    if (i == 0) {
        printf("Programme termine.\n");
        return 0; // Quitte le programme

    } else {
        printf("Processus de creation de compte...\n");
        // Execution du code suivant :


        printf("Entrez le nom du client: "); //Nom du client
        scanf("%49s", client.nom);

        printf("Entrez le post-nom du client: ");  //Post-nom du client
        scanf("%49s", client.postNom);

        printf("Entrez le prenom du client: ");  //Prenom du client
        scanf("%49s", client.prenom);

        printf("Veuillez saisir l'adresse du client :\n");
        printf("Commencons par le numero de la parcelle : ");
        scanf("%d", &client.adresse.numeroParcelle);

        printf("Entrez le nom de l'avenue : ");
        scanf("%49s", client.adresse.avenue);

        printf("Entrez le nom de la commune : ");
        scanf("%49s", client.adresse.commune);

        printf("Entrez le nom de la ville : ");
        scanf("%49s", client.adresse.ville);

        printf("Entrez le nom du pays : ");
        scanf("%49s", client.adresse.pays);

        printf("Entrez le lieu de naissance : ");
        scanf("%49s", client.lieuNaissance);

        printf("Entrez la date de naissance (\format aaaa-mm-jj)\ : ");
        scanf("%12s", client.dateNaissance);

        printf("Entrez le numero de telephone du client +243 ");
        scanf("%10s", client.numeroTelephone);

        //printf("\n");
        //printf("Le nom complet du client est : %s %s %s \n", client.nom, client.postNom, client.prenom); // On affiche le nom complet du client
        //printf("------------------------------------------------------\n");
        //return 0;

    }
    FILE *fichierCSV = fopen("Data_Base.csv", "a"); // Ouvrir le fichier CSV en mode �criture, il sera cr�� s'il n'existe pas.

    if (fichierCSV == NULL){ // Tester pour s'assurer que le fichier CSV a �t� bien ouvert
        printf("\n");
        printf("Erreur d'ouverture du fichier de base de donnees \n"); // Message d'erreur en cas d'�chec d'ouverture du fichier
        printf("------------------------------------------------");
        return 1;
    } else{
        //fprintf(fichierCSV,"SEP=, \n");
        //fprintf(fichierCSV,"Nom,Post-nom,Pr�nom,Adresse,Lieu de naissance,Date de naissance,Num Tel,Num�ro du compte,Date de cr�ation du compte\n"); // Ecrire les en-tetes des colonnes
        fprintf(fichierCSV, "%s,%s,%s,%d %s %s %s %s,%s,%s,%s,%11d,%d-%02d-%02d\n", client.nom, client.postNom, client.prenom, client.adresse.numeroParcelle, client.adresse.avenue, client.adresse.commune, client.adresse.ville, client.adresse.pays, client.lieuNaissance, client.dateNaissance, client.numeroTelephone, client.numero_compte_Unique, tm_info->tm_year + 1900, tm_info->tm_mon + 1, tm_info->tm_mday); // Ecrire les donn�es dans le fichier CSV
        fclose(fichierCSV);

    }

    printf("\n");
    printf("Creation du compte reussie pour le client %s %s %s!\n", client.nom, client.postNom, client.prenom);
    printf("----------------------------\n");

    return 0;

// transaction depot

 while(choix != 4)
   if(choix ==2){
    printf("effectuer un depot \n");
    printf("======================");
    
    int montant;
    char numero_compte_Unique[14];
    float solde;                     
    float  solde = 5.0;
    printf("entrer le numero du compte: ");
    scanf("%s", numero_compte_Unique);
    if(numero != numero_compte_Unique){
       printf("le numero n'exixste pas");
     }
    else {
        printf("entrer le montant: ");
        scanf("%d" montant);
       printf("====le depot effectuer avec succes====");
    
     }
    }
    
    printf("solde apres depot : %.2f\n", solde);
       return 0;


 while(choix != 4)
 printf("effectuer un retrait\n");
 printf("==================\n")
  int montant;
  char numero_compte_Unique[14];
  float solde;
   if(choix ==3){
    printf("entrer le numero du compte: ")
    scanf("%s", numero_compte_Unique);

    if(numero != numero_compte_Unique){
        printf("le numero n'existe pas")
    }

    else{
        printf("entrer le montant a retirer");
        scanf("%d", montant);
        printf("vous avez retirer : %d\n", montant);

        printf("solde apres retrait : %.2f\n", solde);
       
    }
   }  

   while(choix == 4)
   printf("quitter");

   return 0; 
}

