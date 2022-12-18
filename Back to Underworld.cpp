#include<bits/stdc++.h>
using namespace std;
#define  ll      long long
#define  NO      cout<<"NO"<<endl
#define  YES     cout<<"YES"<<endl
#define  no      cout<<"No"<<endl
#define  yes     cout<<"Yes"<<endl
#define  mod     1000000007
#define  mx      10000000007
#define  N       200005
#define  M       17
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
vector<ll>g[N];
bool vis[N];
ll dis[N];
ll a[N];
ll c=0;
ll bfs(ll x)
{
    ll sum1=0;
    ll sum2=0;
    queue<ll>q;
    vis[x]=1;
    a[x]=1;
    q.push(x);
    sum2++;
    while(!q.empty())
    {
        ll node=q.front();
        q.pop();
        for(ll i=0; i<g[node].size(); i++)
        {
            ll next=g[node][i];
            if(vis[next]==0)
            {
                vis[next]=1;
                q.push(next);
                if(a[node]==1)
                {
                    a[next]=0;
                    sum1++;
                }
                else
                {
                    a[next]=1;
                    sum2++;
                }

            }
        }
    }
    ll ans=max(sum1,sum2);
    return ans;

}
void clr()
{
    for(int i=0; i<=N; i++)
    {
        g[i].clear();
        vis[i]=0;
    }
}
void solve()
{
    // vector<char>v;
    map<ll,ll>mp;
    map<ll,ll>pp;
    ll n,j,i,z,l,r,x,k,m,y;
    string s,t;
    cin>>n;
    clr();
    for(i=1; i<=n; i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll sum=0;
    for(i=1; i<=20005; i++)
    {
        if(!vis[i] && g[i].size())sum+=bfs(i);
    }
    c++;
    cout<<"Case "<<c<<": "<<sum<<endl;
}

int main()
{
    fast;
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}
