#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define repe(i,n) for(ll i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(ll i = a ; i < b ; i++)
#define repeb(i,a,b) for(ll i = a ; i <= b ; i++)
#define rfor(i,n,a) for(ll i = n ; i >= a ; i--)
#define pb push_back
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define p3(a,b,c) cout << a << " " << b << " " << c << endl
#define watch(x) cout << (#x) << " is " << (x) << endl
#define w(x) ll x; cin>>x; while(x--)

    template <typename T1, typename T2>
    inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
    {
        return os << "(" << p.first << ", " << p.second << ")";
    }
 
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    {
        bool first = true;
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << " ";
            os << v[i];
            first = false;
        }
        return os;
    }
    
/*-------------------------------------------------*/

// read once, read again, think, code

pii dfs(vi *adj, int curr, int parent, vector<pii> &cache) {

	ll incEdge = 0, incNeither = 0;

	for(auto &child : adj[curr]) {
		if(child != parent) {
			pii smallAns = dfs(adj,child,curr,cache);
			cache[child] = smallAns;
			incNeither += smallAns.fi;
		}
	}

	for(auto &child : adj[curr]) {
		if(child != parent) {
			// include this edge
			incEdge = max(incEdge, incNeither + 1 - cache[child].fi + cache[child].se);
		}
	}

	return {incEdge, incNeither};
}

void solve() {

	ll n,a,b; cin >> n;

	vi adj[n+1];
	vector<pii> cache(n+1);
	
	rep(i,n-1) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	pii ans = dfs(adj,1,-1,cache);
	p1(max(ans.fi,ans.se));
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
    freopen("/home/devang/input.txt","r",stdin);
    freopen("/home/devang/output.txt","w",stdout);
    #endif

    //w(tc)
    	solve();
	
	return 0;
}