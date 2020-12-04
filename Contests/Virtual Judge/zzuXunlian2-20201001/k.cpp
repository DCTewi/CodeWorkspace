#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1e5+5;
vector<int> mp[maxn] ;
int vis[maxn] , tag[maxn]; 
int n,m,t; 
void dfs(int id,int lab)
{
    ++vis[id]; tag[id] = lab;
    for(int i=0;i<mp[id].size();++i)
    {
        int to = mp[id][i];
        if(vis[to]>=2 || to==t || to==lab || tag[to]==lab) continue;
        dfs(to,lab);
    
    }
}
int res[maxn] , cnt;
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1,u,v;i<=m;++i) scanf("%d%d",&u,&v) , mp[v].push_back(u) ;
    for(int i=0;i<mp[t].size();++i) dfs(mp[t][i],mp[t][i]);
    for(int i=0;i<mp[t].size();++i) if(vis[mp[t][i]]<2) res[++cnt] = mp[t][i]; 
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;++i) printf("%d\n",res[i]);
    return 0;
}