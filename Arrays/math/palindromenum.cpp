string is_palindrome(int n){
		    // Code here.
		    int temp = n;
		    int sum = 0;

		    while(temp>0){
		        int rem = temp%10;
		        sum = sum*10 + rem;
		        temp = temp/10;
		    }
		    if(sum == n){
		        return "Yes";
		    }
		    return "No";
}
