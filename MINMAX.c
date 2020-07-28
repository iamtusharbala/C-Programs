/*A minimax in a two-dimensional array is the element that is the minimum of its row and maximum of its column, or vice versa. For example in the following array

11     22    33    33

99    55    66    77

77    44    99    22


the element 33 is a minimax because it is the maximum of row 0 and the minimum of column 2. The element 55 is another minimax because it is the minimum of row 1 and the maximum of column 1. Write and test a program that reads the integers m and n, and then reads an m-by-n matrix, and then prints the location and value of each minimax in the matrix. For example, it would print

a[0,2] = 33 is a minimax 

a[1,1] = 55 is a minimax 

for the matrix shown above.*/

#include <stdio.h>
int main(void) {
  int a[50][50],row,col,i=0,j=0,big=0,small=0,sinew,sjnew,binew,bjnew,newsmall=0,newbig=0,flag=0,tempi,tempj;
  printf("Enter row no:\n");
  scanf("%d", &row);
  printf("Enter col no:\n");
  scanf("%d", &col);
  printf("Enter elements into array:\n");
  for(i=0;i<row;i++){
    for(j=0;j<col;j++){
      scanf("%d",&a[i][j]);
    }
  }
  //correct till here
  for(i=0;i<row;i++){
    for(j=0;j<col;j++){
      if((i==0&&j==0) || j==0 ){
        small=a[i][j];
        big=a[i][j];
        sinew = i;
        sjnew = j;
        binew = i;
        bjnew = j;
      }
      else if(small>a[i][j]){
        small=a[i][j];
        sinew = i;
        sjnew = j;
      }
      else if(big<a[i][j]){
        big=a[i][j];
        binew = i;
        bjnew = j;
      }
      else{
        continue;
      }
    }
    printf("\n");
    tempi=i;
    tempj=j;
    //to find big in row is small in column
    j=bjnew;
    for(i=0;i<row;i++){
      if(i==0&&j==bjnew){
        newsmall = a[i][j];
      } 
      else if(newsmall<a[i][j]){
        continue;
      }
      else{
        flag=1;
        break;
      }
    }
    if(flag==0 && big==newsmall){
      printf("a[%d][%d]= %d is a minmax",binew,bjnew,big);
    }
    //to find small in row is big in column
    j=sjnew;
    for(i=0;i<row;i++){
      if(i==0&&j==sjnew){
        newbig=a[i][j];
      }
      else if(newbig<a[i][j]){
        newbig=a[i][j];
      }
      else{
        flag=1;
        break;
      }
    }
    if(flag==1 && small==newbig){
      printf("a[%d][%d]= %d is a minmax",sinew,sjnew,small);
    }
    i=tempi;
    j=tempj;
    printf("\n");

  }
 

}