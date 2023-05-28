

void printDivisors(int n){
	cout<<"The Divisors of "<<n<<" are:"<<endl;
	for(int i = 1; i <= n; i++)
		if(n % i == 0)
			cout << i << " ";
	cout << "\n";
}


// optimal
void printDivisorsOptimal(int n){

  cout<<"The Divisors of "<<n<<" are:"<<endl;
	for(int i = 1; i <= sqrt(n); i++)
		if(n % i == 0){
			cout << i << " ";
			if(i != n/i) cout << n/i << " "; // quotient
		}

	cout << "\n";
}


//sum of all divisors 1 to n

long long sumOfDivisors(int N)
{
    // Write Your Code here
    long long sum = 0;
    for(int i = 1;i<=N;i++){
        sum+=(N/i)*i;
    }
    return sum;
}
