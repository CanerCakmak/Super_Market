#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
typedef struct{
	int gun;
	int ay;
	int yil;
}tarih;
struct musteri{
	char isim[20];
	char soyisim[20];
	int id;
	long long int numara;
};
struct urun{
    int urunid;
    char urunisim[20];
    int urunkategori;
    int urunadet;
    int urunfiyat;
};
struct satis{
	int saturnid;
	int satmstrid;
	int satadet;
	tarih trh;
};

void musteriekle(struct musteri mstr[], int i){

		char ad[20];
		char soyad[20];
		long long int num;
		int k;

		strcpy(mstr[0].isim,"Furkan");
		strcpy(mstr[0].soyisim,"Serbest");
		mstr[0].numara = 5328427845;
		mstr[0].id = 1;

		strcpy(mstr[1].isim,"Murat");
		strcpy(mstr[1].soyisim,"Denerel");
		mstr[1].numara = 5429644661;
		mstr[1].id = 2;

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
			mstr[i].id = mstr[i-1].id + 1;

			printf("ID\t\tIsim\t\tSoyisim\t\t\tTelefon Numarasi\n");
		for(k=0; k<=i; k++){
			printf("---------------------------------------------------------------------------\n");
			printf("%d\t\t%s\t\t%s\t\t\t%lld\n",mstr[k].id,mstr[k].isim,mstr[k].soyisim,mstr[k].numara);
		}
		printf("\n\n");


}

   void urunekle(struct urun urn[],int *x,int *y){

    int urnid;
    char urnad[20];
    int urnktgr;
    int urnadet=0;
    int urnfiyat;
    int z;
    int o;
    int p;

    printf("Eklemek istediginiz urunun kodunu giriniz (sadece sayi kullaniniz):  ");
    scanf("%d",&urnid);
    printf("Eklemek istediginiz urunun adetini giriniz:  ");
    scanf("%d",&urnadet);


        for(z=0; z<=*y; z++)
        {
        if(urnid==urn[z].urunid)
            {

            urn[z].urunadet = urnadet + urn[z].urunadet;



            printf("Urun ID\t\tUrun Ad\t\tUrun Kategori\t\tUrun Adet\t\tUrun Fiyat\n");
		for(z=0; z<=*x; z++){
			printf("--------------------------------------------------------------------------------------------------------------------\n");
			printf("%.4d\t\t%s\t\t\t%d\t\t  %d\t\t\t%d\n",urn[z].urunid,urn[z].urunisim,urn[z].urunkategori,urn[z].urunadet,urn[z].urunfiyat);
		}
		printf("\n\n");

            goto bitis;

            }
        }


            printf("Eklemek istediginiz urunun ismini giriniz: ");
            scanf("%s",&urnad);
            printf("Eklemek istediginiz urunun kategorisini giriniz(1=giyim 2=elektronik 3=mobilya 4=temizlik 5=gÄ±da):   ");
            scanf("%d",&urnktgr);
            printf("Eklemek istediginiz urunun fiyatini giriniz:  ");
            scanf("%d",&urnfiyat);

            urn[*y].urunid = urnid;
            strcpy(urn[*y].urunisim, urnad);
            urn[*y].urunkategori = urnktgr;
            urn[*y].urunadet = urnadet;
            urn[*y].urunfiyat = urnfiyat;
			*y = *y + 1;
            *x = *x + 1;

         printf("Urun ID\t\tUrun Ad\t\tUrun Kategori\t\tUrun Adet\t\tUrun Fiyat\n");
		for(z=0; z<=*x; z++){
			printf("--------------------------------------------------------------------------------------------------------------------\n");
			printf("%.4d\t\t%s\t\t\t%d\t\t  %d\t\t\t%d\n",urn[z].urunid,urn[z].urunisim,urn[z].urunkategori,urn[z].urunadet,urn[z].urunfiyat);
		}
		printf("\n\n");
         bitis: printf("Urun eklenmistir.\n\n");


   }
   void urunsatma(struct urun urn[],struct satis urunsatma[],struct musteri mstr[],int l,int k){


	int z;
	printf("Satilan Urunun ID Numarasini Giriniz: ");
	scanf("%d",&urunsatma[k].saturnid);
	printf("Satin Alan Musterinin ID Numarasini Giriniz: ");
	scanf("%d",&urunsatma[k].satmstrid);
	printf("Urunun Satildigi Tarihi Giriniz(gun ay ve yil arasinda bir bosluk birakiniz): ");
	scanf("%d %d %d",&urunsatma[k].trh.gun,&urunsatma[k].trh.ay,&urunsatma[k].trh.yil);
	printf("Kac Adet Satin Alinmistir: ");
	scanf("%d",&urunsatma[k].satadet);

	for(z=3;z<=l;z++){
		if(urunsatma[k].saturnid==urn[z].urunid){
			urn[z].urunadet=urn[z].urunadet-urunsatma[k].satadet;
		}
	}

	printf("Urun ID\t\tUrun Ad\t\tUrun Kategori\t\tUrun Adet\t\tUrun Fiyat\n");
		for(z=0; z<=l; z++){
			printf("--------------------------------------------------------------------------------------------------------------------\n");
			printf("%.4d\t\t%s\t\t\t%d\t\t  %d\t\t\t%d\n",urn[z].urunid,urn[z].urunisim,urn[z].urunkategori,urn[z].urunadet,urn[z].urunfiyat);
		}
		printf("\n\n");

		for(z=0;z<=l;z++){
		if(urn[z].urunadet<10){
			printf("Uyarý: %d ID Numarasina sahip urunun stogu 10'un altýna dusmustur.\n",z+1);
		}
	}
}
void toplamsatis(struct urun urn[],struct satis urunsatma[],struct musteri mstr[],int l,int k){
	tarih kontrol;
	int z;
	int tutar=0;
	printf("Tarih giriniz (gun ay ve yil arasinda bir bosluk birakiniz): ");
	scanf("%d %d %d",&kontrol.gun,&kontrol.ay,&kontrol.yil);
	
	printf("Urun ID\t\tMusteri Adý\t\t\tTarih\t\t\tAdet\t\tFiyat\n");
	for(z=0;z<k;z++){
		if(kontrol.gun==urunsatma[z].trh.gun && kontrol.ay==urunsatma[z].trh.ay && kontrol.yil==urunsatma[z].trh.yil){
			
			printf("--------------------------------------------------------------------------------------------------------------------\n");
			printf("%.4d\t\t%s %s\t\t\t%d.%d.%d\t\t%d\t\t",urunsatma[z].saturnid,mstr[urunsatma[z].satmstrid-1].isim,mstr[urunsatma[z].satmstrid-1].soyisim,urunsatma[z].trh.gun,urunsatma[z].trh.ay,urunsatma[z].trh.yil,urunsatma[z].satadet);
		
			
			for(i=0;i<=l;i++){
				if(urunsatma[z].saturnid==urn[i].urunid){
					printf("%d\n",urn[i].urunfiyat);
					tutar += urn[i].urunfiyat * urunsatma[z].satadet;
				}
		}
		
	}
	
		}
	
	printf("Toplam Satis: %d TL",tutar);
	printf("\n\n");
		


	
}
   void bilgilendirme(){

   printf("ABC Martketleri olarak Asya, Avrupa ve Kuzey Amerika kitalarinda Turkiye, Almanya, Kanada, Cin ve Guney Kore ulkelerinde hizmet vermekteyiz.\n\n");
   printf("\t\t\tAvrupa Kitasi Temsilcileri\n\tTurkiye\t\t\t\t\t\tAlmanya\n");
   printf("--------------------------------------------------------------------------------------------------------------------\n");
   printf("Istanbul: Alý Tas\t\t\t\tBerlin: Damian Berthes\nIzmir: Ahmet Akbunar\t\t\t\tMunih: Hans Tuchel\nAnkara: Zeynep Özdemir\t\t\t\tDortmund: Emma Reus\n\n");
   printf("\t\t\tAsya Kitasi Temsilcileri\n\tCin\t\t\t\t\t\tGuney Kore\n");
   printf("--------------------------------------------------------------------------------------------------------------------\n");
   printf("Pekin: Wu Peiliang\t\t\t\tBusan: Kim Sun-Ho\nShanghai: Chen Haoyang\t\t\t\tSeul: Cho Seon-Woo\nWuhan: Lin Jinping\t\t\t\tDaegu: Yoo Min-Seok\n\n");
	printf("\t\t\tKuzey Amerika Kitasi Temsilcileri\n\tKanada\n");
   printf("--------------------------------------------------------------------------------------------------------------------\n");
   printf("Toronto: Cyle Lovato\nMontreal: Atiba Hutchinson\nVancouver: Hannah Brown\n\n");

}
int main()
{

	setlocale(LC_ALL, "Turkish");

	int menu,i,t,l,k;
	k=3;
	i=2;
	t=5;
	l=4;
	
	struct musteri musteribilgi[5];
	strcpy(musteribilgi[0].isim,"Furkan");
	strcpy(musteribilgi[0].soyisim,"Serbest");
	musteribilgi[0].numara = 5328427845;
	musteribilgi[0].id = 1;

	strcpy(musteribilgi[1].isim,"Murat");
	strcpy(musteribilgi[1].soyisim,"Denerel");
	musteribilgi[1].numara = 5429644661;
	musteribilgi[1].id = 2;

	struct urun urn[10];
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

	struct satis urnsat[10];
	urnsat[0].saturnid=1;
	urnsat[0].satmstrid=1;
	urnsat[0].satadet=2;
	urnsat[0].trh.gun=17;
	urnsat[0].trh.ay=03;
	urnsat[0].trh.yil=2021;
	urn[0].urunadet = urn[0].urunadet - urnsat[0].satadet
	
	urnsat[1].saturnid=3;
	urnsat[1].satmstrid=2;
	urnsat[1].satadet=1;
	urnsat[1].trh.gun=17;
	urnsat[1].trh.ay=03;
	urnsat[1].trh.yil=2021;
	urn[2].urunadet = urn[2].urunadet - urnsat[1].satadet
	
	urnsat[2].saturnid=4;
	urnsat[2].satmstrid=1;
	urnsat[2].satadet=5;
	urnsat[2].trh.gun=17;
	urnsat[2].trh.ay=03;
	urnsat[2].trh.yil=2021;
	urn[3].urunadet = urn[3].urunadet - urnsat[2].satadet
	
	printf("\t\t\t\t%c%c%c%c%cMarketimize Hosgeldiniz%c%c%c%c%c\n\n",126,126,126,126,126,126,126,126,126,126);

	menu:printf("1.Musteri Ekleme\t\t\t2.Urun Ekleme\n3.Satis\t\t\t\t\t4.Toplam Satislari Goruntule\n5.Market Hakkinda Bilgilendirme\t\t6.Cikis\n\n");
	printf("Lutfen bir islem seciniz: ");
	scanf("%d",&menu);
	printf("\n\n");

	switch(menu) {
		case 1:
			printf("\t\tMusteri Ekleme\n\n");

			
			musteriekle(musteribilgi,i);
			i++;
			printf("\t\t\tMenuye Gecmek icin Herhangi Bir Tusa Basiniz....\n\n");
			getch();
			goto menu;

		case 2:
			printf("Urun ekleme\n\n");
			urunekle(urn,&l,&t);

			printf("\t\t\tMenuye Gecmek icin Herhangi Bir Tusa Basiniz....\n\n");
			getch();
			goto menu;

		case 3:
			printf ("\t\tSatis\n");
			printf("\t---------------------\n\n");
			
			urunsatma(urn,urnsat,musteribilgi,l,k);
			k++;
			printf("\t\t\tMenuye Gecmek icin Herhangi Bir Tusa Basiniz....\n\n");
			getch();
			goto menu;

		case 4:
			printf ("\t\tToplam satislari goruntule\n");
			printf("\t   -----------------------------------\n\n");
			toplamsatis(urn,urnsat,musteribilgi,l,k);
			printf("\t\t\tMenuye Gecmek icin Herhangi Bir Tusa Basiniz....\n\n");
			getch();
			goto menu;

		case 5:
			printf ("\t\tMarket hakkinda bilgilendirme\n");
			printf("\t   ---------------------------------------\n\n");
			bilgilendirme();
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
