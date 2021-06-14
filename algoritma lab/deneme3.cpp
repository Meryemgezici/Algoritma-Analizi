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
char** split_string(char*);

int parse_int(char*);



/*
 * Complete the 'onesGroups' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY grid
 *  2. INTEGER_ARRAY queries
 */

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */
 
 /* if(mer!=mer1){
        row=mer2;
         while(mer<mer1){
             if((row+1)<grid_rows){
                 if(grid[row+1][mer]==1){
                     sayac++;
                     mer2++;
                     dfs(grid,row+1,mer,grid_rows,grid_columns);
                     
                 }
             }
             mer++;
             mer3=mer;
             
         }
     }*/
     
     
 int sayac;
 int col_ilk1,col_ilk2,col_ilk3;
 int mer,mer1,mer2,mer3;
 
 int dfs(int** grid,int row,int col,int grid_rows, int grid_columns){
     grid[row][col]=0;
    
     if((col+1)<grid_columns){
         if(grid[row][col+1]==1){
             col_ilk1++;
             sayac++;
             dfs(grid,row,col+1,grid_rows,grid_columns);
         }
     }
    
    
     if((col-1)>=0){
         if(grid[row][col-1]==1){
             sayac++;
             mer--;
             dfs(grid,row,col-1,grid_rows,grid_columns);
         }
     }
     col_ilk3=col_ilk2;
     while(col_ilk3<=col_ilk1){
         if((row+1)<grid_rows){
         if(grid[row+1][col_ilk3]==1){
             sayac++;
             col_ilk1=col_ilk3;
             dfs(grid,row+1,col_ilk3,grid_rows,grid_columns);
         }
         }
         col_ilk3++;
         col_ilk2=col_ilk3;
     }
    
     return sayac;
 }
 
int* onesGroups(int grid_rows, int grid_columns, int** grid, int queries_count, int* queries, int* result_count) {
    int a[grid_rows*grid_columns];
   //int* a;
  // a=(int*)malloc(sizeof(int));
  
    int x=0,sayac2=0;
 
    for(int i=0; i<grid_rows; i++){
        for(int j=0; j<grid_columns; j++){
            if(grid[i][j]==1){
                sayac=1;
                col_ilk1=j;
                col_ilk2=j;
                mer=j;
                mer1=j;
                mer2=i;
                mer3=j;
               a[x]=dfs(grid,i,j,grid_rows,grid_columns);
               
               
             // printf("sayac:%d \n",sayac);
                x++;
            }
        }
    }
    int b[queries_count];
    for(int i=0; i<queries_count; i++){
        for(int j=0; j<=x; j++){
            if(a[j]==queries[i]){
                sayac2++;
            }
        }
        b[i]=sayac2;
        //printf("\nb[%d]:%d",i,b[i]);
        sayac2=0;
    }
     for(int i=0; i<queries_count; i++){
        
           queries[i]=b[i];
       
    }
 /* int* t;
    t=&queries[0];*/
  *result_count=queries_count;
return queries;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int grid_rows = parse_int(ltrim(rtrim(readline())));

    int grid_columns = parse_int(ltrim(rtrim(readline())));

    int** grid = malloc(grid_rows * sizeof(int*)		);

    for (int i = 0; i < grid_rows; i++) {
        *(grid + i) = malloc(grid_columns * (sizeof(int)));

        char** grid_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < grid_columns; j++) {
            int grid_item = parse_int(*(grid_item_temp + j));

            *(*(grid + i) + j) = grid_item;
        }
    }

    int queries_count = parse_int(ltrim(rtrim(readline())));

    int* queries = malloc(queries_count * sizeof(int));

    for (int i = 0; i < queries_count; i++) {
        int queries_item = parse_int(ltrim(rtrim(readline())));

        *(queries + i) = queries_item;
    }

    int result_count;
    int* result = onesGroups(grid_rows, grid_columns, grid, queries_count, queries, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}

