/*Find the second least occurring element and second most occurring element in an array
*/


#include <stdio.h>
int main(void) {
  int a[100],i,j,lim,count,bvalue,sbvalue=0,sbcount=0,bcount=0,first,tempval,tempcount,ccount=999,smalval=0,sscount=0,ssvalue=0;
  printf("enter limit:\n");
  scanf("%d",&lim);
  printf("enter elements:\n");
  for(i=0;i<lim;i++){
    scanf("%d",&a[i]);
  }
  printf("\n");
  //check large count
  for(i=0;i<lim;i++){
    first=a[i];
    count=0;
    for(j=0;j<lim;j++){
      if(first==a[j]){
        count++;
      }
      else{
        continue;
      }
    }
    if(bcount<count){
      bvalue=a[i];
      bcount=count;
    }
  }

  //check 2 most occurring
  for(i=0;i<lim;i++){
    first=a[i];
    count=0;
    for(j=0;j<lim;j++){
      if(first==a[j]){
        count++;
      }
      else{
        continue;
      }
    }

    if(count<bcount && sbcount<count){
      sbcount = count;
      sbvalue= first;
    }
  }

//check small count
  for(i=0;i<lim;i++){
    first = a[i];
    count=0;
    for(j=0;j<lim;j++){
      if(first == a[j]){
        count++;
      }
      else{
        continue;
      }
    }
    if(ccount>count){
      smalval = first;
      ccount=count;
    }
  }

  //check 2nd least occuring
  for(i=0;i<lim;i++){
    first=a[i];
    count=0;
    for(j=0;j<lim;j++){
      if(first==a[j]){
        count++;
      }
      else{
        continue;
      }
    }

    if(count>ccount && sscount<count && count<sbcount){
      sscount = count;
      ssvalue= first;
    }
  }
  if(ssvalue==0){
    ssvalue=sbvalue;
  }
  printf("Second least occurring number:%d\n",ssvalue);
  printf("Second most occurring number:%d\n",sbvalue);
  printf("\n");

}