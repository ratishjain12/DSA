#include <iostream>
#include<unordered_map>
using namespace std;

string concatenatedString(string s1, string s2)
{
    // Your code here
    unordered_map<char,int>mp1,mp2;
    for(int i=0;i<s1.size();i++){
        mp1[s1[i]]++;
    }
    for(int i=0;i<s2.size();i++){
        mp2[s2[i]]++;
    }
    string ans = "";
    for(int i=0;i<s1.size();i++){
        if(mp2.find(s1[i]) == mp2.end()){
            ans+=s1[i];

        }
    }
    for(int i=0;i<s2.size();i++){
        if(mp1.find(s2[i]) == mp1.end()){
            ans+=s2[i];

        }
    }
   if(ans.size()!=0){
        return ans;
    }

   return to_string(-1);

}

int main(){
  string s1 = "abcs";
  string s2 = "cxzca";
  cout<<concatenatedString(s1,s2);
  return 0;
}
