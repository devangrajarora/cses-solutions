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

struct SegmentTree {

	vector<ll> seg;
	int size;

	void init(int n) {
		size = 4*n;
		seg.assign(size,0ll);
	}

	void build(vi &a, int pos, int l, int r) {
		if(l == r) {
			seg[pos] = a[l]; return;
		}

		int mid = (l + r) / 2;
		build(a,2*pos+1,l,mid);
		build(a,2*pos+2,mid+1,r);
		seg[pos] = seg[2*pos+1] + seg[2*pos+2];
	}

	void build(vi &a, int n) {
		build(a,0,0,n-1);
	}

	void update(vi &a, ll x, int idx, int pos, int l, int r) {
		if(l == r) {
			seg[pos] = x;
			a[idx] = x;
			return;
		}

		int mid = (l + r) / 2;
		if(idx <= mid) update(a,x,idx,2*pos+1,l,mid);
		else update(a,x,idx,2*pos+2,mid+1,r);

		seg[pos] = seg[2*pos+1] + seg[2*pos+2];		
	}

	void update(vi &a, ll num, int idx, int n) {
		update(a,num,idx,0,0,n-1);
	}

	ll query(int pos, int l, int r, int ql, int qr) {
		if(ql > r or qr < l) return 0;
		if(ql <= l and r <= qr) return seg[pos];
		int mid = (l + r) / 2;

		ll left = query(2*pos+1,l,mid,ql,qr);
		ll right = query(2*pos+2,mid+1,r,ql,qr);
		return left + right;
	}

	ll query(int ql, int qr, int n) {
		return query(0,0,n-1,ql,qr);
	}
};

void solve() {

	int n, q; cin >> n >> q;
	vi a(n);
	rep(i,n) cin >> a[i];

    SegmentTree seg;

    seg.init(n);
    seg.build(a,n);

    while(q--) {
    	int op; cin >> op;
    	if(op == 1) {
    		int idx; cin >> idx; idx--;
    		ll num; cin >> num;
    		seg.update(a,num,idx,n);
    	} else {
    		int l, r; cin >> l >> r; l--; r--;
    		cout << seg.query(l,r,n) << "\n";
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