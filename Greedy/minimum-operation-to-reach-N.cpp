int minOperation(int n)
{
    // code here.
    int ans = 0;

    while (n != 0)
    {
        if (n % 2 != 0)
        {
            ans++;
            n--;
        }
        if (n == 0)
        {
            break;
        }

        n /= 2;
        ans++;
    }

    return ans;
}