#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Data
{
public:
    int val, apos, vpos;
    Data(int d, int ap, int vp)
    {
        val = d;
        apos = ap;
        vpos = vp;
    }
};

struct mycomp
{
    bool operator()(Data d1, Data d2)
    {
        return d1.val > d2.val;
    }
};
vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    // code here
    vector<int> ans;
    priority_queue<Data, vector<Data>, mycomp> pq;
    for (int i = 0; i < k; i++)
    {
        Data d(arr[i][0], i, 0);
        pq.push(d);
    }
    while (!pq.empty())
    {
        Data curr = pq.top();
        pq.pop();
        ans.push_back(curr.val);
        int ap = curr.apos;
        int vp = curr.vpos;
        if (vp + 1 < arr[ap].size())
        {
            Data d(arr[ap][vp + 1], ap, vp + 1);
            pq.push(d);
        }
    }
    return ans;
}