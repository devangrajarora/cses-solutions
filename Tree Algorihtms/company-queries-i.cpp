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


/*

Brute Force:

	make parent array
	repeat n = parent[n] k times

	Each query: O(n) worst case -> skewed tree where k >= n
	Total: O(n*q)

Binary Lifting:

any k can be represented as power of 2s

we make a 2D array up

up[u][x] = ancestor of u 2^x levels up

x <= log2(n)
n <= 2e5 -> x <= 18

p = up[u][x] = going to ancestor p1 2^x-1 levels above u
			+	going to ancestor p 2^x-1 levels above p1

2^(x-1) + 2^(x-1) = 2^x  

up[u][x] = up[ up[u][x-1] ][x-1]

each x is a set bit in k
k = 2^x1 + 2^x2 + 2^x3 + ...

we are breaking down k into its powers of 2 and there can be at max log2(k) powers of 2 in k

we first make a jump from u to up[u][k - (1<<x1)] 
and then recursion takes us to the end by finding next largest set bit



Each query: O(logN)
Total: O(q*logN)
*/

const int MAXM = 2e5+1;

vvi up(MAXM, vi(19));
vi adj[MAXM];

ll n;


// finding ancestors power of 2 nodes up
// O(NlogK) -> logK for every node 
void binaryLifting(ll curr, ll parent) {

	up[curr][0] = parent;
	for(int i = 1 ; i <= 18 ; i++) {
		if(up[curr][i-1] == -1) {
			up[curr][i] = -1;
		} else {
			up[curr][i] = up[up[curr][i-1]][i-1];
		}
	}

	for(auto &child : adj[curr]) {
		binaryLifting(child,curr);
	}
}

// O(logK)

ll query(ll x, ll k) {
	
	if(x == -1 or k == 0) return x;

	for(int i = 18 ; i >= 0 ; i--) {
		if(k >= (1<<i)) {
			return query(up[x][i], k - (1<<i));
		}
	}
}

void solve() {

    ll q, x, k, boss;
    cin >> n >> q;

    repeb(i,2,n) {
    	cin >> boss;
    	adj[boss].pb(i);
    }

    binaryLifting(1,-1);

    while(q--) {
    	cin >> x >> k;
    	cout << query(x,k) << "\n";
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