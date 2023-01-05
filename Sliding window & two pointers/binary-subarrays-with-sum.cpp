// prefix sum method
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    unordered_map<int, int> prevSum;
    int count = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == goal)
        {
            count++;
        }
        if (prevSum.find(sum - goal) != prevSum.end())
        {
            count += prevSum[sum - goal];
        }
        prevSum[sum]++;
    }
    return count;
}

// sliding window technique

int atMost(vector<int> &nums, int k)
{
    if (k < 0)
    {
        return 0;
    }
    int res = 0;
    int i = 0;
    int j = 0;
    int sum = 0;
    int n = nums.size();
    while (j < n)
    {
        sum += nums[j];
        while (sum > k)
        {
            sum -= nums[i];
            i++;
        }
        res += j - i + 1;
        j++;
    }
    return res;
}
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return atMost(nums, goal) - atMost(nums, goal - 1);
}