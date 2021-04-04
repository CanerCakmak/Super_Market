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

			printf("M��terinin Ad�n� Giriniz: ");
			scanf("%s",&ad);
			printf("M��terinin Soyad�n� G�riniz: ");
			scanf("%s",&soyad);
			printf("M��terinin Cep Telefonu Numaras�n� Giriniz (534******* �eklinde):  ");
			scanf("%lld",&num);
			printf("\n\n");
			
			strcpy(mstr[i].isim, ad);
			strcpy(mstr[i].soyisim, soyad);
			mstr[i].numara = num;

			printf("ID\t\t�sim\t\tSoyisim\t\t\tTelefon Numaras�\n");
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
	printf("\t\t\t\t%c%c%c%c%cMarketimize Ho�geldiniz%c%c%c%c%c\n\n",126,126,126,126,126,126,126,126,126,126);
	
	menu:printf("1.M��teri Ekleme\t\t\t2.�r�n Ekleme\n3.Sat��\t\t\t\t\t4.Toplam Sat��lar� G�r�nt�le\n5.Market Hakk�nda Bilgilendirme\t\t6.��k��\n\n");
	printf("L�tfen bir i�lem se�iniz: ");
	scanf("%d",&menu);
	printf("\n\n");
	//Switch i�inde goto deyimi ile ba�a d�nd�rd�m. Men� hemen gelmesin diye de getch fonksiyonunu kulland�m.
	switch(menu) {
		case 1:
			printf("\t\tM��teri Ekleme\n\n");
			
			struct musteri musteribilgi[5];
			musteriekle(musteribilgi,i);
			i++;
			printf("\t\t\tMen�ye Ge�mek ��in Herhangi Bir Tu�a Bas�n�z....\n\n");
			getch();
			goto menu;
			
		case 2:
			printf("�r�n ekleme\n\n");
			printf("\t\t\tMen�ye Ge�mek ��in Herhangi Bir Tu�a Bas�n�z....\n\n");
			getch();
			goto menu;
			
		case 3:
			printf ("Sat��\n\n");
			printf("\t\t\tMen�ye Ge�mek ��in Herhangi Bir Tu�a Bas�n�z....\n\n");
			getch();
			goto menu;
			
		case 4:
			printf("Toplam sat��lar� g�r�nt�le\n\n");
			printf("\t\t\tMen�ye Ge�mek ��in Herhangi Bir Tu�a Bas�n�z....\n\n");
			getch();
			goto menu;
			
		case 5:
			printf("Market hakk�nda bilgilendirme\n\n");
			printf("\t\t\tMen�ye Ge�mek ��in Herhangi Bir Tu�a Bas�n�z....\n\n");
			getch();
			goto menu;
			
		case 6:
			break;
			
		default:
			printf("Bilinmeyen i�lem\n");
			goto menu;
		
	}
	

	

    return 0;
}
