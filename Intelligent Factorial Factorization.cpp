#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define  no               cout<<"No"<<endl
#define  yes              cout<<"Yes"<<endl
#define  mod       1000000007
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
map<ll,ll>mp;
ll c;
void primeFactorization(ll n)
{
    while(n%2==0)
    {
        mp[2]++;
        n/=2;
    }
    for(ll i=3; i*i<=n; i=i+2)
    {
        while(n%i==0)
        {
            mp[i]++;
            n = n/i;
        }
    }
    if(n>2)
    {
        mp[n]++;
    }
}
void solve()
{
    vector<ll>v;
    //map<ll,ll>mp;
    ll n,m,j,i,y,z,l,r,d,x,k;
    cin>>n;

    mp.clear();
    for(i=2;i<=n;i++)
    {
        primeFactorization(i);
    }
    ll sz=mp.size();
    cout<<"Case "<<++c<<": "<<n<<" = ";
    ll cnt=1;
    for(i=2;i<=n;i++)
    {

        if(mp[i] && cnt<sz)
        {
            cnt++;
            cout<<i<<" ("<<mp[i]<<") * ";
        }
        else if(mp[i] && cnt==sz) cout<<i<<" ("<<mp[i]<<")";
    }
    cout<<endl;

}
int main()
{
    fast;
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}
