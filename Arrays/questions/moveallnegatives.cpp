#include<iostream>
using namespace std;


void segregateElements(int arr[],int n)
{
    // Your code goes here
    int a[n];
    int count = 0;
    for(int i = 0;i<n;i++){
        if(arr[i]>=0){
            a[count++] = arr[i];
        }
    }
    for(int i = 0;i<n;i++){
        if(arr[i]<0){
            a[count++] = arr[i];
        }
    }
    for(int i = 0;i<n;i++){
        arr[i] = a[i];
    }
}
int main(){
  int arr[] = {1, -1, 3, 2, -7, -5, 11, 6};
  segregateElements(arr,8);
  for(int i = 0;i<8;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}
