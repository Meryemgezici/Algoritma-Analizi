#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int max(int n,int* a){
    int local_max=0;
    int global_max=a[0];
    for(int i=0; i<n; i++){
    	local_max=a[i]+local_max;
    	  printf("%d     %d\n",global_max,local_max);
        if(a[i]>=local_max){
            local_max=a[i];
        }
        if(local_max>=global_max){
            global_max=local_max;
        }
 
}
    return global_max;

}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int diziBoyutu;
    scanf("%d",&diziBoyutu);
    int dizi[diziBoyutu];
     for(int i=0; i<diziBoyutu; i++)
   {
      
       scanf("%d",&dizi[i]);
   }
      

  int r= max(diziBoyutu, dizi);
   printf(" %d",r);
    return 0;
}
