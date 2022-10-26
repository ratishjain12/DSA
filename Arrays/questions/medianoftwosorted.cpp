#include<iostream>
using namespace std;

//median of two sorted array of different size.
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int i = 0;
    int j = 0;
    vector<int>merge;
    while(i<nums1.size() && j < nums2.size()){
        if(nums1[i]<nums2[j]){
            merge.push_back(nums1[i++]);
        }else if(nums1[i]>nums2[j]){
            merge.push_back(nums2[j++]);
        }else{
            merge.push_back(nums1[i++]);
        }
    }
    while(i<nums1.size()){
        merge.push_back(nums1[i++]);
    }
    while(j<nums2.size()){
        merge.push_back(nums2[j++]);
    }

    if(merge.size()%2 == 1){
        return merge[merge.size()/2];
    }
    return (double)(merge[merge.size()/2]+merge[(merge.size()/2)-1])/2;

}

//median of two sorted array of same size.

double findMedian(int arr1[],int arr2[],int n){
      int i = 0,j=0,count;
      int m1=m2=-1;
      for(count = 0;count<=n;count++){
        if(i == n){
          m1 = m2;
          m2 = arr2[0];
        }
        if(j == n){
          m1 = m2;
          m2 = arr1[0];
        }
        if(arr1[i]<=arr2[j]){
          m1 = m2;
          m2 = arr1[i];
          i++;
        }else{
          m1 = m2;
          m2 = arr2[j];
          j++;
        }
      }
      return (m1+m2)/2;
}
