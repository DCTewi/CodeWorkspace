//B
#include<bits/stdc++.h>
using namespace std;

const int maxn = 500+10;
const int INF = 1e8;
int d[maxn][maxn];
int ar[maxn][maxn];
int n,m;
int s[maxn][maxn];
int main(void){
	cin>>m>>n;
	for(int i = 1;i <= n; ++i){
		for(int j = 1;j <= m; ++j){
			scanf("%d",&ar[i][j]);
			if(ar[i][j] == 0)
				ar[i][j] = INF;
		}
	}
	for(int i = 1;i <= m; ++i){
		for(int j = i+1;j <= m; ++j){
				if(i == j) continue;
				for(int k = 1; k <= n; ++k){
					if(ar[k][i] < ar[k][j])
					   d[i][j]++;
					else if(ar[k][i] > ar[k][j])
					   d[j][i]++;
				}
				int x = d[i][j],y = d[j][i];
				if(x >= y)
					d[j][i] = 0;
				if(x <= y)
					d[i][j] = 0;
				
		} 
	}
//	for(int i = 1;i <= m; ++i,cout<<endl)
//		for(int j = 1;j <= m; ++j)
//			cout<<d[i][j]<<" ";
	for(int k = 1;k <= m; ++k){
		for(int i = 1;i <= m; ++i){
			for(int j = 1;j <= m; ++j){
				if(d[i][k] == 0 || d[k][j] == 0) continue;
					d[i][j] = max(d[i][j],min(d[i][k],d[k][j]));
			}
		}
	}
//	for(int i = 1;i <= m; ++i,cout<<endl)
//		for(int j = 1;j <= m; ++j)
//			cout<<d[i][j]<<" ";
	vector<int> ans;
	for(int i = 1;i <= m; ++i){
		bool yes = true;
		for(int j = 1;j <= m; ++j){
			if(i == j) continue;
			if(d[i][j] < d[j][i])
				yes = false;
		}
		if(yes)
		   ans.push_back(i);
	}
	for(int i = 0;i < ans.size(); ++i)
	 	printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
	
	
	
	return 0;
} 