

// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times.
int majorityElement(int a[], int size)
    {
        // your code here
        int ans_index = 0;
        int cnt = 1;
        for(int i = 1;i<size;i++){
            if(a[ans_index] == a[i]){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt == 0){
                ans_index = i;
                cnt = 1;
            }
        }
        cnt = 0;
        for(int i = 0;i<size;i++){
            if(a[i] == a[ans_index]){
                cnt++;
            }
        }
        if(cnt>size/2) return a[ans_index];
        return -1;

    }
