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

// merge two sorted arrays without extra space
// modify arr1 so that it contains first N sorted elements and arr2 contains next N sorted elements

void merge(long long arr1[], long long arr2[], int n, int m) { 
    // code here 
    int left = n-1;
    int right = 0;
    while(left>=0 && right<m){
        if(arr1[left] > arr2[right]){
            swap(arr1[left],arr2[right]);
            left--;
            right++;
        }else{
            break;
        }
    }
    
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
} 



