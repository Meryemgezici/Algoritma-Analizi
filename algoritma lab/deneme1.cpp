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
int t;
int grid[6][6]={{1,1,1,1,1,1},{1,1,0,0,0,0},{0,0,0,1,1,1},{0,0,0,1,1,1},{0,0,1,0,0,0},{1,0,0,0,0,0}};
int deger(int row, int col ,int grid_rows ,int grid_columns ){
	grid[row][col]=0;
	if((col+1)<grid_columns){
	     if(grid[row][col+1]==1){
	     	b++;
	     	deger(row,col+1,6,6);
	     
		 }
	}
	col=t;
	if((row+1)<grid_rows){
	     if(grid[row+1][col]==1){
	     	b++;
	     	deger(row+1,col,grid_rows,grid_columns);
	     
		 }
	}

	
	return b;
}
int onesGroups(){
	int a[36];
     int k=0;
     for(int i=0; i<6; i++){
     	for(int j=0; j<6; j++){
     		if(grid[i][j]==1){
     			b=1;
     			t=j;
     			deger(i,j,6,6);
     			printf("\n b:%d \n",b);
			 }
		 }
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
	int grid_rows=6;
	int grid_columns=6;
//	int grid[6][6]={{1,1,1,1,1,1},{1,1,0,0,0,0},{0,0,0,1,1,1},{0,0,0,1,1,1},{1,0,0,0,0,0}};
	
	for(int i=0; i<grid_rows; i++){
		
		for(int j=0; j<grid_columns;j++){
	
			printf("deger");
		}
	}
	int* res;
	int b=0;
	res=&b;

	printf("\n res:%d",*res);
		printf("\n \n\n");
		onesGroups();
		print();
	return 0;
}
