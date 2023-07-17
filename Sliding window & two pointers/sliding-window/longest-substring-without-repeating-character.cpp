// we maintain a set and as set does not allow duplicates
// and use sliding window 
int lengthOfLongestSubstring(string s) {
    set<char>st;
    int l = 0;
    int r = 0;
    int len = 0;
    for(;r<s.size();r++){
        while(st.find(s[r]) != st.end()){
            st.erase(s[l]);
            l++;
        }
        st.insert(s[r]);
        len = max(len,r-l+1); //length of subarray is r-l+1;
    }

    return len;
}