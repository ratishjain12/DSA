
#include<iostream>
#include<set>
using namespace std;

/*
Given a string s, find the length of the longest substring without repeating characters.
*/


int lengthOfLongestSubstring(string s) {
    if(s==""){
        return 0;
    }
    set<char>st;
    int i=0,j=0,maxLen = INT_MIN;
    while(j<s.size() && i<s.size()){
        if(st.find(s[j]) == st.end()){ //
            st.insert(s[j++]);

            maxLen = max(maxLen,j-i);

        }else{
            st.erase(s[i]); // erasing original ith element and moving forward
            i++;
        }
    }
    return maxLen;
}
