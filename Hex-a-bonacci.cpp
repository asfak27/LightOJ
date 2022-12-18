#include<bits/stdc++.h>
#define ll long long
#define mod 10000007
using namespace std;
ll a, b, c, d, e, f;
ll dp[10003];
ll fn(ll n) {
    ll ans=0;
    if(dp[n]!=-1)return dp[n];
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;
    
    return dp[n]=(((((fn(n-1) + fn(n-2))%mod + fn(n-3))%mod + fn(n-4))%mod + fn(n-5)%mod) + fn(n-6)%mod);
}
int main() {
    ll n, cases;
    ll ck=1;
    cin>>cases;
    //while()
    //scanf("%d", &cases);
    //for (int caseno = 1; caseno <= cases; ++caseno) {
    while(cases--)
    {
        //scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        cin>>a>>b>>c>>d>>e>>f>>n;
        memset(dp,-1,sizeof(dp));
       // printf("Case %d: %d\n", caseno, fn(n) % 10000007);
       cout<<"Case "<<ck++<<": "<<fn(n)%10000007<<endl;
    }
    return 0;
}
