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

const ll MAXM = 2e5+1;
const ll LOG = ceil(log2(MAXM)) + 1;

vi adj[MAXM];
vvi up(MAXM, vi(LOG));
vi depth(MAXM);

void binaryLifting(ll curr, ll parent) {

	depth[curr] = (parent == -1) ? 0 : 1 + depth[parent];
	up[curr][0] = parent;

	for(ll i = 1 ; i < LOG ; i++) {
		if(up[curr][i-1] == -1) up[curr][i] = -1;
		else up[curr][i] = up[ up[curr][i-1] ][i-1];
	}

	for(auto &child : adj[curr]) {
		binaryLifting(child, curr);
	}
}

ll lca(ll a, ll b) {

	if(depth[a] < depth[b]) swap(a,b);
	ll diff = depth[a] - depth[b];

	for(ll i = LOG-1 ; i >= 0 ; i--) {
		if(diff & (1<<i)) {
			a = up[a][i];
		}
	}

	if(a == b) return a;

	for(ll i = LOG-1 ; i >= 0 ; i--) {
		if(up[a][i] != up[b][i]) {
			a = up[a][i];
			b = up[b][i];
		}
	}

	return up[a][0];
}

void solve() {

    ll n, q, boss, a, b; 
    cin >> n >> q;

    repeb(i,2,n) {
    	cin >> boss;
    	adj[boss].pb(i);
    }

    binaryLifting(1,-1);

    while(q--) {
    	cin >> a >> b;
    	ll ans = lca(a,b);
    	p1(ans);
    }
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