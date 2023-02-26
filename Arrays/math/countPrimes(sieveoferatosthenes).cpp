
// return numbers of prime numbers strictly less than n
int countPrimes(int n)
{
    int count = 0;
    vector<bool> isPrime(n + 1, true); // create a array of size n+1 and mark all as true
    isPrime[0] = isPrime[1] = false;   // mark the composites as false
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i]) // check is i is true
        {

            for (int j = 2 * i; j <= n; j = j + i) // if i is true
            {

                isPrime[j] = false; // mark all the multiples of i as false
            }
        }
    }

    // now in the array isPrime all numbers marked as true are prime simply count them
    for (int i = 0; i < isPrime.size(); i++)
    {
        if (isPrime[i] == true)
        {
            if (i < n)
            {
                count++;
            }
        }
    }
    return count;
}