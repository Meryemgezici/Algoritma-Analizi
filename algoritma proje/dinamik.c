/*
 * dinamik.c
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 

int main(int argc, char **argv)
{
	 double time_spent = 0.0;
 
    clock_t begin = clock();
 
    // do some stuff here
    sleep(3);
 
    clock_t end = clock();
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds", time_spent);
    
	int distance[]={824,695,318,951,35,439,382,766,796,187};//ilk değerimiz ilk istasyonun  merkeze olan uzaklığını verir.Diğer değerlerimiz baz istasyonları arasındaki uzaklığı verir.
	int profit[]={37,42,5,57,11,56,96,65,34,7};//baz istasyonlarının karı.
	
	int distance_size =(sizeof(distance)/sizeof(distance[0]));//distance dizimizin uzunluğu aynı zamanda profit dizimizin de uzunluğu
	int our_location=0;//bulunduğumuz istasyon
    int x=1000;//baz istasyonları arasında  ez az x  mesafe olmalı.
    int merkeze_olan_uzaklik=0;//merkeze olan uzaklık saymamak için 
    int all_distance_size=distance_size*distance_size;//all_distance dizisinin uzunluğu
    int all_distance[all_distance_size];//bütün istasyonların birbirleri arasındaki uzaklık 
    int sum=0;
    int t=0;
    int tablo[distance_size][distance_size];//eğer uzunluk en az x kadar ise kar değerini yaz
    for(int i=0; i<distance_size; i++){
		for(int j=0; j<distance_size; j++){
			if(merkeze_olan_uzaklik==0){//merkeze olan uzaklık ise direkt x kadar olsun
				all_distance[t]=x;
				t++;
				merkeze_olan_uzaklik=merkeze_olan_uzaklik+1;
			}else if(j<=i){//bulunduğumuz istasyondan sonraki istasyonları seçebildiğimiz için o istasyondan büyük olana kadar uzunluğu 0 yapıyoruz
				all_distance[t]=0;
				t++;
			}else{//istasyonlar arasındaki uzaklıkları all_distance dizisine ata
				sum+=distance[j];
				all_distance[t]=sum;
				t++;
			}
		}
		sum=0;
		merkeze_olan_uzaklik=0;
	}
		
   
     t=0;//all_distance dizisini gezmek için
	 for(int i=0; i<distance_size; i++){
		for(int j=0; j<distance_size; j++){
			
			if(merkeze_olan_uzaklik==0){//merkeze olan uzaklık ise o an ki karı tabloya ata
				tablo[i][j]=profit[i];
				merkeze_olan_uzaklik=merkeze_olan_uzaklik+1;
				
			}else if(all_distance[t]>=x){//eğer uzaklık en az x ise o istasyondaki karı tobloya ata
				tablo[i][j]=profit[j];
				
			}else{//eğer uzaklık en az x değilse tabloya 0 ata
					tablo[i][j]=0;
				
			}
			t++;
		}
		merkeze_olan_uzaklik=0;
		
	}
		
	
	
	 int max=0,max1=0,max3;
	 int max_profit=0;
	 int k;//bir onceki bulunduğumuz istasyonu tutar
	 for(int i=0; i<distance_size; i++){//tabloyu dolaş
		  our_location=i;
		  k=i;
		for(int j=0; j<distance_size; j++){
			if(tablo[our_location][j]!= 0){//tablodaki değerimiz 0 değilse yani hem uzaklığımız hem de karımız uyuyorsa 
				max1=max;//bir onceki max tutmak için 
				max+=tablo[our_location][j];//o anki karı ekle
				
				k=our_location;
				if((j+i)<distance_size){
				  our_location=j+i;
				}
			}
			else if(tablo[our_location][j]== 0 && our_location !=i){//tablodaki değerimiz 0 ise  yani uzaklığımız uyuşmuyorsa bir onceki durumu gözden geçir 
				 if(tablo[k][j]!= 0){
					 max1+=tablo[k][j];
					
					  k=j;
				 }
			}
			
			if(max>=max1 && max>=max_profit){
			   
				max_profit=max;
			}
			if(max1>max && max1>max_profit){
				max_profit=max1;
				max3=max;
				max=max1;
				max1=max3;
				k=our_location;
				our_location=j;
				

			}
			
			
		}
		
		 max=0;
		 max1=0;
	}
	
	 printf("\nmax profit:%d\n",max_profit);
		
	
	return 0;
}

