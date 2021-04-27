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

const int MAXM = 2e5+1;
vi depth(MAXM);
vi ans(MAXM);
vi adj[MAXM];

void evalDepth(ll curr, ll parent) {
	for(auto &child : adj[curr]) {
		if(child != parent) {
			evalDepth(child, curr);
			depth[curr] = max(depth[curr], 1 + depth[child]);
		}
	}
}

void findAns(ll curr, ll parent, ll excludingThisSubtree) {

	vi childDepth;
	for(auto &child : adj[curr]) {
		if(child != parent) {
			childDepth.pb(depth[child]);
		}
	}

	int sz = childDepth.size();
	if(sz == 0) {
		ans[curr] = 1 + excludingThisSubtree;
		return;
	}

	vi prefixMax(sz), suffixMax(sz);
	prefixMax[0] = childDepth[0];
	suffixMax[sz-1] = childDepth[sz-1];

	for(int i = 1 ; i < sz ; i++) {
		prefixMax[i] = max(prefixMax[i-1], childDepth[i]);
	}

	for(int i = sz-2 ; i >= 0 ; i--) {
		suffixMax[i] = max(suffixMax[i+1], childDepth[i]);
	}

	int childNo = 0;

	for(auto &child : adj[curr]) {
		if(child != parent) {
			ll op1 = (childNo == 0) ? -1 : prefixMax[childNo-1];
			ll op2 = (childNo == sz-1) ? -1 : suffixMax[childNo+1];
			ll partialAns = 1 + max({excludingThisSubtree, op1, op2});
			findAns(child,curr,partialAns);
			childNo++;
		}
	}

	ans[curr] = max(depth[curr], 1 + excludingThisSubtree);
}

void solve() {

    ll n, u, v; cin >> n;
    rep(i,n-1) {
    	cin >> u >> v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    evalDepth(1,-1);
    findAns(1,-1,-1);

    repeb(i,1,n) p0(ans[i]);
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