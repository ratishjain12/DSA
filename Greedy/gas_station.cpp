// also known as circular tour in gfg

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
        return -1;
    int n = gas.size();
    int remaining_fuel = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        remaining_fuel += gas[i] - cost[i];
        if (remaining_fuel < 0)
        {
            ans = i + 1;
            remaining_fuel = 0;
        }
    }
    return ans;
}