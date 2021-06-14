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
 * Complete the 'countDuplicate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY numbers as parameter.
 */

int countDuplicate(int numbers_count, int* numbers) {
int min;
int sayac1=1,sayac2=0;
if(numbers_count>=3 && numbers_count<=1000){
    if(numbers[0]>=1 && numbers[numbers_count-1]<=1000){
for(int i=0; i<numbers_count; i++){
    min=i;
     for(int j=i+1; j<numbers_count; j++){
         if(numbers[j]<numbers[min]){
             min=j;
         }
         
     }
     int tmp=numbers[i];
     numbers[i]=numbers[min];
     numbers[min]=tmp;
}

for(int i=0; i<numbers_count; i++){
    
    for(int j=i+1; j<numbers_count; j++){
        if(i==0){
            if(numbers[i]==numbers[j]){
                    sayac1++;
                }
        }
        if((i-1)>=0){
            if(numbers[i-1]!=numbers[i]){
                if(numbers[i]==numbers[j]){
                    sayac1++;
                }
            }
        }
    }
    if(sayac1>1){
        sayac2++;
    }
    sayac1=1;
}
    }
}
return sayac2;
}

int main(){
	return 0;
}
