int lengthOfLastWord(string s) {
    int count = 0;
    int flag = 0;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i] == ' ' && flag) {
            break;
        }
        if(s[i] != ' '){
            flag = 1;
            count++;
            
        }
    }
    return count;
}