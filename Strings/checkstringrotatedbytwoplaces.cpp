#include<iostream>
using namespace std;

//formula for clockwise rotation by two places s1[i]!=s2[(i+2)%n] --> clockwise = false
//formula for anti-clockwise rotation by two places s1[(i+2)%n]!=s2[i] --> anticlockwise = false

bool isRotated(string str1, string str2) {
        // Your code here
        if(str1.length()!=str2.length()) return false;
        int n = str1.length();
        bool clockwise = true,anticlockwise = true;
        for(int i=0;i<n;i++){
            if(str1[i] != str2[(i+2)%n]){
                clockwise = false;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(str1[(i+2)%n] != str2[i]){
                anticlockwise = false;
                break;
            }
        }
        return clockwise||anticlockwise;
}

int main(){
  string s1 = "amazon";
  string s2 = "azonam";

  return 0;
}
