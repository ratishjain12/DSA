#include<iostream>
using namespace std;

// T.C -> O(N^2)
void bubbleSort(int arr[],int n){
  for(int i = 0;i<n-1;i++){
    for(int j = 0;j<n-i-1;j++){
      if(arr[j]>arr[j+1]){
        swap(arr[j],arr[j+1]);
      }
    }
  }
}

int main(){
  int arr[] = {4,1,3,9,7};
  bubbleSort(arr,5);
  for(int i = 0;i<5;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}
