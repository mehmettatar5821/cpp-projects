#include<stdio.h>
#include<conio.h> 
 void sifrele(char dizi[],int kural);
   void sifrecoz(char dizi[],int kural);
   int i;
   void sifrele(char dizi[],int kural){
       for(i=0;dizi[i];i++){
        dizi[i]+= kural;
       }
   }
   void sifrecoz(char dizi[],int kural){
   for(i=0;dizi[i];i++){
    dizi[i] -= kural;
   }
   }
int main()
{
    char cumle[150];
    int sec,kar;
    printf("Sifrelemek icin ->1\nSifre Cozmek icin ->2\nLutfen islem turunu seciniz:");
    scanf("%d",&sec);
if(sec == 1){
    printf("Cumlenizi giriniz: ");
    getchar();
    gets(cumle);
    //fgets(cumle,sizeof(cumle),stdin);
    printf("Kac karaktere gore sifrelensin ? :");
    scanf("%d",&kar);
    sifrele(cumle,kar);
    printf(cumle);

} else if(sec == 2){

    printf("Cumlenizi giriniz:");
    getchar();
    gets(cumle);
    printf("Kac karaktere gore cozulmeli ? :");
    scanf(" %d",&kar);
    sifrecoz(cumle,kar);
    printf(cumle);
}else {
    printf("Hatali secim.");
    }

    return 0;
}
