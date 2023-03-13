// you can buy and sell any number of times only condition is you can hold
//  only one share at a time
int maxProfit(vector<int> &prices)
{
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i - 1])
        {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}

// DP approach
int solve(int index, int buy, vector<int> &prices, vector<vector<int>> &dp)
{
    if (index == prices.size())
    {
        return 0;
    }
    if (dp[index][buy] != -1)
        return dp[index][buy];
    int profit = 0;
    if (buy)
    {
        int buyKaro = -prices[index] + solve(index + 1, 0, prices, dp);
        int skipKaro = 0 + solve(index + 1, 1, prices, dp);
        profit = max(buyKaro, skipKaro);
    }
    else
    {
        int sellKaro = prices[index] + solve(index + 1, 1, prices, dp);
        int skipKaro = 0 + solve(index + 1, 0, prices, dp);
        profit = max(sellKaro, skipKaro);
    }
    return dp[index][buy] = profit;
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return solve(0, 1, prices, dp);
}