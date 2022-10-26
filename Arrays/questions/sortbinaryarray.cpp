
#include<iostream>
using namespace std;

// TC = O(N)
void binSort(int A[], int n)
{
    int i = 0,j=n-1;
    while(i<=j){
        while(i<=n-1 && A[i] == 0){
            i++;
        }
        while(j>=0 && A[j] != 0){
            j--;
        }
        if(i<j){
            swap(A[i],A[j]);
        }
    }
}

// similar question segregate 0's and 1';
// segregate postivie and negative
// segregate even and odd
