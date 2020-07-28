/*Given a bitonic array find the maximum value of the array. An array is said to be bitonic if it has an increasing sequence of integers followed immediately by a decreasing sequence of integers.*/
#include <stdio.h>
int main(void) {
  int arr[100],i,j,lim,newi,lessflag=0,greatflag=0,max=0,first;
  printf("Enter limit:\n");
  scanf("%d",&lim);
  printf("Enter Elements:\n");
  for(i=0;i<lim;i++){
    scanf("%d",&arr[i]);
  }
  printf("The elements are:\n");
  for(i=0;i<lim;i++){
    printf("%d\t",arr[i]);
  }
  printf("\n");

  for(i=0;i<lim-1;i++){
    for(j=i+1;j<lim;j++){
      if(arr[i]<arr[j]){
        lessflag=1;
        break;
      }
      else{
        greatflag=1;
        newi=i;
        break;
      }
    }
    if(greatflag==1){
      break;
    }
  }
  if(greatflag==1){
    for(i=newi;i<lim-1;i++){
    for(j=i+1;j<lim;i++){
      if(arr[i]>arr[j]){
        greatflag=2;
        break;
      }
      else{
        lessflag=0;
        break;
      }
    }
   }
  }
  if(lessflag==1 && greatflag==2){
    max=arr[0];
    for(i=0;i<lim;i++){
      for(j=i+1;j<lim;j++){
        if(arr[i]<arr[j]){
          max=arr[j];
          break;
        }
      }
    }
    printf("Bitomic and max is: %d\n",max);
  }
  else{
    printf("Cannot find maximum since it is not bitomic\n");
  }
}