// normal approach
int longestOnes(vector<int> &nums, int k)
{
    int i = 0;
    int j = 0;
    int zeroCount = 0;
    int result = 0;
    while (j < nums.size())
    {
        if (nums[j] == 0)
            zeroCount++;
        while (zeroCount > k)
        {
            if (nums[i] == 0)
            {
                zeroCount--;
            }
            i++;
        }
        result = max(result, j - i + 1);
        j++;
    }
    return result;
}

// highly intuitive
int longestOnes(vector<int> &nums, int k)
{
    int i = 0;
    int j = 0;
    while (j < nums.size())
    {
        if (nums[j] == 0)
        {
            k--;
        }
        if (k < 0)
        {
            if (nums[i] == 0)
            {
                k++;
            }
            i++;
        }
        j++;
    }
    return j - i;
}