#include <stdio.h>
#include <stdlib.h>

struct{
char isim[10];
char soyisim[15];
char birlestirilmis[25];
char sifreli[25];
int girilenno;
}id;








FILE *fp;
    long int asal;
    int buyukasal,i,bolum=2,z=0;
int oteleme;



int main()
{
sezarsifrele();
dosyayaz();
printf("OGRENCI NUMARASINI GIRINIZ:\n");
scanf("%d",&id.girilenno);

printf("EN BUYUK ASAL CARPANI GIRINIZ\n");
scanf("%d",&asal);
printf("ogrenci numarasi : %d\n\n",id.girilenno);
enbuyukasal();
dosyaokuma();
sezarcozum();

}




void sezarsifrele(){
    printf("ADINIZI GIRINIZ \n");
    gets(id.isim);
    printf("SOYADINIZI GIRINIZ\n");
    gets(id.soyisim);
strcpy(id.birlestirilmis,id.isim);
strcat(id.birlestirilmis,id.soyisim);

printf("LUTFEN OTELEME MIKTARINI GIRINIZ  :");
        scanf("%d",&oteleme);

    for (i = 0; id.birlestirilmis[i] != '\0'; i++)
         {
            id.birlestirilmis[i] = id.birlestirilmis[i] + oteleme;
            if (id.birlestirilmis[i] > 'z')
               id.birlestirilmis[i] = id.birlestirilmis[i] - 26;
         }

}
void dosyayaz(){


fp=(fopen("sifrelimetin6.txt","w"));
if(fp==NULL){
    printf("dosya acilamadi..\n");
    exit(1);
}
else{


    fprintf(fp,"%s",id.birlestirilmis);
    fclose(fp);

}}

void enbuyukasal()
{


    while(id.girilenno!=0)
    {
        if(id.girilenno%bolum !=0)
        {
            bolum=bolum+1;
        }
else {
    buyukasal=id.girilenno;
    id.girilenno=id.girilenno/bolum ;}
    if(id.girilenno==1)
    {

    z=1;
    break;

    }


    }
}

void dosyaokuma(){
    char geriokunan[35];
if(buyukasal==asal){
    printf("*****SIFRE DOGRU*****\n");}
    else {
        printf("!!!YANLIS SIFRE GIRDINIZ!!!\n");
        exit (1);
    }

fp=fopen("sifrelimetin6.txt","r");
if(fp==NULL){
    printf("dosyaacilamadi\n");
    exit(1);
}
    else {
            printf("DOSYA ACILDI\n\n\n\n");
            printf("/////////////TOP SECRET\\\\\\\\\\\\\\ \n");
        while(!feof(fp)){
            fgets(id.birlestirilmis,25,fp);
printf("SIFRELENMIS METIN %s\n",id.birlestirilmis);
        }

    }

}


void sezarcozum(){


    for (i = 0; id.birlestirilmis[i] != '\0'; i++)
         {
            id.birlestirilmis[i] = id.birlestirilmis[i] - oteleme;
            if (id.birlestirilmis[i] > 'z')
               id.birlestirilmis[i] = id.birlestirilmis[i] - 26;
         }

printf("SIFRE KAYNAGI: %s\n",id.birlestirilmis);

}






