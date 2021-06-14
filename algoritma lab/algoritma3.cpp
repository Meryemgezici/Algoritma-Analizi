
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
int deger(int** grid, int row, int col ,int grid_rows ,int grid_columns ){
	grid[row][col]=0;
	if((col+1)<grid_columns){
	     if(grid[row][col+1]==1){
	     	    z++;
	     		b++;
	     	deger(grid,row,col+1,grid_rows,grid_columns);
	     
		 }
	}

	if((col-1)>=0){
		if(grid[row][col-1]==1){
	     	b++;
	     	deger(grid,row,col-1,grid_rows,grid_columns);
	     
		 }
	}
		col_ilk=mer;
	while(col_ilk<=z){
	
	if((row+1)<grid_rows){
	     if(grid[row+1][col_ilk]==1){
	     	b++;
	     	z=col_ilk;
	     	deger(grid,row+1,col_ilk,grid_rows,grid_columns);
	     
		 }
	}
	col_ilk++;
	mer=col_ilk;
}
/*	if((row+1)<grid_rows){
	     if(grid[row+1][col]==1){
	     	    z++;
	     		b++;
	     	deger(grid,row+1,col,grid_rows,grid_columns);
	     	
		 }
	}*/
	
	return b;
}
int* onesGroups(int grid_rows, int grid_columns,int** grid,int queries_count,int* queries,int* result_count){
	int a[grid_rows*grid_columns];
    int x=0,kac=0;
     for(int i=0; i<grid_rows; i++){
     	for(int j=0; j<grid_columns; j++){
     		if(grid[i][j]==1){
     			b=1;
     			z=j;
				mer=j;
				col_ilk=j;
     		 a[x]=deger(grid,i,j,grid_rows,grid_columns);
     	    
     		x++;
     		
     	     
			 }
			 
		 }
	 }
	 
	 for(int i=0; i<queries_count; i++){
	 	for(int j=0; j<=x; j++){
	 		if(a[j]==queries[i]){
	 			kac++;
			 }
		 }
		 a[i]=kac;
		 kac=0;
	 }
	
  return result_count;
	
}

int main(){
	int grid_rows=6;
	int grid_columns=6;
	int grid[6][6]={{1,1,1,1,1,1},{1,1,0,0,0,0},{0,0,0,1,1,1},{0,0,0,1,1,1},{0,0,1,0,0,0},{1,0,0,0,0,0}};
	
	for(int i=0; i<grid_rows; i++){
		
		for(int j=0; j<grid_columns;j++){
	
			printf("deger");
		}
	}
	int* res;
	int b=0;
	res=&b;

	printf("\n res:%d",*res);
	
	return 0;
}
