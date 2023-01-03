bool check(vector<int> &nums)
{
    int cnt = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] > nums[i])
        {
            cnt++;
        }
    }
    if (nums[nums.size() - 1] > nums[0])
    {
        cnt++;
    }
    return cnt <= 1;
}

// another simpler approach
bool check(vector<int> &nums)
{
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > nums[(i + 1) % nums.size()])
        {
            cnt++;
        }
    }
    return cnt <= 1;
}