#include<stdio.h>
#include<string.h>



typedef struct date
{
    int jour;
    int mois;
    int annee;
}date;



typedef struct patient
{

    char nom[12];
    char prenom[12];
    int age;
    char sexe[12];
    char historique[100];
    char diagnostique[100];
    date d;
    char ordonnance[100];

}patient;

void saisietabpatient(patient T[],int n);
void affichageTabpatient(patient T[],int n);
void affichagelistepatient(patient T[],int n);
void recherchenompatient(char nom[],patient T[],int n);
void rechercheentredeuxdates (patient  T[],int  n,patient v,patient w);
void supprimerpatient(char nom[],patient T[] ,int n);
void  modifiertabpatient(patient T[],int  n,int t,patient X[]);


void saisietabpatient(patient T[],int n)
{
int i;
for(i=0;i<n;i++)
{
printf("\n\n Taper les informations du patient numero %d ",i+1);
printf("\n Taper le nom du patient  : ");
scanf("%s",&T[i].nom);
printf("\n Taper le prenom du patient  : ");
scanf("%s",&T[i].prenom);
printf("\n Taper l'age du patient : ");
scanf("%d",&T[i].age);
printf("\n Taper le sexe du patient  : ");
scanf("%s",&T[i].sexe);
printf("\n Taper la date de consulation du patient : ");
scanf("%d%d%d",&T[i].d.jour,&T[i].d.mois,&T[i].d.annee);
printf("\n Taper le diagnostique du patient : ");
scanf("%s",&T[i].diagnostique);
printf("\n saisir l'historique du patient : ");
scanf("%s",&T[i].historique);
printf("\n Taper l'ordonnance du patient : ");
scanf("%s",&T[i].ordonnance );
}
}




void affichageTabpatient(patient T[],int n)
{

int i;
for(i=0;i<n;i++)
{

    printf("\n\n patient numero : %d ",i+1);



printf("\n  le nom est : %s",T[i].nom);

printf("\n  le prenom est : %s",T[i].prenom);

printf("\n  le sexe est : %s",T[i].sexe);

printf("\n  l'age est : %d",T[i].age);

printf("\n  la date de consultation est : %d%d%d",T[i].d.jour,T[i].d.mois,T[i].d.annee);

printf("\n  La diagnostique est :  %s ",T[i].diagnostique);

printf("\n  L'historique est :  %s ",T[i].historique );

printf("\n  L'ordonnance est :  %s ",T[i].ordonnance );

}
}

void affichagelistepatient(patient T[100],int n)
{
int i;
printf("\n La liste des patients est : \n ");
for(i=0;i<n;i++)
{
printf("%s\n",T[i].nom);
}
}


void recherchenompatient(char nom[],patient T[],int n)
{



int i;
int pos;



for(i=0;i<n;i++)
{

    if(strcmp(T[i].nom,nom)==0)
    {
    pos=i;
    }

}
printf("La position du patient est : %d ",pos);
}

 void rechercheentredeuxdates (patient  T[],int  n,patient v,patient w)
    {
        int i;
        long int J[100],q,r;
        q=(v.d.jour)+(v.d.mois*30)+(v.d.annee*365);
        r=(w.d.jour)+(w.d.mois*30)+(w.d.annee*365);

        for(i=0;i<n;i++)
        {
            J[i]=(T[i].d.jour)+(T[i].d.mois*30)+(T[i].d.annee*365);
        }
        for(i=0;i<n;i++)
        {
            if  ((J[i]>=q)&&(J[i]<=r))
            {
                printf("\n%s %s.",T[i].nom,T[i].prenom);
            }
        }
    }


  void supprimerpatient(char nom[],patient T[] ,int n)
    {

        int i,pos;
        patient F[100];


for(i=0;i<n;i++)
{

    if(strcmp(T[i].nom,nom)==0)
    {
    pos=i;
    }

}
        for(i=pos;i<n;i++)
        {
            F[i]=T[i];
            T[i]=T[i+1];
            T[i+1]=F[i];
        }
       n--;
       affichageTabpatient(T,n);
       printf("\n \n Le patient a ete suprime ! ");
    }

  void  modifiertabpatient(patient T[],int  n,int t,patient X[])
    {
      int i;
    for(i=0;i<n;i++)
    {
    if(i==t)
    {
  T[t]=X[t];
    }
    }
   affichageTabpatient(T,n);
    }








int main()
{
patient T1[500],T[500],v,w;
int s=1,n,b,c,e;
char N[20],no[20];
do
{
      printf("\n 1.Nouveau patient. ");
      printf("\n 2.L'affichage des informations d'un patient.");
      printf("\n 3.L'affichage de la liste des patients.");
      printf("\n 4.La recherche d'un patient par nom.");
      printf("\n 5.La recherche des patient qui on fait une consultation entre deux dates quelconques.");
      printf("\n 6.La suppression d'un patient.");
      printf("\n 7.La modification des informations d'un patient. \n \n ");
      scanf("%d",&b);
if(b==1)
{
      printf("taper le nombre de patients:  ");
      scanf("%d",&n);
      saisietabpatient(T1,n);
}
if(b==2)
{
printf("Saisir le nombre du patient:  ");
scanf("%d",&c);
affichageTabpatient(T1,c);
}
if(b==3)
{
affichagelistepatient(T1,n);
}
if(b==4)
{
printf("Tapper le nom du patient a chercher : ");
scanf("%s",&N);
recherchenompatient(N,T1,n);
}
if(b==5)
{
printf("\n Taper la 1ere date : ");
scanf("%d %d %d",&v.d.jour,&v.d.mois,&v.d.annee);
printf("\n Taper la 2eme date : ");
scanf("%d %d %d",&w.d.jour,&w.d.mois,&w.d.annee);
rechercheentredeuxdates(T1,n,v,w);
}
if(b==6)
{
printf("Taper le nom du patient a supprime : ");
scanf("%s",&no);
supprimerpatient(no,T1,n);
}
if(b==7)
{
printf("Taper la position du patient:  ");
scanf("%d",&e);
saisietabpatient(T1,s);
modifiertabpatient(T1,n,e,T);
}
}while((b==1)||(b==2)||(b==3)||(b==4)||(b==5)||(b==6)||(b==7));

return 0;
}
