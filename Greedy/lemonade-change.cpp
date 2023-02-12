// checkout leetcoode question page

bool lemonadeChange(vector<int> &bills)
{
    map<int, int> mp;
    for (int i = 0; i < bills.size(); i++)
    {
        if (bills[i] == 5)
        {
            mp[bills[i]]++;
        }
        if (bills[i] == 10)
        {
            mp[bills[i]]++;
            if (mp[5] > 0)
            {
                mp[5]--;
            }
            else
            {
                return false;
            }
        }
        if (bills[i] == 20)
        {
            if (mp[5] > 0 && mp[10] > 0)
            {
                mp[5]--;
                mp[10]--;
            }
            else if (mp[5] >= 3)
            {
                mp[5] -= 3;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}