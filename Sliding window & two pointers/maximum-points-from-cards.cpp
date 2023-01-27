int maxScore(vector<int> &cardPoints, int k)
{
    int totalSum = 0;
    int sum = 0;
    int n = cardPoints.size();
    int rem = n - k;
    for (int i = 0; i < n; i++)
    {
        totalSum += cardPoints[i];
    }
    for (int i = 0; i < n - k; i++)
    {
        sum += cardPoints[i];
    }
    int mn = sum;
    for (int i = rem; i < n; i++)
    {
        sum -= cardPoints[i - rem];
        sum += cardPoints[i];
        mn = min(mn, sum);
    }

    return totalSum - mn;
}