int findMin(int arr[], int n)
{
	// complete the function here
	int l = 0;
	int h = n - 1;
	if (arr[l] <= arr[h])
	{
		return arr[0];
	}
	while (l <= h)
	{
		int mid = (l + h) >> 1;
		if (arr[mid] > arr[mid + 1])
		{
			return arr[mid + 1];
		}
		if (arr[mid] < arr[mid - 1])
		{
			return arr[mid];
		}
		if (arr[l] <= arr[mid])
		{
			l = mid + 1;
		}
		else
		{
			h = mid - 1;
		}
	}
	return -1;
}
// without binary search method
int minNumber(int arr[], int low, int high)
{
	// Your code here
	for (int i = high; i >= 0; i--)
	{
		if (arr[i] < arr[i - 1])
		{
			return arr[i];
		}
	}
	return arr[0];
}