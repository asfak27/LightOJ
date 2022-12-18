#include<bits/stdc++.h>
using namespace std;
#define  ll      unsigned long long
#define  NO      cout<<"NO"<<endl
#define  YES     cout<<"YES"<<endl
#define  no      cout<<"No"<<endl
#define  yes     cout<<"Yes"<<endl
#define  mod     1000000007
#define  mx      10000000007
#define  N       100005
#define  M       17
//#define  gcd(a,b) __gcd(a,b)
//#define  lcm(a,b) a*b/(gcd(a,b))
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll c;
void solve()
{
    map<ll,ll>mp;
    map<ll,ll>pp;
    ll n,j,i,z,l,r,x,k,m,y;
    string s,t;
    cin>>n>>k;
    ll a[n+1];
    for(i=0;i<n;i++)
    {
       cin>>a[i];
    }
    sort(a,a+n);
    c++;
    cout<<"Case "<<c<<": "<<endl;
    while(k--)
    {
        cin>>l>>r;

        x=upper_bound(a,a+n,r)-a;
        y=lower_bound(a,a+n,l)-a;

       // cout<<x<<" "<<y<<endl;
        ll ans=x-y;

        cout<<ans<<endl;
    }


}
int main()
{
    fast;
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}
