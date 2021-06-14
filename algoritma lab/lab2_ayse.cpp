#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);



/*
 * Complete the 'balancedSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
 
int balancedSum(int arr_count, int* arr) {
	int sum=0;
    int sumRight=0;
    int sumLeft=0;
    int pivot;
   
   /* if(arr_count==1){
        return 0;
    }*/
    
    for(int i=0; i<arr_count; i++){
        sum=sum+arr[i];
    }
    printf("\ntoplam:%d\n",sum);
    sumRight=sum;
   
    for(int j=0; j<arr_count; j++){
        sumRight=sumRight-arr[j];
        sumLeft=sumLeft;
         printf("\ntoplamsol:%d    toplamsag:%d  \n",sumLeft,sumRight);
        if(sumLeft==sumRight){
            pivot=j;
        }
        sumLeft=sumLeft+arr[j];
    }
    return pivot;


}

int main(){
	int arr[1]={1};
	int r=balancedSum(1,arr);
	printf("%d",r);
	return 0;
}
