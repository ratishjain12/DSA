#include<iostream>
#include<map>;
using namespace std;



int getPairsCount(int arr[], int n, int k) {
    // code here
    int count = 0;
    map<int,int>mp;
    for(int i = 0;i<n;i++){
        if(mp.find(k-arr[i])!=mp.end()){
            count+=mp[k-arr[i]];
        }
        mp[arr[i]]++;
    }

    return count;
}

int main(){
  int a[] = {1, 5, 7, 1};
  cout<<getPairsCount(a,4,6);
  return 0;
}
