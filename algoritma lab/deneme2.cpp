#include<assert.h>
#include<limits.h>
#include<math.h>
#include<stdbool.h>
#include<stddef.h>
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int b;
int z,mer,col_ilk;

int row_ilk;
int grid[6][6]={{0,0,0,1,1,1},{1,1,1,1,1,1},{0,0,1,1,1,1},{0,0,0,1,1,1},{0,0,1,1,0,0},{1,1,0,0,0,0}};
int deger(int row, int col ,int grid_rows ,int grid_columns ){
	grid[row][col]=0;

  
	if((col+1)<grid_columns){
	     if(grid[row][col+1]==1){
	     	b++;
	     	z++;
	     	deger(row,col+1,6,6);
	     
		 }
	}
	//col=mer;
	if((col-1)>=0){
		if(grid[row][col-1]==1){
	     	b++;
	     	deger(row,col-1,6,6);
	     
		 }
	}
	col_ilk=mer;
	while(col_ilk<=z){
	
	if((row+1)<grid_rows){
	     if(grid[row+1][col_ilk]==1){
	     	b++;
	     	z=col_ilk;
	     	deger(row+1,col_ilk,grid_rows,grid_columns);
	     
		 }
	}
	col_ilk++;
	mer=col_ilk;
}
   

	return b;
}
int onesGroups(){
	int quiers[]={11,2,1};
	int a[36];
     int k=0;
     int kac=0;
     for(int i=0; i<6; i++){
     	for(int j=0; j<6; j++){
     		if(grid[i][j]==1){
     			b=1;
     			z=j;
     			mer=j;
     		
     		a[k]=deger(i,j,6,6);
     			printf("\n b:%d \n",b);
     			
     			k++;
     		
			 }
			 
		 }
	 }
	 
	  for(int i=0; i<3; i++){
	 	for(int j=0; j<=k; j++){
	 		if(a[j]==quiers[i]){
	 			kac++;
			 }
		 }
		 a[i]=kac;
		 	printf("\n a:%d \n",a[i]);
		 	kac=0;
	 }
	
  	return 0;
	
}
void print(){
		for(int i=0; i<6; i++){
		
		for(int j=0; j<6;j++){
	
			printf("\ndeger:%d \n",grid[i][j]);
		}
	}
}

int main(){

		onesGroups();
	//	print();
	return 0;
}
