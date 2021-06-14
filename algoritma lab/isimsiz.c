

int min(int a,int b){
	return a<b ? a:b;
	
	}
int coin_para(int n,int coin[],int amount){
	int dizi[amount+1];
	dizi[0]=0;
	
	for(int i=1; i<=amount; i++){
		int j=0;
		int minimum=300;
		
		while(j<n && i>=coin[j]){
			minimum=min((dizi[i-coin[j]]),minimum);
			j++;
		}
		dizi[i]=minimum+1;
	}
	return dizi[amount];
}



#include <stdio.h>

int main(int argc, char **argv)
{
	 int coin[]={1,3,5};
	int n=3;
	int t=coin_para(n,coin,9);
	printf("\n t:%d\n",t);
	return 0;
}

