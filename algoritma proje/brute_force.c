/*
 * isimsiz.c

 * 
 */


#include <stdio.h>
#include<math.h>
#include <time.h>
#include <unistd.h> 

int main(int argc, char **argv)
{
	//çalışma zamanı:
	 double time_spent = 0.0;
 
    clock_t begin = clock();
 
    // do some stuff here
    sleep(3);
 
    clock_t end = clock();
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds", time_spent);
    
    
	int distance[]={824,695,318,951,35,439,382,766,796,187};//ilk deger merkeze uzaklık diğer değerler istasyonlar arasındaki uzaklık
	int profit[]={37,42,5,57,11,56,96,65,34,7};
	int distance_size =(sizeof(distance)/sizeof(distance[0]));//distance dizimizin uzunluğu aynı zamanda profit dizisinin de uzunluğu
	int x=500;//istasyonlar arası mesafe ne kadar olmalı
	int b=0,k=distance_size-1;//b ve k dğerleri her bir istasyon için kaç durum varsa içerdeki dongü o kadar dönsün 
	int a=distance_size-1,t=0,z=0;//tüm olasılıklara bakması için oluşturduğumuz değişkenler
	int max=profit[0];//maxa ilk istasyondaki karımızı atadık.Her durumda seçtiğimşz istasyonun karını buna atayıp maximum profit ile karşılaştırırız.
	int max_profit=max;//max karı verir.
	int toplam=0,toplam1=0,toplam2=0;//seçilen istasyonla bir sonraki istasyonun arasındaki toplam uzaklıkları tutar.
	
	
	
	
	
	for(int i=0; i<distance_size; i++){//birden sona kadar bütün istasyonlara bak 
		max=profit[i];//her seferinde seçtiğimiz istasyonun uzunluğunu max atadık
		int j=i+1;
		
	 while(j<distance_size){//o anki seçtiğimiz istasyon ile oluşucak bütün kombinasyonları hesapla ve maximum karı max_profite ata.
		 
		 if((toplam1+distance[j])>=x && t==0){//eğer uzaklık en az x kadar ise ve atlamadan gitmek için t= 0 ise  mesela 1-2-3 diye sırayla gidiyorsak veya 2-3-4
			 max=max+profit[j];//o anki seçtiğimiz istayonun karını ekle
			 z=toplam1;//z ye toplamı atadık ki bir sonraki ife girmesin diye
             toplam1=0;
		 }
		 if( t==0 && (z+distance[j])<x){//eger uzaklık en az x kadar değilse bir sonraki istasyonla olan uzaklığı hesaplamak için o anki iki istasyon arasındaki uzaklıkları toluyoruz
			 toplam1=toplam1+distance[j];
			
		 }
		
		  z=0;
		 if( j+b<distance_size){
		   if((toplam+distance[j]+distance[j+b])>=x && t==1 && j==i+1){//eğer uzaklık en az x ise ve atlayarak gideceksek  yani 1-3-4-5 ya da 1-4-5 ve atlayarak gittiğimiz için bir sonraki istasyonla olan uzaklığı hesaplıyacaksak j o anki i+1 olmalı
			 max=max+profit[j+b];
			 toplam=toplam+distance[j+b];//toplama o an eklenen istasyonla olan uzaklığı ekledik ki bir dahaki atlamada ikisi arasındaki toplam uzaklık ile kontrolü yapalım.
			
		   }
		   if((toplam+distance[j]+distance[j+b])<x && t==1 && j==i+1){//eğer uzaklık en az x değilse 
			  toplam2+=distance[j]+distance[j+b];//eger uzaklık ez az x değilse bir sonraki uzaklığı bulmak için
			   toplam=toplam+distance[j+b];//toplama o an eklenen istasyonla olan uzaklığı ekledik ki bir dahaki atlamada ikisi arasındaki toplam uzaklık ile kontrolü yapalım.
		   }
	     }
	     if( j+b<distance_size){
		   if((toplam2+distance[j+b])>=x && t==1 && j!=i+1){//eğer uzaklık en az x ise ve atlayarak gideceksek  ve j ilk durum değilse
			 
			 max=max+profit[j+b];
			 z=toplam2;
			 toplam2=0;//artık seçilen istasyona göre uzaklıklara bakacağımız için toplam uzaklığı sıfırla
			 
			
		   }
		    if((z+distance[j+b])<x && t==1 && j!=i+1){//eğer uzaklık en az x değilse o anki seçtiğimiz istasyon ile seçilecek istasyon arasındaki uzaklığı bulmak için o anki uzaklığı ekledik
				
			   toplam2+=distance[j+b];
			  
		   }
	    }
	    if(j+b==distance_size){//istasyonların sonuna gelince de bu değeri 0 la
			toplam2=0;
		}
		if(j+1==distance_size){//istasyonların sonuna gelince de bu değeri 0 la
			toplam1=0;
		}
	    
		 if(j==a){//o anki kombinasyon bitince diğer kombinasyona geçmek için 
			  
			 if(max_profit<=max){
				 max_profit=max;
				
			}
			max=profit[i];//max tekrar o anki seçilen istasyonun karını atadık.
			
			b=b+1;
			t=1;
			if(b<k){
			j=i;//j yi tekrar ilk seçilen yani dış döngüde seçilen istasyona atadık
		    }
		 }
		 
		
		 j++;
	 }
	 t=0;
	 b=0;
	 toplam=0;
	 k=k-1;
	
	
	}
	printf("\n%d",max_profit);
	return 0;
}

