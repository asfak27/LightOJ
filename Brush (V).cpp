#include <bits/stdc++.h>

#define I_O ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//~~~~~~~~~~~~ Sort Form Of Long~~~~~~~~~~~//
#define ll long long int
#define int int64_t
#define ld long double
#define db double
#define ull unsigned long long int

//~~~~~~~~~~~~~~Pair~~~~~~~~~~~~~~~~~~//
#define pii pair<int, int>
#define vi vector<int>
#define vs vector<string>
#define vpi vector<pii>
#define vvi vector<vector<int>>

//~~~~~~~~~~~~~~Shorts~~~~~~~~~~~~~~~~~//
#define ff first
#define ss second
#define al(v) v.begin(),v.end()
#define alr(v) v.rbegin(), v.rend()
#define srt(v) sort(al(v))
#define srtr(v) sort(al(v), greater<int>());
#define len(x) ((int)(x).size())
#define rev(v) reverse(al(v))
#define btcnt(n) __builtin_popcountll(n)
#define acl(v, n) accumulate(al(v), n)
#define Lrt(s, c) rotate(s.begin(), s.begin() + c, s.end())
#define Rrt(s, c) rotate(s.begin(), s.begin() + s.size() - c, s.end())
#define lb(v, kk) lower_bound(al(v), kk) - v.begin()
#define ub(v, kk) upper_bound(al(v), kk) - v.begin()
#define tpu(str) transform(al(str), str.begin(), ::toupper)
#define tpl(str) transform(al(str), str.begin(), ::tolower)
#define cignr cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define mxv(v) *max_element(al(v))
#define mnv(v) *min_element(al(v))

const int mod = 1e9 + 7;
const int INF = 2e18;
const int mxn = 2e9 + 9;
const int mxd = 2e5 + 5;
const int mxa = 2e6 + 5;

//~~~~~~~~~~~~~~~~~~Function~~~~~~~~~~~~~~~~~~~~//
int gcd(int a, int b){ if(b == 0LL) return a; return gcd(b, a % b); }
int lcm(int a, int b){ return (a / gcd(a, b) * b); }
int maxll(int x, int y){ return x > y ? x : y; }
int minll(int x, int y){ return x < y ? x : y; }

//~~~~~~~~~~~~~~~Loops and Short~~~~~~~~~~~~~~~~//

#define PI acos(-1)
#define N '\n'
#define Read(x) freopen(x, "r", stdin)
#define Write(x) freopen(x, "w", stdout)
#define rep(i, n) for(int i = 0; (int)i < n; i++)
#define test_case() int T; cin >> T; while(T--)

using namespace std;

vpi adj[mxd];
int n, m, dist[mxd], vis[mxd], a, b, c;
priority_queue<pii, vpi, greater<pii>> pq;

void Dijkstra(int src) {
   for (int i = 1; i <= n; i++) dist[i] = LONG_LONG_MAX;
   dist[src] = 0;
   pq.push({0, src});

   while (pq.size()) {
      int cur_node = pq.top().ss;
      pq.pop();
      for (auto edge: adj[cur_node]) {
         int next_node = edge.ff, weight = edge.ss;
         if (dist[cur_node] + weight < dist[next_node]) {
            dist[next_node] = dist[cur_node] + weight;
            pq.push({dist[next_node], next_node});
         }
      }
   }
}

void Run_Case() 
{
   cin >> n >> m;
   rep (i, n + 1) adj[i].clear();
   rep (i, m) {
      cin >> a >> b >> c;
      adj[a].push_back({b, c});
      adj[b].push_back({a, c});
   }

   Dijkstra(1);
   if (dist[n] == LONG_LONG_MAX) cout << "Impossible" << N;
   else cout << dist[n] << N;
}

signed main()
{
   I_O
   int cnt = 1;
   test_case()
   {
      cout << "Case " << cnt++ << ": ";
      Run_Case();
   }

   return 0;
}
