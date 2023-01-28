// moore's voting algorithm
int majorityElement(int a[], int n)
{

    // your code here
    int ans = a[0], freq = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == ans)
        {
            freq++;
        }
        else
        {
            freq--;
            if (freq == 0)
            {
                ans = a[i];
                freq = 1;
            }
        }
    }

    freq = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == ans)
        {
            freq++;
        }
    }

    if (freq > (n / 2))
    {
        return ans;
    }
    return -1;
}