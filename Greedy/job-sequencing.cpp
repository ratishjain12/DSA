static bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}
vector<int> JobScheduling(Job arr[], int n)
{
    // your code here
    vector<int> ans;

    sort(arr, arr + n, cmp);
    int maxDeadline = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, arr[i].dead);
    }

    int maxProfit = 0;
    int count = 0;

    vector<int> schedule(maxDeadline + 1, -1);
    for (int i = 0; i < n; i++)
    {
        int currJobId = arr[i].id;
        int currProfit = arr[i].profit;
        int currJobDeadline = arr[i].dead;
        for (int k = currJobDeadline; k > 0; k--)
        {
            if (schedule[k] == -1)
            {
                count++;
                maxProfit += currProfit;
                schedule[k] = currJobId;
                break;
            }
        }
    }
    ans.push_back(count);
    ans.push_back(maxProfit);
    return ans;
}