int characterReplacement(string s, int k) {
    int r = 0;
    int l = 0;
    int count[26] = {0};
    int len = 0;
    int maxf = 0;
    for(;r<s.size();r++){
        count[s[r] - 'A']++;
        maxf = max(maxf,count[s[r]-'A']);
        while((r-l+1) - maxf > k){
            count[s[l] - 'A']--;
            l++;
        }
        len = max(len,r-l+1);

    }
    return len;
}