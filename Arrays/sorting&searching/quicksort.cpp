
#include<iostream>
using namespace std;


int partition (int arr[], int low, int high){
       // Your code here
       int pivot = arr[low];
       int i = low;
       int j = high;
       while(i<j){
           while(arr[i]<=pivot && i<=high){
               i++;
           }
           while(arr[j]>pivot && j>=low){
               j--;
           }
           if(i<j){
               swap(arr[i],arr[j]);
           }

       }
       swap(arr[j],arr[low]);
       return j;
}

void quickSort(int arr[], int low, int high){
        // code here
        if(low<high){
            int pivot = partition(arr,low,high);
            quickSort(arr,low,pivot-1);
            quickSort(arr,pivot+1,high);
        }
}
