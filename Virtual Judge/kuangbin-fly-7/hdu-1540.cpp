#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        stack<int> s;
        set<int> st({0, n + 1});

        for (int i = 0; i < m; i++)
        {
            char opt = getchar();
            while (!isalpha(opt)) opt = getchar();

            if (opt == 'R')
            {
                st.erase(s.top()); s.pop();
            }
            else if (opt == 'D')
            {
                int x = read<int>();
                st.insert(x);
                s.push(x);
            }
            else if (opt == 'Q')
            {
                int x = read<int>();
                if (st.count(x))
                {
                    puts("0");
                }
                else
                {
                    auto l = st.lower_bound(x), r = l;
                    printf("%d\n", *r - *--l - 1);
                }
            }
        }
    }

    return 0;
}
