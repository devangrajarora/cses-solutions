#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define repe(i,n) for(ll i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(ll i = a ; i <= b ; i++)
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
#define w(x) ll x; cin>>x; while(x--)

#define pNode(a) p3(a.dist,a.st,a.en)

int dr4[] = {0,1,0,-1}, dc4[] = {1,0,-1,0};
int dr8[] = {0,1,1,1,0,-1,-1,-1}, dc8[] = {1,1,0,-1,-1,-1,0,1};

/*-------------------------------------------------*/

// read once, read again, think, code
class Node {
public:
	ll dist;
	ll st;
	ll en;
};

struct compare {
    bool operator()(const Node &lhs, const Node &rhs) const {
        return lhs.dist > rhs.dist;
    }
};

void solve() {

    ll x, n, newLight;
    cin >> x >> n;

    multiset<Node, compare> m;
    multiset<ll> lights;
    lights.insert(0);
    lights.insert(x);
    m.insert({x,0,x});

    rep(i,n) {
    	cin >> newLight;
    	auto nextIt = lights.upper_bound(newLight);
    	auto prevIt = nextIt;
    	prevIt--;

    	ll distAhead = *nextIt - newLight;
    	m.insert({distAhead, newLight, *nextIt});

    	ll distBehind = newLight - *prevIt;
    	m.insert({distBehind, *prevIt, newLight});

    	auto found = m.find({*nextIt - *prevIt, *prevIt, *nextIt});
    	m.erase(found);

    	lights.insert(newLight);
    	ll ans = (*m.begin()).dist;
    	p0(ans);
    }
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    //w(tc)
    	solve();
	
	return 0;
}