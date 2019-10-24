#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int read()
{
    int x = 0; char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48);
    return x;
}

int main()
{
    int T = read();
    while (T--)
    {
        int n = read();
        vector<int> w(n);
        for (int i = 0; i < n; i++)
        {
            w[i] = read();
        }
        sort(w.begin(), w.end());
        int hun = upper_bound(w.begin(), w.end(), 100),
            fif = upper_bound(w.begin(), w.end(), 50),
            twn = upper_bound(w.begin(), w.end(), 20),
            ten = upper_bound(w.begin(), w.end(), 10);

    }
    return 0;
}
