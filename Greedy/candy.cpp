// a leetcode hard problem
int candy(vector<int> &ratings)
{
    vector<int> left(ratings.size(), 1);
    for (int i = 1; i < ratings.size(); i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            left[i] = left[i - 1] + 1;
        }
    }
    int right = 1;
    for (int j = ratings.size() - 2; j >= 0; j--)
    {
        if (ratings[j] > ratings[j + 1])
        {
            right++;
            left[j] = max(left[j], right);
        }
        else
        {
            right = 1;
        }
    }

    int sum = 0;
    for (int i = 0; i < left.size(); i++)
    {
        sum += left[i];
    }
    return sum;
}