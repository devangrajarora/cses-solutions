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

struct Pair {
	ll low;
	ll high;
};

struct SegmentTree {
	
    vi low, high;
    ll sz, n;

    void init(ll n) {
        sz = 4*n;
        this -> n = n;
        low.assign(sz,0ll);
        high.assign(sz,0ll);
    }

	void build(vi &a, int pos, int l, int r) {
		if(l == r) {
			low[pos] = a[l]-l;
			high[pos] = a[l]+l;
			return;
		}

		int mid = (l + r) / 2;
		build(a,2*pos+1,l,mid);
		build(a,2*pos+2,mid+1,r);
		low[pos] = min(low[2*pos+1], low[2*pos+2]);
		high[pos] = min(high[2*pos+1], high[2*pos+2]);
	}

	void build(vi &a) {
		build(a,0,0,n-1);
	}


    void update(ll idx, ll num, ll pos, ll l, ll r) {
        if(l == r) {
            low[pos] = num-idx;
            high[pos] = num+idx;
            return;
        }

        ll mid = (l + r)/2;
        if(idx <= mid) update(idx,num,2*pos+1,l,mid);
        else update(idx,num,2*pos+2,mid+1,r);
        low[pos] = min(low[2*pos+1], low[2*pos+2]);
		high[pos] = min(high[2*pos+1], high[2*pos+2]);
    }

    void update(ll idx, ll num) {
        update(idx,num,0,0,n-1);
    }

    Pair query(ll pos, ll l, ll r, ll ql, ll qr) {
        if(ql > r or qr < l) return {INT_MAX,INT_MAX};
        if(ql <= l and r <= qr) return {low[pos],high[pos]};

        ll mid = (l + r)/2;
        Pair left = query(2*pos+1,l,mid,ql,qr);
        Pair right = query(2*pos+2,mid+1,r,ql,qr);
        ll low = min(left.low, right.low);
        ll high = min(left.high, right.high);
        return {low, high};

    }

    Pair query(ll ql, ll qr) {
        return query(0,0,n-1,ql,qr);
    }

};

/*
	seg.init(n);
	seg.build(a);
	seg.update(idx,num);
	seg.query(ql,qr);
*/

void solve() {

    ll n, q, val;
    cin >> n >> q;

    vi a(n);
    rep(i,n) cin >> a[i];

    SegmentTree seg;
    seg.init(n);
    seg.build(a);

    while(q--) {
    	int op; cin >> op;
    	ll k, x;
    	if(op == 2) {
    		cin >> k; k--;
    		ll left = seg.query(0,k).low + k;
    		ll right = seg.query(k,n-1).high - k;

    		ll ans = min(left, right);
    		p1(ans);

    	} else {
    		cin >> k >> x;
    		k--;
    		seg.update(k,x);
    	}
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