#include <bits/stdc++.h>
using namespace std;
 
int n;
 
int getN(int n, int i, int j)
{
    if (i == 1)
        return j;
    if (j == n)
        return n + i - 1;
    if (i == n)
        return 3 * n - 2 - j + 1;
    if (j == 1)
        return 4 * n - 4 - i + 2;
    return getN(n - 2, i - 1, j - 1) + 4 * (n - 1);
}
 
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin>>n;
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            cout<<getN(n, j, i)<<" ";
        }
        cout<<endl;
    }
    return 0;
}