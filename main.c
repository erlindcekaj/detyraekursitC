#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

struct person
{
  char emri[20];
  char mbiemri[20];
  char tel[13];
  char vendlindja[60];
  char email[30];
  int mosha[10];
  char gjinia[3];
} v[200],temp;

int nr=0;

char fn[250]="info.txt"; // emri i file-it.

void menu()
{
  printf("\n===========================\n");
  printf("\n   Detyre   Kursi");
  printf("\n\n 1 - Lexo te dhenat ");
  printf("\n 2 - Regjistrim ");
  printf("\n 3 - Fshirje ");
  printf("\n 4 - Modifikim ");
  printf("\n 5 - Kerkim sipas emrit ");
  printf("\n s - Save ");
  printf("\n p - Paraqit ");
  printf("\n r - Rendit ");
  printf("\n d - Dalja");
  printf("\n-----------------------------");
  printf("\n Zgjedhja : ");
}

void lexo()
{
    system("cls");
 FILE *f;
 f=fopen(fn,"rb");
 if (f==NULL)
 {
   printf("\n \n   Gabim ne file");
   return;
 }

 nr=0;

 while (fread(&v[nr],sizeof(struct person),1,f))
 {
   nr++;
 }

 fclose(f);
}

void save()
{
 system("cls");
 FILE *f;
 f=fopen(fn,"wb");
 if (f==NULL)
 {
   printf("\n \n   Gabim ne file");
   return;
 }
int i;
 for(i=0;i<nr; i++)
 {
  fwrite(&v[i],sizeof(struct person),1,f);
 }

 fclose(f);
}

void dislay()
{
    system("cls");
 printf("\n\n  Lista e personave ");
 printf("\n=====================================");
 printf("\n   Emri     Mbiemri      Mosha     Gjinia     Nr tel    Vendlindja");
 printf("\n-------------------------------------");
 int i;
 for(i=0;i<nr; i++)
 {
  printf("\n%10s %10s %10s %10s %10s %10s",v[i].emri,v[i].mbiemri,v[i].mosha,v[i].gjinia,v[i].tel,v[i].vendlindja);
 }
 printf("\n\n");
}

void shto()
{
    system("cls");
     printf("\n\n Shtim");
     printf("\nEmri :");
     scanf("%s",v[nr].emri);
     printf("Mbiemri :");
     scanf("%s",v[nr].mbiemri);
     printf("Tel :");
     scanf("%s",v[nr].tel);
     printf("Vendlindja :");
     scanf("%s",v[nr].vendlindja);
     printf("Email :");
     scanf("%s",v[nr].email);
     printf("Mosha :");
     scanf("%s",v[nr].mosha);
     printf("Gjinia :");
     scanf("%s",v[nr].gjinia);
     nr++;
     system("cls");
}

void fshi()
{
 char v_emri[20];
 printf("\n\n Fshirje");
 printf("\nEmri :");
 scanf("%s",v_emri);
 int i;
 for(i=0;i<nr; i++)
 {
  if (strcmp(v_emri,v[i].emri)==0)
  {
      int j;
   for(j=i;j<nr-1; j++)
   {
     v[j]=v[j+1];
   }
   nr--;
   break;
  }
 }
}

void modifiko()
{
 char v_emri[20];
 printf("\n\n Ndryshim");
 printf("\nEmri :");
 scanf("%s",v_emri);
 int i;
 for(i=0;i<nr; i++)
 {
  if (strcmpi(v_emri,v[i].emri)==0)
  {
     printf("\nEmri i ri:");
     scanf("%s",v[i].emri);
     printf("Mbiemri i ri :");
     scanf("%s",v[i].mbiemri);
     printf("Tel :");
     scanf("%s",v[i].tel);
     printf("Adresa :");
     scanf("%s",v[i].vendlindja);
     printf("Email :");
     scanf("%s",v[i].email);
     break;
  }
 }
}

void kerko_emri()
{
 char v_emri[20];
 printf("\n\n Kerkim sipas emrit");
 printf("\nEmri :");
 scanf("%s",v_emri);
 int i;
 for(i=0;i<nr; i++)
 {
  if (strcmp(v_emri,v[i].emri)==0)
  {
     printf("\nEmri %s",v[i].emri);
     printf("\nMbiemri  %s",v[i].mbiemri);
     printf("\nTel  %s",v[i].tel);
     printf("\nAdresa  %s",v[i].vendlindja);
     printf("\nEmail %s",v[i].email);
  }
 }
}
void operatorTel()
{
    int i,vdf=0,telekom=0,eagle=0,plusi=0,fiks=0;
    for(i=0;i<nr;i++)
    {
    if(v[i].tel[2]=='9')
    vdf++;
    if(v[i].tel[2]=='8')
    telekom++;
    if(v[i].tel[2]=='7')
    eagle++;
    if(v[i].tel[2]=='6')
    plusi++;
    if(v[i].tel[1]=='6')
    fiks++;
    }
    printf("%d persona perdorin operatorin Vodafone\n",vdf);
    printf("%d persona perdorin operatorin Telekom\n",telekom);
    printf("%d persona perdorin operatorin Eagle\n",eagle);
    printf("%d persona perdorin operatorin Plus\n",plusi);
    printf("%d persona perdorin operator telefonie fikse\n",fiks);

}

void mosha()
{    int i,mosha1=0;
for(i=0;i<nr;i++)
    {if (v[i].mosha[0]=='1'&&v[i].mosha[1]>8)
    mosha1++;

     }
printf("\n Ne rregjister ndodhen %d persona mbi 18 vjec",mosha1);

}
void statistika()
{
    system("cls");
    printf("\nNe regjister ndodhen te rregjistruar: %d persona\n",nr);
    operatorTel();
    mosha();

}
void emriT()
{
    int i;
    int j;
    {for(i=0;i<nr;i++)
{for(j=i;j<nr;j++)
{if (strcmp(v[i].emri,v[j].emri)==1)
	{temp=v[i];
	v[i]=v[j];
	v[j]=temp;
	}
	else if (strcmp(v[i].emri,v[j].emri)==0)
	{if (strcmp(v[i].mbiemri,v[j].mbiemri)==1)
	{temp=v[i];
	v[i]=v[j];
	v[j]=temp;
	}}}}}

  system("cls");
 printf("\n\n  Lista e personave ");
 printf("\n=====================================");
 printf("\n   Emri       Mbiemri      Nr tel");
 printf("\n-------------------------------------");
 for(i=0;i<nr; i++)
 {
  printf("\n%10s %10s %10s",v[i].emri,v[i].mbiemri,v[i].tel);
 }
 printf("\n\n");

}


void rendit()
{
    int x;
    printf("Rendit sipas : \n1- Emrit\n2-Mbimrit ");
    scanf("%d",&x);
    switch (x){
case 1 :
    emriT();
    break;
case 2 :
    break;
    }

}


main()
{
 char k;
 lexo();
 do
 {
   menu();
   k=getch();
   if (k=='1') lexo();
   else if (k=='2') shto();
   else if (k=='3') fshi();
   else if (k=='4') modifiko();
   else if (k=='s') save();
   else if (k=='5') kerko_emri();
   else if (k=='p') dislay();
   else if (k=='t') statistika();
   else if (k=='r') rendit();


 }while (k!='d' && k!='D' && k!=27);

}

