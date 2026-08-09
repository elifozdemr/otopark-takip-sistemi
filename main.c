#include <stdio.h>
#include <string.h>
int gecirilenSure;
int girisSaati;
char plaka[15];
struct araba{
    float girisSaati;
    char plaka[15];
};
void arac_girisi() {
    FILE* fptr;
    fptr=fopen("arac.txt","a");
    if(fptr==NULL) {
        printf("Dosya basarisiz\n");
    }
    else {
        printf("Arac bilgilerini giriniz;\n Giris saati:\n Plaka:\n");
        scanf("%d %s",&girisSaati,plaka);
        fprintf(fptr,"%d %s\n",girisSaati,plaka);
    }
    fclose(fptr);
}
void arac_listele() {
    FILE* fptr;
    fptr=fopen("arac.txt","r");
    if(fptr==NULL) {
        printf("Dosya basarisiz\n");
    }
    else {
        while (fscanf(fptr,"%d %s",&girisSaati,plaka)==2) {
            printf("%d %s\n",girisSaati,plaka);
        }
    }
    fclose(fptr);
}
void ara() {
    char arananPlaka[15];
    int bulundu=0;
    FILE* fptr;
    fptr=fopen("arac.txt","r");
    if(fptr==NULL) {
        printf("Dosya basarisiz\n");
    }
    else {
        printf("Aranan mevcut plakayi giriniz\n");
        scanf("%s",arananPlaka);
        while (fscanf(fptr,"%d %s",&girisSaati,plaka)==2) {
           if (strcmp(plaka,arananPlaka)==0) {
               bulundu=1;
               printf("Aranan plaka bulundu\n");
               break;
           }
        }
        if (bulundu==0) {
            printf("Aranan plaka bulunamadi\n");
        }
    }
    fclose(fptr);
}
void bos_yer_sayisi() {
    int kapasite=100;
    int sayac=0;
    int bosYer;
    FILE* fptr;
    fptr=fopen("arac.txt","r");
    if(fptr==NULL) {
        printf("Dosya basarisiz\n");

    }
    else {
        while (fscanf(fptr,"%d %s\n",&girisSaati,plaka)==2) {
            sayac++;
        }
        bosYer=kapasite-sayac;
        printf("Bos yer sayisi: %d\n",bosYer);
    }
    fclose(fptr);
}
void arac_cikisi() {
    int cikisSaati;
    FILE* fptr;
    fptr=fopen("arac.txt","r");
    if(fptr==NULL) {
        printf("Dosya basarisiz\n");
    }
    else {
        printf("Otoparkta gecirilen sureyi giriniz: ");
        scanf("%d",&gecirilenSure);
        cikisSaati=girisSaati+gecirilenSure;
        printf("Cikis saati: %d\n",cikisSaati);
    }
    fclose(fptr);
}
void toplam_kazanc() {
    float ucret;
    float toplamKazanc;
    FILE* fptr;
    fptr=fopen("arac.txt","r");
    if(fptr==NULL) {
        printf("Dosya basarisiz\n");
    }
    printf("Otoparkta gecirilen sureyi giriniz: ");
    scanf("%d",&gecirilenSure);
    if (gecirilenSure<=1)
        ucret=50;
    else if (gecirilenSure<=2)
        ucret=75;
    else if (gecirilenSure<=3)
        ucret=100;
    else if (gecirilenSure<=4)
        ucret=125;
    else if (gecirilenSure<=5)
        ucret=150;
    else
        ucret=300;
    printf("Odenecek tutar: %.0f\n",ucret);
    while (fscanf(fptr,"%d %s",&girisSaati,plaka)==2) {
        toplamKazanc+=ucret;
        printf("Toplam kazanc: %.0f\n",toplamKazanc);
    }
    fclose(fptr);
}
void cikis() {
    printf("Cikis yapildi\n");
}
int main() {
    int sec;
    do{
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("          ---Arac Takip Sistemi---          \n");
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("1-Arac girisi\n");
    printf("2-Arac listele\n"),
    printf("3-Arac ara\n");
    printf("4-Bos yer sayisi\n");
    printf("5-Arac cikisi\n");
    printf("6-Toplam kazanc\n");
    printf("7-Cikis\n");
        printf("1-7 arasinda bir secim yapiniz: ");
        scanf("%d",&sec);
        switch (sec) {
            case 1:arac_girisi();
                break;
                case 2:arac_listele();
                break;
                case 3:ara();
                break;
                case 4:bos_yer_sayisi();
                break;
                case 5:arac_cikisi();
                break;
                case 6:toplam_kazanc();
                break;
                case 7:cikis();
                break;
        }
}while (sec != 7);
    return 0;
}