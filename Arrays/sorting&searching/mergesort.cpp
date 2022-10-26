#include<iostream>
using namespace std;

// T.C -> O(nlogn) S.c -> O(n)
void merge(int arr[], int l,int mid, int r){
     // Your code here
     int first = mid-l+1;
     int second = r-mid;

     int firstArr[first];
     int secondArr[second];
     int k = l;
     for(int i = 0;i<first;i++){
         firstArr[i] = arr[k++];
     }
     k = mid + 1;
     for(int j = 0;j<second;j++){
         secondArr[j] =arr[k++];
     }

     int i = 0;
     int j = 0;
     k = l;
     while(i<first && j<second){
         if(firstArr[i]<=secondArr[j]){
             arr[ k++] = firstArr[i++];
         }else if(firstArr[i]>secondArr[j]){
             arr[ k++] = secondArr[j++];
         }
     }
     while(i<first){
         arr[ k++] = firstArr[i++];
     }
     while(j<second){
         arr[k++] = secondArr[j++];
     }

}

void mergeSort(int arr[], int l, int r){
        //code here
        if(l>=r){
            return;
        }
        int mid = l + (r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
}

int main(){
  int arr[] = {4,1,3,9,7};
  mergeSort(arr,0,4);
  for(int i = 0;i<5;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}
