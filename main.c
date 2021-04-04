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

void musteriekle(struct musteri mstr[], int i){
	// Ýki tane müþteri tanýmladým. Ardýndan eklenecek müþterilerin bilgilerini aldýrýp döngüde bütün müþterileri yazdýrdým.
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

			printf("Müþterinin Adýný Giriniz: ");
			scanf("%s",&ad);
			printf("Müþterinin Soyadýný GÝriniz: ");
			scanf("%s",&soyad);
			printf("Müþterinin Cep Telefonu Numarasýný Giriniz (534******* Þeklinde):  ");
			scanf("%lld",&num);
			printf("\n\n");
			
			strcpy(mstr[i].isim, ad);
			strcpy(mstr[i].soyisim, soyad);
			mstr[i].numara = num;

			printf("ID\t\tÝsim\t\tSoyisim\t\t\tTelefon Numarasý\n");
		for(k=0; k<=i; k++){
			printf("---------------------------------------------------------------------------\n");
			printf("%d\t\t%s\t\t%s\t\t\t%lld\n",k+1,mstr[k].isim,mstr[k].soyisim,mstr[k].numara);
		}
		printf("\n\n");
			
	
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	
	int menu,i;
	i=2;
	printf("\t\t\t\t%c%c%c%c%cMarketimize Hoþgeldiniz%c%c%c%c%c\n\n",126,126,126,126,126,126,126,126,126,126);
	
	menu:printf("1.Müþteri Ekleme\t\t\t2.Ürün Ekleme\n3.Satýþ\t\t\t\t\t4.Toplam Satýþlarý Görüntüle\n5.Market Hakkýnda Bilgilendirme\t\t6.Çýkýþ\n\n");
	printf("Lütfen bir iþlem seçiniz: ");
	scanf("%d",&menu);
	printf("\n\n");
	//Switch içinde goto deyimi ile baþa döndürdüm. Menü hemen gelmesin diye de getch fonksiyonunu kullandým.
	switch(menu) {
		case 1:
			printf("\t\tMüþteri Ekleme\n\n");
			
			struct musteri musteribilgi[5];
			musteriekle(musteribilgi,i);
			i++;
			printf("\t\t\tMenüye Geçmek Ýçin Herhangi Bir Tuþa Basýnýz....\n\n");
			getch();
			goto menu;
			
		case 2:
			printf("Ürün ekleme\n\n");
			printf("\t\t\tMenüye Geçmek Ýçin Herhangi Bir Tuþa Basýnýz....\n\n");
			getch();
			goto menu;
			
		case 3:
			printf ("Satýþ\n\n");
			printf("\t\t\tMenüye Geçmek Ýçin Herhangi Bir Tuþa Basýnýz....\n\n");
			getch();
			goto menu;
			
		case 4:
			printf("Toplam satýþlarý görüntüle\n\n");
			printf("\t\t\tMenüye Geçmek Ýçin Herhangi Bir Tuþa Basýnýz....\n\n");
			getch();
			goto menu;
			
		case 5:
			printf("Market hakkýnda bilgilendirme\n\n");
			printf("\t\t\tMenüye Geçmek Ýçin Herhangi Bir Tuþa Basýnýz....\n\n");
			getch();
			goto menu;
			
		case 6:
			break;
			
		default:
			printf("Bilinmeyen iþlem\n");
			goto menu;
		
	}
	

	
    return 0;
}
