int catchThieves(char arr[], int n, int k)
{
    // Code here
    int ans = 0;
    vector<int> police, thieves;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 'P')
        {
            police.push_back(i);
        }
        else
        {
            thieves.push_back(i);
        }
    }

    int i = 0, j = 0;
    while (i < police.size() && j < thieves.size())
    {
        if (abs(police[i] - thieves[j]) <= k)
        {
            i++;
            j++;
            ans++;
        }
        else if (thieves[j] < police[i])
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    return ans;
}