#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll N,M,ans,c=0;
bool vis[1001][1001];
char a[1001][1001];
bool isvalid(ll x,ll y)
{
    if(x<1 || x>N || y<1 || y>M)return false;

    if(vis[x][y] || a[x][y]=='#')return false;
    return true;
}
ll dx[]= {-1,0,1,0};
ll dy[]= {0,1,0,-1};
void dfs(ll x,ll y)
{
    vis[x][y]=1;
    for(ll i=0; i<4; i++)
    {
        if(isvalid(x+dx[i],y+dy[i]) && a[x+dx[i]][y+dy[i]]=='.')
        {
            ans++;
            dfs(x+dx[i],y+dy[i]);
        }
    }
}
int main()
{
    //freopen("textnew.txt","r",stdin);
    ll n,e,m,i,j,T;
    cin>>T;
    while(T--)
    {
        cin>>M>>N;
        for(i=1; i<=N; i++)
        {
            for(j=1; j<=M; j++)
            {
                vis[i][j]=0;
                a[i][j]='.';
            }
        }
        ans=0;
        for(i=1; i<=N; i++)
        {
            for(j=1; j<=M; j++)
            {
                char ch;
                cin>>ch;
                a[i][j]=ch;
            }
        }
        bool f=false;
        for(i=1; i<=N; i++)
        {
            for(j=1; j<=M; j++)
            {
                if(a[i][j]=='@')
                {
                    dfs(i,j);
                    f=true;
                    break;
                }
            }
            if(f)break;
        }
        c++;
        cout<<"Case "<<c<<": "<<ans+1<<endl;
    }

    return 0;
}
