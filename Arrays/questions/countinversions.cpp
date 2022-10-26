
#include<iostream>
using namespace std;

//T.C -> O(NLogN) S.C-> O(N)
int merge(int arr[], int l,int mid, int r){
     // Your code here
     int inv = 0;
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
             inv+=first-i;
         }
     }
     while(i<first){
         arr[ k++] = firstArr[i++];
     }
     while(j<second){
         arr[k++] = secondArr[j++];
     }
     return inv;

}

int mergeSort(int arr[], int l, int r){
        //code here
        int inv = 0;
        if(l>=r){
            return inv;
        }
        int mid = l + (r-l)/2;
        inv+=mergeSort(arr,l,mid);
        inv+=mergeSort(arr,mid+1,r);
        inv+=merge(arr,l,mid,r);
        return inv;
}

int main(){
  int arr[] = {2, 4, 1, 3, 5};
  cout<<mergeSort(arr,0,4);
  return 0;
}
