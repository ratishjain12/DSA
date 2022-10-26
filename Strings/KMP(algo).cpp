
#include <iostream>
#include<vector>
using namespace std;


vector<int>fillLPS(string str){
    int n=str.length(),len=0;
    vector<int>lps(n);
    lps[0] = 0;
    int i=1;
    while(i<n){
        if(str[i]==str[len])
        {len++;lps[i]=len;i++;}
        else
        {if(len==0){lps[i]=0;i++;}
            else{len=lps[len-1];}
        }
    }
    return lps;
}
int KMP(string pat,string txt){
    int N=txt.length();
    int M=pat.length();

    vector<int>lps = fillLPS(pat);
    int i=0,j=0;
    while(i<N){
        if(pat[j]==txt[i]){i++;j++;}

        if (j == M) {
            return i-j;
        }
        else if (i < N && pat[j] != txt[i]) {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
}

int main()
{
    string txt = "ababcababaad",pat="ababa";
    cout<<KMP(pat,txt);
    return 0;
}
