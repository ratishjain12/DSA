string longestCommonPrefix(vector<string>& strs) {
    sort(strs.begin(),strs.end());
    string n = strs[0];
    string m = strs[strs.size()-1];

    string ans="";
    for(int i=0;i<n.size();i++){
        if(n[i] == m[i]){
            ans+=n[i];
        }else{
            break;
        }
    }

    return ans;
}

// another approach without sorting
string longestCommonPrefix(vector<string>& strs) {
    int ans = strs[0].length();
    int n = strs.size();
    for(int i = 1;i<n;i++){
        int j = 0;
        while(j<strs[i].length() && strs[i][j] == strs[0][j]) j++;
        ans = min(ans,j);
    }

    return strs[0].substr(0,ans);
}
