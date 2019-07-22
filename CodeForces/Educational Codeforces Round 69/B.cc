#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
int n, pi[MAXN];

int main()
{
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pi[i];
    }

    int flag = 0;
    for (int i = 0, j = n - 1, cnt = 1; i < j;)
    {
        if (pi[i] == cnt)
        {
            cnt++; i++;
        }
        else if (pi[j] == cnt)
        {
            cnt++; j--;
        }
        else
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        cout << "NO\n";
    }
    else 
    {
        cout << "YES\n";
    }

    return 0;
}
// 1 3 4 2
// 1 0 34 2
// 0 1 34 2
// 0 1 234 0
// 0 0 1234 0

// 3 1 2
// 13 0 2
// 13 2 0

// 3 1 2 4

// 1 3 4 2
// 1 34 2
// 1 234
// 1234