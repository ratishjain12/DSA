// input - aaabbaaccd
// output - ad
// remove pairs of duplicates consecutive  and join remaining string 

string removePair(string str){
    // Your code here
    stack<char>st;
    st.push(str[0]);
    string res = "";
    for(int i = 1;i<str.size();i++){
        if(st.size() != 0 && st.top() == str[i]){
            st.pop();
        }else{
            st.push(str[i]);
        }
    }
    
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    
    reverse(res.begin(),res.end());
    return res;
}


// remove consecutive duplicates 
// input - aaaaaabaabccccccc
// output - abc
string removeConsecutiveDuplicates(string s){
    // Your code here
    stack<char>st;
    st.push(s[0]);
    string res = "";
    res+=s[0];
    for(int i = 1;i<s.size();i++){
        if(st.top() != s[i]){
            st.push(s[i]);
            res+=s[i];
        }
    }
    
    return res;
}