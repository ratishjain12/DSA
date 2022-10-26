#include<iostream>
using namespace std;

// if relative order matters
void rearrange(int arr[], int n) {
	    // code here
	    vector<int>pos;
	    vector<int>neg;
	    for(int i = 0;i<n;i++){
	        if(arr[i]>=0){
	            pos.push_back(arr[i]);
	        }else{
	            neg.push_back(arr[i]);
	        }
	    }
	    int j = 0;
	    for(int i = 0;i<n;i++){
	        if(i<pos.size()){
	            arr[j] = pos[i];
	            j++;
	        }
	        if(i<neg.size()){
	            arr[j] = neg[i];
	            j++;
	        }
	    }
}

//if relative order does not matter
void rearrange(int arr[], int n) {
    // code here
    int i = 0,j=n-1;
    while(i<j){
        while(i<=n-1 && arr[i]>=0){ // change if first number must be psotive
            i++;
        }
        while(j>=0 && arr[j]<0){ // change if first number must be positive
            j--;
        }
        if(i<j){
           swap(arr[i],arr[j]);
        }

    }
    int k = 0;
    while(k<n && i<n){
        swap(arr[k],arr[i]);
        i = i+1;
        k = k+2;
    }
}
