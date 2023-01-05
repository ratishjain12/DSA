// a subarray is said to be nice if it has k odd numbers in it

int atMost(vector<int> &nums, int k)
{
    if (k < 0)
        return 0;
    int i = 0;
    int j = 0;
    int res = 0;
    int sum = 0;
    while (j < nums.size())
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
int numberOfSubarrays(vector<int> &nums, int k)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 0)
        {
            nums[i] = 0; // convert all even numbers to zero
        }
        else
        {
            nums[i] = 1; // convert all odd numbers to one
        }
    }
    return atMost(nums, k) - atMost(nums, k - 1); // number of subarrays of sum equals k
}