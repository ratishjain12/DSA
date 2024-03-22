

vector<int>twoNonRepeating(vector<int>num){
    int xxory = 0;
    for(int i : num){
        xxory^=i;
    }

    int rightMostBitMask = ;

    int x = 0;
    int y = 0;
    for(int i : num){
        if(i & rightMostBitMask){
            x^=i;
        }else{
            y^=i;
        }
    }

    if(x<y) return {x,y};
    else return {y,x};
}