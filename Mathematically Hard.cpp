#include<bits/stdc++.h>
#define m 5000000
using namespace std;
int p [m + 1];
unsigned long long s [m + 1];
int i, j;
void cphi()
{
    for (i = 2; i <= m; i ++)
    {
        p [i] = i;
    }
    for (i = 2; i <= m; i ++)
    {
        if (p [i] == i)
        {
            for (j = i; j <= m; j+=i)
            {
                p[j]-=p[j]/i;
            }
        }
    }
}
void sum ()
{
    s [1] = 0;
    for (i = 2; i <= m; i++)
    {
        s [i] = p [i];
        s [i] *= p [i];
        s [i] += s [i-1];
    }
}
int main ()

{
    cphi ();
    sum ();
    int t, a, b,c=1;
    cin >> t;
    for (i = 1; i <= t; i++)
    {
        cin >> a >> b;
        cout<<"Case "<<c++<<": "<<s[b]-s[a-1]<<endl;
    }
}
