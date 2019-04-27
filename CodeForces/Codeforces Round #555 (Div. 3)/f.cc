#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int ha = 998244353;
const int N = 1e6 + 5;

map<int, int> M;
vector<int> A, B;

int main()
{
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        ++M[x];
    }
    int ml = 0, mr = 0, mans = 0, lst = 0, lstf = -1, lstl = 0, lstans = 0;
    for (auto &it : M)
    {
        A.push_back(it.first);
        B.push_back(it.second);
    }
    int flg = 0;
    for (int i = 1; i < M.size(); ++i)
        if (A[i] != A[i - 1] + 1 || B[i] < 2)
            flg = 1;
    if (!flg)
    {
        int cnt = 0;
        for (int i = 0; i < M.size(); ++i)
            cnt += B[i];
        printf("%d\n", cnt);
        for (int i = 0; i < M.size(); ++i)
            for (int j = 1; j < B[i]; ++j)
                printf("%d ", A[i]);
        for (int i = M.size() - 1; i >= 0; --i)
            printf("%d ", A[i]);
        return 0;
    }
    int ans = 1, L = 0, R = 1;
    for (int i = 1; i < M.size(); ++i)
        if (A[i] == A[i - 1] + 1 && B[i] == 1 && B[i - 1] == 1)
            ans = 2, L = i - 1, R = i + 1;
    A.push_back(1e9);
    B.push_back(1);
    for (int i = 0; i < A.size(); ++i)
    {
        if (B[i] < 2)
            continue;
        int tot = B[i], tl = i, tr = i + 1;
        if (i > 0 && A[i - 1] == A[i] - 1)
            --tl, ++tot;
        for (int j = i + 1; j < A.size(); ++j)
        {
            if (A[j - 1] != A[j] - 1)
            {
                tr = j;
                break;
            }
            if (B[j] == 1)
            {
                ++tot, tr = j + 1;
                break;
            }
            tot += B[j];
        }
        if (tot > ans)
            ans = tot, L = tl, R = tr;
        i = tr - 1;
    }
    printf("%d\n", ans);
    for (int i = L; i < R; ++i)
    {
        for (int j = 1; j < B[i]; ++j)
            printf("%d ", A[i]);
    }
    for (int i = R - 1; i >= L; --i)
    {
        printf("%d ", A[i]);
    }
    return 0;
}