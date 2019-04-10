#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 5;
int n, m, q;
string s, t;
int plc[MAX], top = 0;

int main(int argc, char const *argv[])
{
	scanf("%d%d%d", &n, &m, &q);
	cin>>s>>t;
	//cout<<s.find(t, 0)<<endl;
	for (int i = s.find(t); s.find(t, i) != string::npos; i = s.find(t, i + 1))
	{
		plc[top++] = i + 1;
	}
	//for (int i = 0; i < top; i++) cout<<plc[i]<<" ";cout<<endl;

	for (int i = 0; i < q; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		int ans = 0;
		for (int i = 0; i < top; i++)
		{
			if (plc[i] < l) continue;
			if (plc[i] > r) break;
			//cout<<r - l<<" "<<t.size()<<endl;
			if (r - plc[i] >= t.size() - 1) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}