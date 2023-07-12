//import question there are multiple approaches for this problem
int missingNumber(int arr[], int n) { 
    // Your code here
    for(int i = 0;i<n;i++){
        int correctInd = arr[i] - 1;
        while(arr[i] > 0 && arr[i] <= n && arr[i] != arr[correctInd]){
            swap(arr[i],arr[correctInd]);
            correctInd = arr[i]-1;
        }
    }
    
    for(int i = 0;i<n;i++){
        if(arr[i] != i+1){
            return i+1;
        }
    }
    return n+1;
} 