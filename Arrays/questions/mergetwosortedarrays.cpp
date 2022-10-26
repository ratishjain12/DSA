#include<iostream>
using namespace std;

void merge(int a[],int n,int b[],int m,int c[]){
     int i = 0,j=0,k=0;
     while(i<n && j<m){
       if(a[i]<b[j]){
         c[k++] = a[i++];
       }else{
         c[k++] = b[j++];
       }
     }
     while(i<n){
       c[k++] = a[i++];
     }
     while(j<m){
       c[k++] = b[j++];
     }
}

int main(){
  int a[] = {1,2,3,4};
  int b[] = {5,6,7,8};
  int c[8];
  merge(a,4,b,4,c);
  for(int i=0;i<8;i++){
    cout<<c[i]<<" ";
  }
  return 0;
}
