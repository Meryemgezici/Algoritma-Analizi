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


int main(){
	
	int a=20,b=10,r;
	if(a>b){
	r=b;
     while(r!=0){
     	b=r;
     	r=a%b;
     	a=b;
     
	 }
	 printf("%d",b);
}
	return 0;
}
