
// leetcode HARD
// given 2D vector where each element is a vector defining width,height and lenght
// cuboids[i] = [Wi,Hi,Li] and cuboid can be rotated

bool check(vector<int> &base, vector<int> &newBox)
{
    if (newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
    {
        return true;
    }
    return false;
}

int longestSubsequence(int n, vector<vector<int>> &cuboids)
{

    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);
    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || check(cuboids[curr], cuboids[prev])) // check for conditions for the box to be stacked
            {
                include = cuboids[curr][2] + nextRow[curr + 1]; // curr+1 to make sure to change preve
            }
            int exclude = nextRow[prev + 1]; // prev + 1 for no negative value
            currRow[prev + 1] = max(include, exclude);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}

int maxHeight(vector<vector<int>> &cuboids)
{
    for (auto &i : cuboids)
    {
        sort(i.begin(), i.end()); // sort each cuboids dimensions
    }
    sort(cuboids.begin(), cuboids.end()); // sort on the basis of width or length
    return longestSubsequence(cuboids.size(), cuboids);
}