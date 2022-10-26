#include<iostream>
using namespace std;


// T.C -> O(N2) S.C -> O(1)
int select(int arr[], int i,int n)
{
    // code here such that selectionSort() sorts arr[]
    int mini = i;
    for(int j = i+1;j<n;j++){
        if(arr[mini]>arr[j]){
            mini = j;
        }
    }
    return mini;

}

void selectionSort(int arr[], int n)
{
   //code here
   for(int i = 0;i<n;i++){
       int mini = select(arr,i,n);
       int temp = arr[mini];
       arr[mini] = arr[i];
       arr[i] = temp;
   }

}

int main(){
  int arr[] = {4,1,3,9,7};
  selectionSort(arr,5);
  for(int i = 0;i<5;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}
