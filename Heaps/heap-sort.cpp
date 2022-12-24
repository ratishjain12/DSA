#include <iostream>
using namespace std;

void maxHeapify(vector<int> &nums, int i, int n)
{
    int li = 2 * i + 1;
    int ri = 2 * i + 2;
    int greatest = i;
    if (li < n && nums[li] > nums[greatest])
    {
        greatest = li;
    }
    if (ri < n && nums[ri] > nums[greatest])
    {
        greatest = ri;
    }
    if (greatest != i)
    {
        swap(nums[greatest], nums[i]);
        maxHeapify(nums, greatest, n);
    }
}
void buildHeap(vector<int> &nums, int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        maxHeapify(nums, i, n);
    }
}
vector<int> sortArray(vector<int> &nums)
{
    int n = nums.size();
    buildHeap(nums, n);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(nums[0], nums[i]);
        maxHeapify(nums, 0, i);
    }
    return nums;
}