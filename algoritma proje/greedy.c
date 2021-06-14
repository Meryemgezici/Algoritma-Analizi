/*
 * greedy.c
 * 
 
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    
    int L[n1], R[n2];
 
  
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
   
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
   
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
  
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void  mergesort(int arr[],int sol,int sag){
    

    
    
    if(sag>sol){
  
    
    int orta = (sag + sol) / 2;
 
   
               mergesort(arr, sol, orta);
               mergesort(arr, orta + 1, sag);
               merge(arr, sol, orta, sag); 
	}
    
}

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
    
	int distance[]={824,695,318,951,35,439,382,766,796,187};//ilk değerimiz ilk istasyonun  merkeze olan uzaklığını verir.Diğer değerlerimiz baz istasyonları arasındaki uzaklığı verir.
	int profit[]={37,42,5,57,11,56,96,65,34,7};//baz istasyonlarının karı.
	int profit_sort[]={37,42,5,57,11,56,96,65,34,7};//karları büyükten küçüğe doğru sıralamak için profit dizimizin kopyasını oluşturduk
	int distance_size =(sizeof(distance)/sizeof(distance[0]));//distance dizimizin uzunluğu aynı zamanda profit dizimizin de uzunluğu
	int our_location=0;//bulunduğumuz istasyon
    int x=500;//baz istasyonları arasında  ez az x  mesafe olmalı.
    int sum_distance=0;//seçtiğimiz baz istasyonları arasındaki toplam uzaklık
    int distance_index[distance_size];//profit_sort daki istasyonların uzaklık indexini verir
    int selected_stations_index[distance_size];//seçilen istasyonların profit dizindeki indexleri
    
    
   
	
	
	mergesort(profit_sort,0,distance_size-1); //profit_sort dizimizi büyükten küçüğe doğru sıraladık
	
	for(int i=0; i<distance_size; i++){//profit_sort dizimizi büyükten küçüğe doğru sıraladıktan sonra profit dizindeki indexlerini bulup distance_index atadık.
	   for(int j=0; j<distance_size; j++){
		   if(profit_sort[i]==profit[j]){
			   distance_index[i]=j;
		   }
	    }
	}
	

	
	
	selected_stations_index[0]=distance_index[0];//seçilen ilk istasyonumuzun profit dizisindeki indexini atadık.
	int t=1;
	for(int i=0; i<distance_size; i++){
		if((i+1)<distance_size && profit_sort[i]!=profit_sort[distance_size-1]){//dizinin sonuna gelmemişsek
		if(distance_index[our_location]>distance_index[i+1]){//eğer bulunduğuuz istasyon seçeceğimiz istasyonun sağında ise
			int a=distance_index[our_location];
			int b=distance_index[i+1];

			while(b<a){//bulunduğumuz istasyondan seçeceğimiz istasyon arasındaki uzaklığı hesapla
				sum_distance+=distance[b+1];
				b++;
			}
			if(sum_distance>=x){//bulunduğumuz istasyon ile seçeceğimiz istasyon arasındaki uzaklığı en az x ise selected_stations dizimize o istasyonu ekle
				our_location=i+1;//bulunduğumuz istasyonun indexi değiştir
				int c=distance_index[i+1];
			
				
				selected_stations_index[t]=c;//seçtiğimiz istasyonun indexini selected_stations_index ata.
				t++;			
			}
		}else{//eğer bulunduğuuz istasyon seçeceğimiz istasyonun solunda  ise
			int a=distance_index[our_location];
			int b=distance_index[i+1];
		
			while(a<b){//bulunduğumuz istasyondan seçeceğimiz istasyon arasındaki uzaklığı hesapla
				sum_distance+=distance[a+1];
				a++;
			}
			if(sum_distance>=x){//bulunduğumuz istasyon ile seçeceğimiz istasyon arasındaki uzaklığı en az x ise selected_stations dizimize o istasyonu ekle
				our_location=i+1;//bulunduğumuz istasyonun indexi değiştir
				int c=distance_index[i+1];
				selected_stations_index[t]=c;//seçtiğimiz istasyonun indexini selected_stations_index ata.
				t++;			
			}
			
		}
	}
		sum_distance=0;
		
	}
	
	    
	    mergesort(selected_stations_index,0,t-1);//seçilen istasyonların indexini büyükten küçüğe sırala
	    
	    int j=0;
	    int dizi[t];//
	    for(int i=t-1; i>=0; i--){//seçilen istasyonların indexini küçükten büyüğe sırala
			dizi[j]=selected_stations_index[i];
			j++;
		}
		
	    int secilen_index[t];//seçilen istasyonların indexi
	    secilen_index[0]=dizi[0];
	    int c=dizi[0];
	    int max_profit=profit[c];
	    int z=1;
	    our_location=0;
	    for(int i=0; i<j; i++){
			if((i+1)<j ){ 
			   int a=dizi[our_location];//bulunduğumuz istasyon
			   int b=dizi[i+1];//seçeceğimiz istasyon
			   while(a<b){//bulunduğumuz istasyon ile seçeceğimiz istasyon arasındaki uzaklığı hesapla
				  sum_distance+=distance[a+1];
				  a++;
			   }
			   a=dizi[our_location];
			  
			     if(sum_distance>=x){//eğer uzaklık en az x ise max karımıza ekle
					 	our_location=i+1;
			            secilen_index[z]=dizi[i+1];
			            z++;
				       max_profit+=profit[b];
			        	
				  		
			     }else{//eğer aradaki uzaklık en az x değilse 
					 if(profit[a]<profit[b]){//buluduğumuz istasyon bizden sonraki seçeceğimiz istasyondan küçük ise bulunduğumuz istasyonu max kardan çıkar ve seçeceğimiz istasyonu max kara ekle.
						    max_profit=max_profit-profit[a];
						    z--;
						    secilen_index[z]=dizi[i+1];
						    z++;
						    max_profit=max_profit+profit[b];
						    our_location=i+1;
					 }
			     }
		   }
		   sum_distance=0;
		}
		 for(int i=0; i<z; i++){
			   printf("\n max kar icin secilen istasyonlar:%d \n",secilen_index[i]);
		 }
	     printf("\n max:%d \n",max_profit);
	return 0;
}

