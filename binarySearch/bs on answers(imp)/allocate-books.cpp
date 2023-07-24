// similar to capacity to ship packages within d days
bool isPossible(int A[],int N, int maxPages,int M){
    int cnt = 1;
    int pagesStudent = 0;
    for(int i = 0;i<N;i++){
        if(pagesStudent + A[i] <= maxPages){
            pagesStudent+=A[i];
        }else{
            cnt++;
            pagesStudent = A[i];
        }
    }
    if(cnt<=M) return true;
    return false;
}



int findPages(int A[], int N, int M) 
{
    //code here
    
    if(M > N){
        return -1;
    }
    
    int l = INT_MIN;
    int h = 0;
    for(int i = 0;i<N;i++){
        l = max(l,A[i]);
        h += A[i];
    }
    
    int ans = -1;
    while(l<=h){
        int mid = (l+h)/2;
        if(isPossible(A,N,mid,M)){
            ans = mid;
            h = mid-1;
        }else{
            l = mid+1;
        }
    }
    
    return ans;
}