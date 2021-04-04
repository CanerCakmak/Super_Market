#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
struct musteri{
	char isim[20];
	char soyisim[20];
	long long int numara;
};
struct urun{
    int urunid;
    char urunisim[20];
    int urunkategori;
    int urunadet;
    int urunfiyat;
};

void musteriekle(struct musteri mstr[], int i){
	// �ki tane m��teri tan�mlad�m. Ard�ndan eklenecek m��terilerin bilgilerini ald�r�p d�ng�de b�t�n m��terileri yazd�rd�m.
		char ad[20];
		char soyad[20];
		long long int num;
		int k;

		strcpy(mstr[0].isim,"Furkan");
		strcpy(mstr[0].soyisim,"Serbest");
		mstr[0].numara = 5328427845;

		strcpy(mstr[1].isim,"Murat");
		strcpy(mstr[1].soyisim,"Denerel");
		mstr[1].numara = 5429644661;

			printf("Musterinin Adini Giriniz: ");
			scanf("%s",&ad);
			printf("Musterinin Soyadini Giriniz: ");
			scanf("%s",&soyad);
			printf("Musterinin Cep Telefonu Numarasini Giriniz (534******* seklinde):  ");
			scanf("%lld",&num);
			printf("\n\n");

			strcpy(mstr[i].isim, ad);
			strcpy(mstr[i].soyisim, soyad);
			mstr[i].numara = num;

			printf("ID\t\tIsim\t\tSoyisim\t\t\tTelefon Numarasi\n");
		for(k=0; k<=i; k++){
			printf("---------------------------------------------------------------------------\n");
			printf("%d\t\t%s\t\t%s\t\t\t%lld\n",k+1,mstr[k].isim,mstr[k].soyisim,mstr[k].numara);
		}
		printf("\n\n");


}

   void urunekle(struct urun urn[],int t,int l){

    int urnid;
    char urnad[20];
    int urnktgr;
    int urnadet=0;
    int urnfiyat;
    int z;

    urn[0].urunid = 1;
    strcpy(urn[0].urunisim,"Kazak");
    urn[0].urunkategori = 1;
    urn[0].urunadet = 20;
    urn[0].urunfiyat = 40;

    urn[1].urunid = 2;
    strcpy(urn[1].urunisim,"Telefon");
    urn[1].urunkategori = 2;
    urn[1].urunadet = 10;
    urn[1].urunfiyat = 5000;

    urn[2].urunid = 3;
    strcpy(urn[2].urunisim,"Koltuk");
    urn[2].urunkategori = 3;
    urn[2].urunadet = 5;
    urn[2].urunfiyat = 8000;

    urn[3].urunid = 4;
    strcpy(urn[3].urunisim,"Sunger");
    urn[3].urunkategori = 4;
    urn[3].urunadet = 20;
    urn[3].urunfiyat = 5;

    urn[4].urunid = 5;
    strcpy(urn[4].urunisim,"Ekmek");
    urn[4].urunkategori = 5;
    urn[4].urunadet = 30;
    urn[4].urunfiyat = 1;

    printf("Eklemek istediginiz urunun kodunu giriniz (sadece sayi kullaniniz):  ");
    scanf("%d",&urnid);
    printf("Eklemek istediginiz urunun adetini giriniz):  ");
    scanf("%d",&urnadet);


        for(z=0; z<=t; z++)
        {
        if(urnid==urn[z].urunid)
            {
            urn[z].urunadet = urnadet + urn[z].urunadet;
            l--;
            t--;
            goto bitis;
            }
        }


            printf("Eklemek istediginiz urunun ismini giriniz: ");
            scanf("%s",&urnad);
            printf("Eklemek istediginiz urunun kategorisini giriniz(1=giyim 2=elektronik 3=mobilya 4=temizlik 5=gıda):   ");
            scanf("%d",&urnktgr);
            printf("Eklemek istediginiz urunun Fiyatını giriniz:  ");
            scanf("%d",&urnfiyat);

            urn[t].urunid = urnid;
            strcpy(urn[t].urunisim, urnad);
            urn[t].urunkategori = urnktgr;
            urn[t].urunadet = urnadet;
            urn[t].urunfiyat = urnfiyat;

         bitis: printf("Urun eklenmistir.\n\n");




        printf("Urun ID\t\tUrun Ad\t\tUrun Kategori\t\tUrun Adet\t\tUrun Fiyat\n");
		for(z=0; z<=l; z++){
			printf("--------------------------------------------------------------------------------------------------------------------\n");
			printf("%.4d\t\t%s\t\t\t%d\t\t  %d\t\t\t%d\n",urn[z].urunid,urn[z].urunisim,urn[z].urunkategori,urn[z].urunadet,urn[z].urunfiyat);
		}
		printf("\n\n");

   }
int main()
{

	setlocale(LC_ALL, "Turkish");

	int menu,i,t,l;
	i=2;
	t=5;
	l=5;
	printf("\t\t\t\t%c%c%c%c%cMarketimize Hosgeldiniz%c%c%c%c%c\n\n",126,126,126,126,126,126,126,126,126,126);

	menu:printf("1.Musteri Ekleme\t\t\t2.Urun Ekleme\n3.Satis\t\t\t\t\t4.Toplam Satislari Goruntule\n5.Market Hakkinda Bilgilendirme\t\t6.Cikis\n\n");
	printf("Lutfen bir islem seciniz: ");
	scanf("%d",&menu);
	printf("\n\n");
	//Switch i�inde goto deyimi ile ba�a d�nd�rd�m. Men� hemen gelmesin diye de getch fonksiyonunu kulland�m.
	switch(menu) {
		case 1:
			printf("\t\tMusteri Ekleme\n\n");

			struct musteri musteribilgi[5];
			musteriekle(musteribilgi,i);
			i++;
			printf("\t\t\tMenuye Gecmek icin Herhangi Bir Tusa Basiniz....\n\n");
			getch();
			goto menu;

		case 2:
			printf("Urun ekleme\n\n");
			struct urun urunler[8];
			urunekle(urunler,t,l);
			t++;
			l++;
			printf("\t\t\tMenuye Gecmek icin Herhangi Bir Tusa Basiniz....\n\n");
			getch();
			goto menu;

		case 3:
			printf ("Satis\n\n");
			printf("\t\t\tMenuye Gecmek icin Herhangi Bir Tusa Basiniz....\n\n");
			getch();
			goto menu;

		case 4:
			printf("Toplam satislari goruntule\n\n");
			printf("\t\t\tMenuye Gecmek icin Herhangi Bir Tusa Basiniz....\n\n");
			getch();
			goto menu;

		case 5:
			printf("Market hakkinda bilgilendirme\n\n");
			printf("\t\t\tMenuye Gecmek icin Herhangi Bir Tusa Basiniz....\n\n");
			getch();
			goto menu;

		case 6:
			break;

		default:
			printf("Bilinmeyen islem\n");
			goto menu;

	}




    return 0;
}
