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
vi sumChild(MAXM);
vi sumParent(MAXM);
vi adj[MAXM];

void sumC(ll curr, ll parent) {
	int ok = 0;
	for(auto &child : adj[curr]) {
		if(child != parent) {
			ok = 1;
			sumC(child, curr);
			sumChild[curr] += 1 + sumChild[child];
		}
	}
}

void sumP(ll curr, ll parent) {
	int ok = 0;
	for(auto &child : adj[curr]) {
		if(child != parent) {
			sumParent[child] = 1 + sumParent[curr];
			sumP(child, curr);
		}
	}

}
void solve() {

    ll n, u, v; cin >> n;
    rep(i,n-1) {
    	cin >> u >> v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    sumP(1,0);
    sumC(1,0);

    repeb(i,1,n) p0(sumParent[i]); p1("");
    repeb(i,1,n) p0(sumChild[i]);
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