#include <iostream>
using namespace std;

// if relative order matters
void rearrange(int arr[], int n)
{
	// code here
	vector<int> pos;
	vector<int> neg;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] >= 0)
		{
			pos.push_back(arr[i]);
		}
		else
		{
			neg.push_back(arr[i]);
		}
	}
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (i < pos.size())
		{
			arr[j] = pos[i];
			j++;
		}
		if (i < neg.size())
		{
			arr[j] = neg[i];
			j++;
		}
	}
}

// if relative order does not matter
void rearrange(int arr[], int n)
{
	// code here
	int i = 0, j = n - 1;
	while (i < j)
	{
		while (i <= n - 1 && arr[i] >= 0)
		{ // change if first number must be postive
			i++;
		}
		while (j >= 0 && arr[j] < 0)
		{ // change if first number must be positive
			j--;
		}
		if (i < j)
		{
			swap(arr[i], arr[j]);
		}
	}
	int k = 0;
	while (k < n && i < n)
	{
		swap(arr[k], arr[i]);
		i = i + 1;
		k = k + 2;
	}
}

// if number of positives and negatives are same
vector<int> rearrangeArray(vector<int> &nums)
{
	int n = nums.size();
	vector<int> ans(n, 0);
	int pos = 0, neg = 1;
	for (int i = 0; i < n; i++)
	{
		if (nums[i] > 0)
		{
			ans[pos] = nums[i];
			pos += 2;
		}
		else
		{
			ans[neg] = nums[i];
			neg += 2;
		}
	}
	return ans;
}
