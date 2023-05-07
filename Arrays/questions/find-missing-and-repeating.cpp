/*
 One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs 
 twice in array.Find these two numbers.
*/

// solution 1 T.C - O(N) S.C - O(N)
vector<int> findTwoElement(vector<int> arr, int n) {
    // code here
    vector<int>ans;
    
    int missing = -1;
    int repeating = -1;
    
    vector<int>checker(n+1,0);
    for(int i = 0;i<n;i++){
        checker[arr[i]]++;
    }
    for(int i = 1;i<checker.size();i++){
        if(checker[i] > 1){
            repeating = i;
        }else if(checker[i] == 0){
            missing = i;
        }
        
        if(repeating != -1 && missing != -1){
            break;
            
        }
    }
    return {repeating,missing};
}

// solution 2 T.C - O(N) S.C - O(1)

    vector<int> findTwoElement(vector<int> nums, int n) {
        // code here
        // BST SOLUTION AND EASY TOO :)
        
        // Calculating Actual Sum Of nums

        long long int S1 = 0;   // Stores nums sum
        long long int S2 = 0;   // Stores nums square sum
        for(int i=0; i<n; i++){
            S1 += (long long int)nums[i];
            S2 += (long long int)nums[i]*(long long int)nums[i];
        }
        
        //Calculating the sum and (square)sum from 1 to N
        long long int S1N = (n*(n+1))/2;            // Gives the sum of 1->n
        long long int S2N = (n*(n+1)*(2*n+1))/6;    // Gives squares sum of 1->n
    
    
        // Math Equation
        long long int x = 0, y = 0;
        long long int val1 = S1 - S1N;      // X-Y = val1
        long long int val2 = S2 - S2N;
        val2 = val2 / val1;             // X+Y = val2
        x = (val1 + val2)/2;
        y = x - val1;
    
        // Finally return the elements
        return {(int)x, (int)y};
    }
     
