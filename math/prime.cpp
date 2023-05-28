

bool checkforprime(int N){
  for(int i = 2;i<sqrt(N);i++){
      if(N%i == 0){
        return false;
      }
  }
  return true;
}

int main(){
  int n;
  cout<<"Enter a number: ";
  cin>>n;
  if(n!=1 && checkforprime(N)){
    cout<<"it is not prime";
  }else{
    cout<<"it is prime";
  }
  return 0;
}
