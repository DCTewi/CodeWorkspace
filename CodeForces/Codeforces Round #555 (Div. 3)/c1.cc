#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int n;
int a[MAXN];
string seq;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int last = 0;
    for (int l = 1, r = n; l <= r;)
    {
        if (l == r && a[l] > last)
        {
            if (a[l - 1] == last)
            {
                seq += 'L';
            }
            else
            {
                seq += 'R';
            }
            break;
        }
        if (a[l] < a[r] && a[l] > last)
        {
            seq += 'L';
            last = a[l];
            l++;
        }
        else if (a[r] > last)
        {
            seq += 'R';
            last = a[r];
            r--;
        }
        else
        {
            break;
        }
    }

    cout << seq.size() << "\n" << seq << "\n";

    return 0;
}