#include<stdlib.h>
#include<stdio.h>
int max(int x,int y,int z){
//	printf("ars:%d\n",ars);
//	ars++;
	return z;
}

 void printArray(int A[], int size)
{
int i;
for (i=0; i < size; i++)
printf("%d ", A[i]);
printf("\n");
}




int merge(int arr[], int sol, int orta, int sag)
{   int max[sol+sag+1];
    int i=0, j=0, k=sol;
    int t=0,a;
    int n1 = orta - sol + 1;
    int n2 = sag - orta;
    int s=0;
/*Geçici diziler oluþturuyoruz */
    int solDizi[n1], sagDizi[n2];
/* Verileri geçici dizilere kopyalýyoruz L[] veR[] */
    for (int i = 0; i < n1; i++){
	
        solDizi[i] = arr[sol + i];
    }
    for (int j = 0; j < n2; j++){
    	 sagDizi[j] = arr[orta + 1+ j];
	}
      
   
     /*   while (i < n1 && j < n2){
           if (L[i] <= R[j]){
             arr[k] = L[i];
             i++;
            }
           else{
              arr[k] = R[j];
              j++;
            }
            k++;
        }*/
/*Kalan elemanlarý kontrol edip varsa onlarý geçici dizilere kopyalýyoruz*/
/*while (i < n1)
{
arr[k] = L[i];
i++;
k++;
}
while (j < n2)
{
arr[k] = R[j];
j++;
k++;
}*/
      while(i<n1){
      	if(solDizi[i]>solDizi[i+1] && solDizi[i]>(solDizi[i]+solDizi[i+1])){
      		max[t]=solDizi[i];
      		t++;
		  }
		  else if(solDizi[i+1]>solDizi[i] && solDizi[i+1]>(solDizi[i]+solDizi[i+1])){
		  	max[t]=solDizi[i+1];
		  	t++;
		  }
		  else{
		  	max[t]=(solDizi[i+1]+solDizi[i]);
		  	t++;
		  }
		  i+=2;
	  }
	  i=1;
	  a=t;
	  t=0;
	 while(t<a && i<n1){
	 	if(max[t]==solDizi[i]){
	 		if(max[t+1]==solDizi[i+1]){
	 				if(solDizi[i]>solDizi[i+1] && solDizi[i]>(solDizi[i]+solDizi[i+1])){
      		max[t]=solDizi[i];
      		t++;
		  }
		  else if(solDizi[i+1]>solDizi[i] && solDizi[i+1]>(solDizi[i]+solDizi[i+1])){
		  	max[t]=solDizi[i+1];
		  	t++;
		  }
		  else{
		  	max[t]=(solDizi[i+1]+solDizi[i]);
		  	t++;
		  }
	 		
		   }
		 }
		 i+=2;
		 
	 }
	 for(int i=0; i<t; i++){
	 }
	 if(max[1]>max[0]){
	 	max[0]=max[1];
	 }
	 t=1;
	 
	 
	 
	 while(j<n2){
      	if(sagDizi[j]>sagDizi[j+1] && sagDizi[j]>(sagDizi[j]+sagDizi[j+1])){
      		max[t]=sagDizi[j];
      		t++;
		  }
		  else if(sagDizi[j+1]>sagDizi[j] && sagDizi[j+1]>(sagDizi[j]+sagDizi[j+1])){
		  	max[t]=sagDizi[j+1];
		  	t++;
		  }
		  else{
		  	max[t]=(sagDizi[j+1]+sagDizi[j]);
		  	t++;
		  }
		  j+=2;
	  }
	  j=1;
	  a=t;
	  t=1;
	 while(t<a && j<n2){
	 	if(max[t]==sagDizi[j]){
	 		if(max[t+1]==sagDizi[j+1]){
	 			if(sagDizi[j]>sagDizi[j+1] && sagDizi[j]>(sagDizi[j]+sagDizi[j+1])){
      		max[t]=sagDizi[j];
      		t++;
		  }
		  else if(sagDizi[j+1]>sagDizi[j] && sagDizi[j+1]>(sagDizi[j]+sagDizi[j+1])){
		  	max[t]=sagDizi[j+1];
		  	t++;
		  }
		  else{
		  	max[t]=(sagDizi[j+1]+sagDizi[j]);
		  	t++;
		  }
	 		
		   }
		 }
		 j+=2;
	 }
	  if(max[2]>max[1]){
	 	max[1]=max[2];
	 }
	 if(max[1]>max[0]){
	 	max[0]=max[1];
	 }
	 i=1;
	 j=0;
	 int toplam=0;
	 int toplam2=0;
	 while((orta+j)>=0){
	  
	   toplam2+=arr[orta+j];
	   toplam=toplam2;
	    printf("\narr[orta+j]:%d",arr[orta+j]);
	 	while((orta+i)<=sag){
	 		 printf("\narr[orta+i]:%d",arr[orta+i]);
	 		toplam+=arr[orta+i];
	 		printf("\ntoplam:%d",toplam);
	 		if(max[0]<toplam){
	 			max[0]=toplam;
			 }
			// toplam+=toplam2;
	 		i++;
		 }
		// toplam2+=arr[orta+j];
		 j--;
		 i=1;
	 }
return max[0];
}




int mergeSort(int arr[], int sol, int sag)
{
    if (sol ==sag){
	     return arr[sag];
	}

int orta = (sol+sag)/2;
// Ýlk ve ikinci yarýlarý sýralýyoruz
        return max(mergeSort(arr, sol, orta),
                   mergeSort(arr, orta+1, sag),
                   merge(arr, sol, orta, sag));

}


int main(){
	int arr[]={-2,-5,6,-2,-3,1,5,-6};
    // int arr[]={-2,6,-5,-2,-3,1,-6,5};
	int n=sizeof(arr)/sizeof(arr[0]);
	int toplam_max=mergeSort(arr,0,n-1);

	 printArray(arr,8);
     printf("\n%d",toplam_max);

	return 0;
}
