
#include <iostream>
#include <vector>
using namespace std;

void help(int i, vector<string> &ans, string &s)
{

  if (i == s.size())
  {
    ans.push_back(s);
    return;
  }

  for (int pos = i; pos < s.size(); i++)
  {
    swap(s[pos], s[i]);
    help(i + 1, ans, s);
    swap(s[pos], s[i]);
  }
}

vector<string> permutations(string s)
{
  vector<string> ans;
  help(0, ans, s);
  return ans;
}
