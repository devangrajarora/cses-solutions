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
#define w(x) ll x; cin>>x; while(x--)

int dr4[] = {0,1,0,-1}, dc4[] = {1,0,-1,0};
int dr8[] = {0,1,1,1,0,-1,-1,-1}, dc8[] = {1,1,0,-1,-1,-1,0,1};

/*-------------------------------------------------*/

// read once, read again, think, code

vi one, two;

bool solve(int n) {

	if(n == 0) return true;
	if(n <= 2) return false;
	if(n == 3) {
		one.pb(1),one.pb(2),two.pb(3);
		return true;
	}

	one.pb(n-3), one.pb(n);
	two.pb(n-2), two.pb(n-1);
	return solve(n-4);
}

void pv(vi &a) {
	for(auto &elem : a) p0(elem);
	cout << "\n";
}

int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ll n;
    cin >> n;
    if(solve(n)) {
    	p1("YES");
    	p1(one.size());
    	pv(one);
    	p1(two.size());
    	pv(two);    	
    } else {
    	p1("NO");
    }
	
	return 0;
}