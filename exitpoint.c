/*Given a matrix with 0's and 1's, one enters the matrix at cell (0, 0) in left to right direction. Whenever one encounters a 0 he retains in the same direction, if one encounters a 1 he has to change direction to the right of current direction and change that 1 value to 0. Write a programming out from which index he will leave the matrix at the end. (Indexing starts from 0).
Input: An mxn matrix with each element 0 or 1

Output:Cell index pair (i, j) where is the row no & j is the column no*/

/*
down => flag=1
left => flag=2
up => flag=3
down => flag=0
*/

#include <stdio.h>
int main(void) {
  int a[100][100],row,col,i,j,iinew,inew=0,jnew=0,flag=0;
  printf("Enter row no:\n");
  scanf("%d",&row);
  printf("enter column no:\n");
  scanf("%d",&col);
  printf("enter elements 0 or 1:\n");
  for(i=0;i<row;i++){
    for(j=0;j<col;j++){
      scanf("%d", &a[i][j]);
    }
  }

  printf("elements are:\n");
  for(i=0;i<row;i++){
    for(j=0;j<col;j++){
      printf("%d\t", a[i][j]);
      if(j==col-1){
        printf("\n");
      }
    }
  }

  for(i=0;i<row;i++){
    for(j=0;j<col;j++){
      if(a[i][j]==1){
        a[i][j]=0;
        inew = i;
        jnew = j;
        flag=1;
        break;
      }
      else{
        continue;
      }
    }
    if(flag==1){
        break;
      }
  }

//flag 1 is correct
  if(flag==1){
    j=jnew;
    for(i=inew;i<row;i++){
      if(a[i][j]!=1){
        iinew=i;
      }
      else{
        a[i][j]=0;
        inew=i;
        jnew=j;
        flag=2;
        break;
      }
    }
    if(flag==1){
        printf("\n(%d,%d) \n",iinew,jnew);
    } 
}

if(flag==2){
    i=inew;
    for(j=jnew;j>=0;j--){
      if(a[i][j]!=1){
        iinew=i;
      }
      else{
        a[i][j]=0;
        inew=i;
        jnew=j;
        flag=3;
        break;
      }
    }
    if(flag==2){
        printf("\n(%d,%d) \n",iinew,j+1);
    } 
}

if(flag==3){
  j=jnew;
  for(i=inew;i>=0;i--){
    if(a[i][j]!=1){
      iinew=i;
    }
    else{
      a[i][j]=0;
      inew=i;
      jnew=j;
      flag=0;
      // printf("%d nnn %d",inew,jnew);
      break;
    }
  }
  if(flag==3){
      printf("\n(%d,%d) \n",iinew,j);
  } 

  }
}
