// you are given two strings find length of longest substring s that can be converted to t such that cost is <= maxCost 
// cost is abs(s[i] - t[i])
int equalSubstring(string s, string t, int maxCost) {
    int l = 0;
    int r = 0;
    int cost = 0;
    int len = 0;
    for(;r<s.size();r++){
            cost+=abs(s[r]-t[r]);
            while(cost  > maxCost){
                cost-= abs(s[l] - t[l]);
                l++;
            }
            len = max(len,r-l+1);
    }
    return len;
}