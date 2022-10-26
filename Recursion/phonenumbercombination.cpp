
#include<iostream>
#include<vector>
using namespace std;

/*

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
Return the answer in any order.

*/
void help(int i,string &s,string &temp,vector<string>&ans,unordered_map<char,string>&mp){
    if(s == "") return;
    if(i == s.size()){
        ans.push_back(temp);
        return;
    }
    string str = mp[s[i]];
    for(int j=0;j<str.size();j++){
        temp.push_back(str[j]);
        help(i+1,s,temp,ans,mp);
        temp.pop_back();
    }

}
vector<string> letterCombinations(string digits) {
    unordered_map<char,string>mp;
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";

    string temp;
    vector<string>ans;
    help(0,digits,temp,ans,mp);
    return ans;
}
