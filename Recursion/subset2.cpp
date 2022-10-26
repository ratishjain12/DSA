#include <iostream>
#include <vector>
using namespace std;

void help(int i, vector<int> &nums, vector<int> &subset, vector<vector<int>> &ans)
{
  if (i == nums.size())
  {
    ans.push_back(subset);
    return;
  }
  subset.push_back(nums[i]);
  help(i + 1, nums, subset, ans);

  subset.pop_back();

  while (i + 1 < nums.size() && nums[i] == nums[i + 1])
    i++;

  help(i + 1, nums, subset, ans);
  return;
}

vector<vector<int>> subsets(vector<int> &nums)
{
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  vector<int> subset;
  help(0, nums, subset, ans);
  return ans;
}
