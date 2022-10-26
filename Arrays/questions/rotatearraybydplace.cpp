//right rotate
void reverse(vector<int>& arr,int i,int j){
    while(i<=j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}
void rotate(vector<int>& arr, int k) {
    if(arr.size() == 0 || arr.size()<2){
        return;
    }
    k = k%arr.size();
    reverse(arr,0,arr.size()-1);
    reverse(arr,0,k-1);
    reverse(arr,k,arr.size()-1);

}


//left rotate
void reverse(vector<int>& arr,int i,int j){
    while(i<=j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}
void rotate(vector<int>& arr, int k) {
    if(arr.size() == 0 || arr.size()<2){
        return;
    }
    k = k%arr.size();
    reverse(arr,0,k-1);
    reverse(arr,k,arr.size()-1);
    reverse(arr,0,arr.size()-1);

}
