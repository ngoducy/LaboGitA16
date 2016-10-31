#include <stdio.h>
#include <string.h>

struct contact {
	char telephone[11];
	char nom[30];
	char prenom[30];
};

void ecrire_fich(FILE *f, char *nom);

int main(int argc, char *argv[]) {

	struct contact contact1;
	char chaine[100], *fin;
	int telOK=0;
	unsigned long tel;
	FILE *fic;
	fic = fopen("repertoire", "a");
	
	printf("Entrez le nom : ");
	scanf("%s",chaine);
	strcpy(contact1.nom, chaine);

	printf("Entrez le prenom : ");
	scanf("%s",chaine);
	strcpy(contact1.prenom, chaine);

	while (!telOK) {
		printf("Entrez le telephone : ");
		scanf("%s",chaine);		//doit inclure \n
		tel = strtoul(chaine,&fin,10);
		if (strlen(chaine)!=10) {
			fprintf(stderr,"Telephone invalide (pas 10 chiffres).\n");	
		} else if (*fin!='\0'){
			fprintf(stderr,"Telephone invalide (caractère non numérique).\n");	
		} else if (chaine[0]=='0'){
			fprintf(stderr,"Telephone invalide (commence par 0).\n");	
		} else
			telOK=1;
	}
	strcpy(contact1.telephone, chaine);

	ecrire_fich(fic, contact1.nom);
	ecrire_fich(fic, contact1.prenom);
	ecrire_fich(fic, contact1.telephone);
	ecrire_fich(fic, "\n");

	fclose(fic);
}

void ecrire_fich(FILE *f, char *entree){
//	fputs(entree,fic);
	fprintf(f,"%s\t",entree);
	return;
}
