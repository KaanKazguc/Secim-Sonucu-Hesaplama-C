#include <stdio.h>

void diziSifirlayici(int nereyeKadarSifirlanacak,int dizi[nereyeKadarSifirlanacak])
{                                                           /***********************/
    int i;                                                  /**  Uzerine ekleme   **/
    for(i=0;i<nereyeKadarSifirlanacak;i++)                  /**yapilacak dizilerin**/
  {                                                         /**  baslangiclarini  **/
    dizi[i]=0;                                              /**  0'a esitliyoruz. **/
  }                                                         /***********************/
}

int enBuyukBulucu(int elemanSayisi,int elemanlar[elemanSayisi])
{
    int sayac=0,enBuyuk=0;                  /************************/
    while(sayac<elemanSayisi)               /**  Gonderilen dizin  **/
        {                                   /**   tum elemanlari   **/
          if(elemanlar[sayac]>enBuyuk)      /** arasindan en buyuk **/
          enBuyuk=elemanlar[sayac];         /**  olani buluyoruz   **/
          sayac++;                          /**      ve sonuc      **/
        }                                   /**olarak gonderiyoruz.**/
        return enBuyuk;                     /************************/
}


void siralayici(int partiSayisi,int siralanacak[partiSayisi],int sira[partiSayisi])
{
int enBuyuk,sayac=0,sayac1=0,k,siralanacakYedek[partiSayisi],partiSayisiYedek=partiSayisi;

      for(k=0;k<partiSayisi;k++)
      {
        siralanacakYedek[k]=siralanacak[k];
      }
while(partiSayisiYedek>0)
    {
        enBuyuk=enBuyukBulucu(partiSayisi,siralanacakYedek);
        sayac=0;
        while(sayac<partiSayisi)                 /******************************/
        {                                        /**     En buyuk degeri      **/
            if(siralanacakYedek[sayac]==enBuyuk) /**     ilk siraya kayit     **/
            {                                    /**ediyoruz. Sonra eksi bire **/
              sira[sayac1]=sayac;                /**   esitliyoruz sonraki    **/
              siralanacakYedek[sayac]=-1;        /**  buyuk degeri 2.siraya   **/
              partiSayisiYedek--;                /**   kayit ediyoruz ve bu   **/
              sayac1++;                          /**   islem tum elemanlar    **/
            }                                    /**    icin tekrarliyoruz    **/
            sayac++;                             /******************************/
        }
	}

}


int main ()
{
  int partiSayisi,ilSayisi;

  printf("Secime katilacak parti sayisini girin:");
  scanf("%d",&partiSayisi);
  while(partiSayisi<=0)
       {
        printf("Lutfen gecerli bir deger girin\n");
        printf ("Secime katilacak parti sayisini girin:");
        scanf ("%d", &partiSayisi);
       }
  printf("Secime katilacak il sayisini girin:");
  scanf("%d",&ilSayisi);
  printf("\n");
  while(ilSayisi<=0)
       {
        printf("Lutfen gecerli bir deger girin\n");
        printf ("Secime katilacak il sayisini girin:");
        scanf ("%d", &ilSayisi);
        printf("\n");
       }
  ilSayisi++; /**1.illin bilgilerini[1]'den baslayarak kaydetmek ve [0]'a ulke genelini atayabilmek icin ilSayisini bir arttiriyoruz.**/

  int oy[ilSayisi][partiSayisi] , oyYedek[ilSayisi][partiSayisi] , mvSayisi[ilSayisi][partiSayisi+1];
  int kontenjan[ilSayisi] , kontenjanYedek[ilSayisi] , toplam[ilSayisi];
  int il=1 , sayac , enBuyuk , birincilik[partiSayisi] , sira[partiSayisi] , i;
  double yuzde , yuzde1;
  char dogru='a',parti[25] = {' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','U','V','Y','Z',' '};
  toplam[0]=0,kontenjan[0]=0; /**sonradan uzerine ekleme yapacagimiz degerlerin baslangicini sifira esitliyoruz.**/

 diziSifirlayici(partiSayisi,birincilik);
 diziSifirlayici(partiSayisi,oy[0]);
 diziSifirlayici(partiSayisi+1,mvSayisi[0]);

  while (il < ilSayisi)
    {while(dogru!='E')
    {
      sayac = 0;
      printf ("%d.ilin bilgilerini giriyorsunuz\n", il);
      printf ("Milletvekili kontenjanini girin:");
      scanf ("%d", &kontenjan[il]);
      while(kontenjan[il]<=0)
       {
        printf("Lutfen gecerli bir deger girin\n");
        printf ("%d.ilin milletvekili kontenjanini giriniz:",il);
        scanf ("%d", &kontenjan[il]);
       }
      kontenjanYedek[il]=kontenjan[il];
      toplam[il]=0;
      while (sayac < partiSayisi)
	{                                                             /******************************/
	  printf ("%c%c ",parti[sayac/22],parti[(sayac%22)+1]);       /**   Partilerin oylarini    **/
	  printf ("partisinin aldigi gecerli oy sayisini girin:");    /**    kullanicidan alip     **/
	  scanf ("%d", &oy[il][sayac]);                               /**ileride isimize yarayacak **/
	  while(oy[il][sayac]<0)                                      /**  degiskenlere atiyoruz   **/
       {                                                          /**   ve bulundugumuz ilin   **/
        printf("Lutfen gecerli bir deger girin\n");               /**toplam oyunu hesapliyoruz.**/
        printf ("%c%c ",parti[sayac/22],parti[(sayac%22)+1]);     /******************************/
        printf ("partisinin aldigi gecerli oy sayisini girin:");
        scanf ("%d", &oy[il][sayac]);
       }
	  mvSayisi[il][sayac]=0;
      toplam[il]+=oy[il][sayac];
	  oyYedek[il][sayac]=oy[il][sayac];
	  sayac++;
    }

    siralayici(partiSayisi,oy[il],sira);

	while(kontenjanYedek[il]>0)                           /*************************/
        {                                                 /** Ilin milletvekili   **/
        sayac=0;                                          /** kontenjani oldugu   **/
        enBuyuk=enBuyukBulucu(partiSayisi,oyYedek[il]);   /**  surece en buyuk    **/
        while(sayac<partiSayisi)                          /**   oyu olan parti    **/
        {                                                 /**       bulunur.      **/
            if(oyYedek[il][sayac]==enBuyuk)               /**Oyu yariya indirilir.**/
            {                                             /**Milletvekili sayisi  **/
              oyYedek[il][sayac]/=2;                      /**   bir arttirilir.   **/
              mvSayisi[il][sayac]++;                      /**  Ilin kontenjani    **/
              kontenjanYedek[il]--;                       /**   bir azaltilir.    **/
            }                                             /*************************/
            sayac++;
        }
	}
	if(kontenjanYedek[il]<0) /**degerlendirme sirasinda partilerin oylari esit ise kontenjandan fazla milletvekili cikabilir.**/
	printf("\nUYARI secimde esitlik soz konusu secim tekrari gerekir!");
	printf("\n\t\t\t\t%d.Ilin Sonuclari\nToplam gecerli oy=%d\nMilletvekili kontenjani:%d\n",il,toplam[il],kontenjan[il]);
	printf("\t\tOy Sayisi\tOy Yuzdesi\tMV Sayisi\n");
	printf("\t\t---------\t----------\t---------");
	sayac=0;
	while(sayac<partiSayisi)
    {
        yuzde=oy[il][sira[sayac]]; /**yuzde sonuc hesaplayabilmek icin integer degerleri double'a kopyaliyoruz.**/
        printf("\n%c%c Partisi \t",parti[sira[sayac]/22],parti[(sira[sayac]%22)+1]);
        printf("   %d\t\t  %.2f\t\t    %d",oy[il][sira[sayac]],(100*yuzde)/toplam[il],mvSayisi[il][sira[sayac]]);
        sayac++;
    }
      if(kontenjanYedek[il]<0)
	printf("\n\nUYARI secimde esitlik soz konusu secim tekrari gerekir!\n\n");

      printf("\n\nDegerleri dogru girdiyseniz 'E'harfini yanlis girdiyseniz herhangibir degeri tuslayin:");         /****************/
      scanf(" %c",&dogru);                                                                                          /** Kullanici  **/
      if(dogru=='e') dogru='E';                                                                                     /**hatali deger**/
        if(dogru!='E')                                                                                              /** girmis ise **/
        {                                                                                                           /**tekrar girme**/
            printf("\nEminmisiniz? Bu islem bulundugunuz ilin tum degerleri tekrar girmenize neden olacak.\n");     /**   imkani   **/
            printf("Degerleri tekrar girmek istiyorsaniz 'E' harfini istemiyorsaniz herhangibir degeri tuslayin:"); /** taniyoruz. **/
            scanf(" %c",&dogru);                                                                                    /****************/
            if(dogru=='e') dogru='E';
            if(dogru=='E') dogru='a';
            else
                dogru='E';

        }
      printf("\n");
    }
    dogru='a';
    sayac=0;
      while(sayac<partiSayisi)
        {
          if(oy[il][sayac]==oy[il][sira[0]])
          birincilik[sayac]++;
          sayac++;
        }
      toplam[0]+=toplam[il];  /**tum illerin toplam oyunu toplam[0]'a kayit ediyoruz**/
      kontenjan[0]+=kontenjan[il]; /**tum illerin toplam kontejanini kontenjan[0]'a kayit ediyoruz**/
      sayac=0;
      while(sayac<partiSayisi)                              /***********************************************/
      {                                                     /** Kullanici ilin degerlerini dogruladiktan  **/
        oy[0][sayac]+=oy[il][sayac];                        /**    sonra partilerin bulunulan ildeki      **/
        mvSayisi[0][sayac]+=mvSayisi[il][sayac];            /**     sonucunu ulke geneline ekliyoruz.     **/
                                                            /***********************************************/
        mvSayisi[0][partiSayisi]+=mvSayisi[il][sayac]; /**tum illerdeki milletvekili sayisinin toplamini hesapliyoruz cunku**/
        sayac++;                                       /**kontenjan ile milletvekili sayisi ayni olmayabilir.**/
      }
      il++;
    }
    printf("\t\t\t\t*************Ulke Geneli*************");
    printf("\nToplam Gecerli Oy:%d\nMilletvekili Kontenjani:%d\n",toplam[0],kontenjan[0]);
    printf("\t\tOy Sayisi\tOy Yuzdesi\tMV Sayisi\tMV Yuzdesi\t1.oldugu il sayisi\n");
    printf("\t\t---------\t----------\t---------\t---------\t-------------------");
    siralayici(partiSayisi,mvSayisi[0],sira);
    for(i=0;i<partiSayisi;i++)
    {
        yuzde=mvSayisi[0][sira[i]]; /**yuzde sonuc hesaplayabilmek icin integer degerleri double'a kopyaliyoruz.**/
        yuzde1=oy[0][sira[i]]; /**yuzde sonuc hesaplayabilmek icin integer degerleri double'a kopyaliyoruz.**/
      printf("\n%c%c Partisi\t%d\t\t%.2f\t\t%.d\t\t%.2f\t\t%d",parti[sira[i]/22],parti[(sira[i]%22)+1],oy[0][sira[i]],100*yuzde1/toplam[0],mvSayisi[0][sira[i]],100*yuzde/mvSayisi[0][partiSayisi],birincilik[sira[i]]);
    if(i==0) printf("  ===> Ikdidar");
    if(i==1) printf("  ===> Ana muhalefet");}
    printf("\n\nUygulamayi X'e tiklayarak kapatabilirsiniz.\nBu bolgeyi not defteri olarak kullanabilirsiniz.\n");
    while(1){scanf("%s",parti);}
  return 1;
}
