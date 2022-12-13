#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  string s1, s2;
  cout << "Enter the first string:  ";
  cin >> s1;
  cout << "Enter the second string: ";
  cin >> s2;
  cout << endl;

  int m = s1.size();
  int n = s2.size();

  vector<vector<int> > dp(m+1, vector<int> (n+1, 0));

  int max_len = 0;

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (s1[i-1] == s2[j-1])
      {
        dp[i][j] = dp[i-1][j-1] + 1;
        if (dp[i][j] > max_len)
          max_len = dp[i][j];
      }
      else
        dp[i][j] = 0;
    }
  }

  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
        {
            if(i==0 && j==0)
                cout << " " << " ";
            else if(i==0 && j>0)
                cout << s2[j-1] << " ";
            else if(i>0 && j==0)
                cout << s1[i-1] << " ";
            else
        cout << dp[i][j] << " ";
        }
    cout << endl;

  }

  cout << "The length of the longest common substring is "
       << max_len;

  return 0;
}
