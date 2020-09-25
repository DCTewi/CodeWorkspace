#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e1 + 5;
int n = 0;
string str[MAXN];

string lcs(string s1, string s2) {
    int len1 = s1.size();
    int len2 = s2.size();
    vector<vector<int>> c(len1+1, vector<int>(len2+1, 0));
    for (int i = 1 ; i <= len1; i++) {
        for(int j = 1; j <=len2 ; j++) {
            if (s1[i-1] == s2[j-1]) c[i][j] = c[i - 1][j - 1] + 1;
            else if (c[i - 1][j] >= c[i][j - 1]) c[i][j] = c[i - 1][j];
            else c[i][j] = c[i][j - 1];
        }
    }

    for (int i = 0 ; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    //return c[len1][len2];
    int now = c[len1][1], nowi = 1; string ans = "";
    for (int i = 1, t = 0; t < c[len1][len2]; i++)
    {
    	if (c[len1][i + 1] != now)
    	{
    		ans += s2[nowi];
    		nowi = i + 1;
    		now = c[len1][i + 1];
    		t++;
    	}
    }
    return ans;
}

int main(int argc, char const *argv[])
{
	while (cin>>n)
	{
		for (int i = 0; i < n; i++)
		{
			cin>>str[i];
		}
		sort(str, str + n, [](string a, string b) -> bool {return a < b;});

		cout << lcs(str[0], str[1]);

	}
	return 0;
}