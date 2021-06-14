#include <limits.h>
#include <stdio.h>
int max(int x,int y,int z){//max degeri ortanýnToplami fonkiyonunda buldugumuz için z yi dondurduk.
    return z;
}
 void printArray(int A[], int size)
{
int i;
for (i=0; i < size; i++)
printf("%d ", A[i]);
printf("\n");
}

//yazmanýz gereken asil fonksyon budur. Gerekirse ekstra yardýmcý fonksiyon yazabilirsiniz.

int ortaninToplami(int arr[], int sol, int orta, int sag)
{    int max[sag+sol+1];
     int i=0,j=0,k=sol;
     int t=0,a;
     int n1=orta-sol+1;
     int n2=sag-orta;
    int solDizi[n1],sagDizi[n2];
    for(int i=0; i<n1; i++){//ortanýn solunu solDiziye ata.
        solDizi[i]=arr[sol+i];
    }
    for(int j=0; j<n2; j++){//ortanýn sagýný sagDiziye ata.
        sagDizi[j]=arr[orta+1+j];
    }
    while(i<n1){//sol dizide ikili ikili max degerlerini bul
        if(solDizi[i]>solDizi[i+1] && solDizi[i]>(solDizi[i]+solDizi[i+1]) ){
            max[t]=solDizi[i];
            t++;
        }
        else if(solDizi[i+1]>solDizi[i] && solDizi[i+1]>(solDizi[i]+solDizi[i+1]) ){
            max[t]=solDizi[i+1];
            t++;
        }
        else{
            max[t]=(solDizi[i]+solDizi[i+1]);
            t++;
        }
        i+=2;
    }
    i=1;
    a=t;
    t=0;
    while(t<a && i<n1){//sol tarafta bulunan maxlar komþuysa degerlere tekrar bakýp max bul.
        if(max[t]==solDizi[i]){
            if(max[t+1]==solDizi[i+1]){
                 if(solDizi[i]>solDizi[i+1] && solDizi[i]>(solDizi[i]+solDizi[i+1]) ){
            max[t]=solDizi[i];
            t++;
        }
        else if(solDizi[i+1]>solDizi[i] && solDizi[i+1]>(solDizi[i]+solDizi[i+1]) ){
            max[t]=solDizi[i+1];
            t++;
        }
        else{
            max[t]=(solDizi[i]+solDizi[i+1]);
            t++;
        }
            }
        }
        i+=2;
    }
    //bu kodu yazýnýz
    if(max[1]>max[0]){//max elemanýný max dizisinin ilk elemaný olarak tutuyoruz.
        max[0]=max[1];
    }
    t=1;
    
    while(j<n2){//sag dizide ikili ikili max degerlerini bul
        if(sagDizi[j]>sagDizi[j+1] && sagDizi[j]>(sagDizi[j]+sagDizi[j+1]) ){
            max[t]=sagDizi[j];
            t++;
        }
        else if(sagDizi[j+1]>sagDizi[j] && sagDizi[j+1]>(sagDizi[j]+sagDizi[j+1]) ){
            max[t]=sagDizi[j+1];
            t++;
        }
        else{
            max[t]=(sagDizi[j]+sagDizi[j+1]);
            t++;
        }
        j+=2;
    }
    j=1;
    a=t;
    t=1;
    
    while(t<a && j<n2){//sag tarafta bulunan maxlar komþuysa degerlere tekrar bakýp max bul.
        if(max[t]==sagDizi[j]){
            if(max[t+1]==sagDizi[j+1]){
               if(sagDizi[j]>sagDizi[j+1] && sagDizi[j]>(sagDizi[j]+sagDizi[j+1]) ){
            max[t]=sagDizi[j];
            t++;
        }
        else if(sagDizi[j+1]>sagDizi[j] && sagDizi[j+1]>(sagDizi[j]+sagDizi[j+1]) ){
            max[t]=sagDizi[j+1];
            t++;
        }
        else{
            max[t]=(sagDizi[j]+sagDizi[j+1]);
            t++;
        }
            }
        }
        j+=2;
    }
    if(max[2]>max[1]){
        max[2]=max[0];
    }
    if(max[1]>max[0]){
        max[0]=max[1];
    }
    i=1;
    j=0;
    int toplam=0,toplam2=0;
    while((orta+j)>=0){//maximum sað ve solun ortasýnýn toplamýnda
        toplam2+=arr[orta+j];
        toplam=toplam2;
        while((orta+i)<=sag){
            toplam+=arr[orta+i];
            if(max[0]<toplam){
                max[0]=toplam;
            }
            i++;
        }
        j--;
        i=1;
    }
  return max[0];  
    
}

//diziyi, ilk indisi, son indisi input olarak alýr.
int enBuyukToplam(int arr[],int sol,int sag){
    

    
    //base case
    if(sag==sol)
    return arr[sag];
    
   // else 
    
      // Find middle point
    int orta = (sag + sol) / 2;
 
    /* 3 ihtimalin maxmumunu dondurunuz
            1. maximum sol tarafta
            2. maximum sag tarafta
            3.maximum sað ve solun ortasýnýn toplamýnda */
    
    //aþaðýdaki max fonksyonunu yazýn
    return max(enBuyukToplam(arr, sol, orta),
               enBuyukToplam(arr, orta + 1, sag),
               ortaninToplami(arr, sol, orta, sag)); //bu fonksiyonu yukarýya yazýn
    
}


int main()
{ //mainde hiçbir þey deðiþtirmeyiniz.
    
    //diziyi tanýmla
    int arr[]={-5, 20, 10, -2, -3, -5,- 5, -6};
    
    //dizinin boyunu bul
    int n = sizeof(arr) / sizeof(arr[0]);
    
    //fonksiyonu çaðýr
   
    int toplam_max = enBuyukToplam(arr, 0, n - 1);
   printArray(arr,8); 
    //yazdýr
    printf("%d",toplam_max);
    
    return 0;
    
}


// A Divide and Conquer based program for maximum subarray
// sum problem
/*
#include <limits.h>
#include <stdio.h>
 
// A utility funtion to find maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }
 
// A utility funtion to find maximum of three integers
int max(int a, int b, int c) { return max(max(a, b), c); }
 
// Find the maximum possible sum in arr[] auch that arr[m]
// is part of it
int maxCrossingSum(int arr[], int l, int m, int h)
{
    // Include elements on left of mid.
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }
 
    // Include elements on right of mid
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= h; i++) {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
 
    // Return sum of elements on left and right of mid
    // returning only left_sum + right_sum will fail for
    // [-2, 1]
    return max(left_sum + right_sum, left_sum, right_sum);
}
 
// Returns sum of maxium sum subarray in aa[l..h]
int maxSubArraySum(int arr[], int l, int h)
{
    // Base Case: Only one element
    if (l == h)
        return arr[l];
 
    // Find middle point
    int m = (l + h) / 2;
 
    /* Return maximum of following three possible cases
            a) Maximum subarray sum in left half
            b) Maximum subarray sum in right half
            c) Maximum subarray sum such that the subarray
       crosses the midpoint */ 
   /* return max(maxSubArraySum(arr, l, m),
               maxSubArraySum(arr, m + 1, h),
               maxCrossingSum(arr, l, m, h));
}*/
 
/*Driver program to test maxSubArraySum
int main()
{
    int arr[] = { 2, 3, 4, 5, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, 0, n - 1);
    printf("Maximum contiguous sum is %dn", max_sum);
    getchar();
    return 0;
}*/
