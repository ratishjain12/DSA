#include<iostream>
using namespace std;

// basic solution
void sort012(int a[], int n)
    {
        // code here
        int cnt0 = 0,cnt1 = 0,cnt2 =0;
        for(int i = 0;i<n;i++){
            switch(a[i]){
                case 0:
                    cnt0++;
                    break;
                case 1:
                    cnt1++;
                    break;
                case 2:
                    cnt2++;
                    break;
            }
        }

        int i = 0;
        while(cnt0>0){
            a[i++] = 0;
            cnt0--;
        }
        while(cnt1>0){
            a[i++] = 1;
            cnt1--;
        }
        while(cnt2>0){
            a[i++] = 2;
            cnt2--;
        }
}


//Dutch national flag algo
