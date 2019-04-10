#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n,m;
    cin>>n>>m;
    map<string,vector< pair<string,string> > > mp;
    for(int i=1;i<=n;i++)
    {
        string s,t;
        cin>>s>>t;
        string t1,t2;
        t1=t.substr(0,4);
        t2=t.substr(4,8);
        mp[t2].push_back( make_pair(t1,s) );
    }
    while(m--)
    {
        string s;int k;
        cin>>k>>s;
        vector<pair<string,string> > v;
        v=mp[s];
        sort(v.begin(),v.end());
        cout<<v[k-1].second<<endl;
    }

    return 0;
}