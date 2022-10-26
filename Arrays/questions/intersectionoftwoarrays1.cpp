
/* Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must
be unique and you may return the result in any order. */
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int>ans;
    set<int>s;
    for(int i = 0;i<nums1.size();i++){
        s.insert(nums1[i]);
    }
    for(int i = 0;i<nums2.size();i++){
        if(s.find(nums2[i]) != s.end()){
            ans.push_back(nums2[i]);
        }
        s.erase(nums2[i]);
    }
    return ans;
}
