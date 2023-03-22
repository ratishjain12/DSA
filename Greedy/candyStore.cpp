vector<int> candyStore(int candies[], int N, int K)
{
    // Write Your Code here
    vector<int> ans(2, 0);
    sort(candies, candies + N);

    int buy = 0;
    int freeCandy = N - 1;
    int mini = 0;
    while (buy <= freeCandy)
    {
        mini = mini + candies[buy];
        buy++;
        freeCandy = freeCandy - K;
    }
    int max = 0;
    buy = N - 1;
    freeCandy = 0;
    while (freeCandy <= buy)
    {
        max = max + candies[buy];
        buy--;
        freeCandy = freeCandy + K;
    }
    ans[0] = mini;
    ans[1] = max;
    return ans;
}