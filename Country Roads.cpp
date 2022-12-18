#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 100000000
#define mx 100009

vector<pair<ll, ll>>g[mx];
bool vis[mx];
ll dis[mx],c;
void reset()
{
    for(ll i=0; i<mx; i++)
    {
        g[i].clear();
        vis[i]=0;
        dis[i]=inf;
    }
}
void digkstra(ll s,ll n)
{
    for(ll i=0; i<n; i++)
    {
        dis[i]=inf;
    }
    dis[s]=0;
    priority_queue <pair<ll, ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>> >q;
    q.push({0,s});

    while(!q.empty())
    {
        ll currnode=q.top().second;
        ll currdis=q.top().first;
        q.pop();

        if(dis[currnode]<currdis)continue;
        for(ll i=0; i<g[currnode].size(); i++)
        {
            ll nxtnode=g[currnode][i].first;
            ll nxtdis=g[currnode][i].second;

            if(max(currdis,nxtdis) < dis[nxtnode])
            {
                dis[nxtnode]=max(currdis,nxtdis);
                q.push({dis[nxtnode],nxtnode});
            }

        }

    }

}
int main()
{
    //freopen("textnew.txt","r",stdin);
    ll T;
    cin>>T;
    while(T--)
    {
        reset();
        ll node,edge,n,m,i,j,source;
        cin>>node>>edge;
        for(i=1; i<=edge; i++)
        {
            ll u,v,cost;
            cin>>u>>v>>cost;
            g[u].push_back({v,cost});
            g[v].push_back({u,cost});
        }
        cin>>source;
        digkstra(source,node+1);
        c++;
        cout<<"Case "<<c<<":"<<endl;
        for(i=0; i<node; i++)
        {
            if(dis[i]==inf)
            {
                cout<<"Impossible"<<endl;
            }
            else cout<<dis[i]<<endl;
        }
    }
}
