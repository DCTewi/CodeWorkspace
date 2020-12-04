#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <deque>
#include <bitset>
using namespace std;
typedef long long ll;

const int MAXN = 1e4 + 5;

//notprime[n] == 0 means n is a prime.
//prim[0..top - 1] are primes below upLimit
int notprime[MAXN];
int prim[MAXN], top = 0;

void getPrime(int upLimit)
{
	notprime[0] = notprime[1] = 1;
	for (int i = 2; i <= upLimit; i++)
	{
		if (!notprime[i])
		{
			prim[top++] = i;
		}

		for (int j = 0; j < top; j++)
		{
			if (i * prim[j] > upLimit) break;

			notprime[i * prim[j]] = 1;

			if (i % prim[j] == 0) break;
		}
	}
	return ;
}

int vis[MAXN];
const int tens[] = {1, 10, 100, 1000};
int a, b;

int main()
{
    getPrime(MAXN);
    int _T; scanf("%d", &_T);
    while (_T--)
    {
        memset(vis, 0, sizeof vis);
        scanf("%d%d", &a, &b);
        if (a == b)
        {
            puts("0"); continue;
        }

        queue<pair<int, int> > q;
        q.push(make_pair(0, a)); vis[a] = 1;
        int flag = 0;

        while (!flag && q.size())
        {
            pair<int, int> now = q.front(); q.pop();
            int &val = now.second, &depth = now.first;

            for (int i = 0; i < 4 && !flag; i++)
            {
                int dig = val / tens[i] % 10;

                for (int j = 0; j <= 9; j++)
                {
                    if (dig == j) continue;

                    int nex = val - (dig - j) * tens[i];

                    if (nex == b)
                    {
                        flag = 1; printf("%d\n", depth + 1); break;
                    }

                    if (nex >= 1000 && !vis[nex] && !notprime[nex])
                    {
                        #ifdef DEBUG
                        printf("\t%d pushed(%d)\n", nex, notprime[nex]);
                        #endif
                        q.push(make_pair(depth + 1, nex)); vis[nex] = 1;
                    }
                }
            }
            vis[val] = 0; 
        }
    }
    return 0;
}
