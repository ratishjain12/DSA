

int main(){
  int n;
  int  i = 0;
  int ans;
  while(n!=0){
    int bit = n&1; // get right bit as
    ans += (bit*pow(10,i));
    i++;
    n = n>>1;
  }

  return ans;
}
