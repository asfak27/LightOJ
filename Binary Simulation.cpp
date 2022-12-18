#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N =          (int) 1e6 + 6;
const ll  MxN =       (int) 1e9 + 7;
int arr[N];
int tree[N*3];
void init(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    ll left = node*2;
    ll right = node*2+1;
    ll mid = (b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);
}
void update(ll node,ll b,ll e,ll l,ll r)
{
   if(b>r || e<l)return;
   if(b>=l && e<=r)
   {
       tree[node]++;
       return;
   }
    ll left = node*2;
    ll right = node*2+1;
    ll mid = (b+e)/2;

    update(left,b,mid,l,r);
    update(right,mid+1,e,l,r);

}
ll query(ll node,ll b,ll e,ll i)
{
    if(b==i && e==i)return tree[node];

    ll left = node*2;
    ll right = node*2+1;

    ll mid = (b+e)/2;

    if(i<=mid)return tree[node]+query(left,b,mid,i);
    else return tree[node]+query(right,mid+1,e,i);


}

int main()
{
    int ck=1;
    int tc; cin>>tc;
    while(tc--)
    {


  cout<<"Case "<<ck++<<":"<<endl;
     int n,q,i;
    string s;
    cin>>s;
    n=s.size();

    for(i=0;i<n;i++)
    {
        if(s[i]=='0')arr[i+1]=0;
        else arr[i+1]=1;
    }

    init(1,1,n);
    cin>>q;
    //cout<<"Case "<<Case<<":"<<endl;
    while(q--)
    {
        char ch;
        cin>>ch;
        if(ch=='I')
        {
            //cout<<"s"<<endl;
            int k,l,r;
            cin>>l>>r;
            update(1,1,n,l,r);
        }
        else
        {
            int k;
            cin>>k;
            cout<<query(1,1,n,k)%2<<endl;

        }



    }
    memset(arr,0,sizeof(arr));
    memset(tree,0,sizeof(tree));



}
}

