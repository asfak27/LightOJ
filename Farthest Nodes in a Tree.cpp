#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll        long long int
#define  mod      1000000007
#define N        30005
#define yes      cout<<"YES"<<endl
#define no      cout<<"NO"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
vector<pair<ll,ll>>g[N+5];
ll vis[N];
ll mx=0,x,k,c;
//vector<vector<ll>>a(N+1,vector<ll>(N+1,0));
void dfs(ll node,ll dis)
{
    vis[node]=1;
    if(dis>mx)
    {
        mx=dis;
        k=node;
    }
    for(ll i=0;i<g[node].size();i++)
    {
        ll child=g[node][i].first;
        ll cost=g[node][i].second;
        if(vis[child]==0)
        {
            dfs(child,dis+cost);
        }
    }
}

void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<ll>v;
    map<ll,ll>mp;
    ll n,e,i,j,l,m,y,z;
    cin>>n;
    mx=0;
    for(i=0;i<=n;i++)
    {
        vis[i]=0;
        g[i].clear();
    }
    for(i=1;i<n;i++)
    {
        ll u,v,cost;
        cin>>u>>v>>cost;
        g[u].push_back({v,cost});
        g[v].push_back({u,cost});

    }
    dfs(0,0);
    //cout<<k<<endl;
    for(i=0;i<=n;i++)
    {
        vis[i]=0;
    }
    mx=0;
    dfs(k,0);
    c++;
   // cout<<k<<endl;
    cout<<"Case "<<c<<": "<<mx<<endl;
}
int main()
{
    fast;
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}
