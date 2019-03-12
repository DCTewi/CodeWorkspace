#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int plc[MAXN], top = 0;

int main(int argc, char const *argv[])
{
	int t, T = 1;cin>>t;
	while(t--)
	{
		printf("Case#%d\n", T++);

		int n, q;
		scanf("%d%d", &n, &q);
		string A; cin>>A;

		for (int qq = 0; qq < q; qq++)
		{
			int l, r;scanf("%d%d", &l, &r);
			if (l == r) printf("1\n");
			else
			{
				char now = 'Z' + 1;
				for (int i = l - 1; i < r; i++)
				{
					if (A[i] < now)
					{
						#ifdef TEWILOCAL
							//printf("now <- %c, oldnow = %c\n", A[i], now);
						#endif
						now = A[i];
						top = 0;
						plc[top++] = i;
						#ifdef TEWILOCAL
							//printf("plc[%d] of %c = %d\n", top - 1, now, i);
						#endif
					}
					else if (A[i] == now)
					{
						plc[top++] = i + 1;
					}
				}
				printf("%d\n", top);
			}
			
		}
	}
	return 0;
}