struct Item
{
    int value;
    int weight;
}

static bool
comp(Item a, Item b)
{
    if (((double)a.value / a.weight) > ((double)b.value / b.weight))
    {
        return true;
    }
    return false;
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    sort(arr, arr + n, comp);
    double ans = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= W)
        {
            ans += arr[i].value;
            W = W - arr[i].weight;
        }
        else
        {
            ans += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }
    return ans;
}