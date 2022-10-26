string armstrongNumber(int n){
        // code here
        int sum = 0;
        int temp = n;
        while(temp){
            int rem = temp%10;
            sum += pow(rem,3);
            temp = temp/10;
        }
        if(sum == n){
            return "Yes";
        }
        return "No";
}
