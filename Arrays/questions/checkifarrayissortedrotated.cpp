// this if array is sorted in non decreasing order and then rotated
bool check(vector<int> &nums)
{
    int cnt = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] > nums[i])
        {
            cnt++;
        }
    }
    if (nums[nums.size() - 1] > nums[0])
    {
        cnt++;
    }
    return cnt <= 1;
}

// another simpler approach
bool check(vector<int> &nums)
{
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > nums[(i + 1) % nums.size()])
        {
            cnt++;
        }
    }
    return cnt <= 1;
}

//gfg version where both non decreasing and non increasing will be given

bool isIncreasing(int arr[],int num){
    int cnt = 0;
    if(arr[0] < arr[num-1]) return false;
    for(int i = 1;i<num;i++){
        if(arr[i-1] > arr[i]){
            cnt++;
        }
    }
    
    if(arr[num-1] > arr[0]){
        cnt++;
    }
    return cnt<=1;
}



bool isDecreasing(int arr[],int num){
    int cnt = 0;
    if(arr[0] > arr[num-1]) return false;
    for(int i = 1;i<num;i++){
        if(arr[i-1] < arr[i]){
            cnt++;
        }
    }
    
    if(arr[num-1] < arr[0]){
        cnt++;
    }
    
    return cnt<=1;
}
bool checkRotatedAndSorted(int arr[], int num){
    
    // Your code here
    if(isIncreasing(arr,num)) return true;
    if(isDecreasing(arr,num)) return true;
    return false;
}
