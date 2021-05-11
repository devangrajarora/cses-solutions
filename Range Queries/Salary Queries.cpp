#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
#define vi vector<int>
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

const int MAXM = 1e6;

struct SegmentTree {
	
    vi seg;
    ll sz, n;

    void build(vi &a, int pos, int l, int r) {

		if(l == r) {
			seg[pos] = a[l];
			return;
		}

		int mid = (l + r) / 2;
		build(a,2*pos+1,l,mid);
		build(a,2*pos+2,mid+1,r);
		seg[pos] = seg[2*pos+1] + seg[2*pos+2];
	}

	void build(vi &a) {
		this -> n = MAXM+1;
        sz = 1;
        while(sz < n) sz <<= 1;
        sz = 2*sz-1;
        seg = vi(sz,0);
		build(a,0,0,MAXM);
	}

    void update(ll idx, ll num, ll pos, ll l, ll r) {
        if(l == r) {
            seg[pos] = num;
            return;
        }

        ll mid = (l + r)/2;
        if(idx <= mid) update(idx,num,2*pos+1,l,mid);
        else update(idx,num,2*pos+2,mid+1,r);
        seg[pos] = seg[2*pos+1] + seg[2*pos+2];
    }

    void update(ll idx, ll num) {
        update(idx,num,0,0,MAXM);
    }

    ll query(ll pos, ll l, ll r, ll ql, ll qr) {

        if(ql > r or qr < l or ql > qr) return 0;
        if(ql <= l and r <= qr) return seg[pos];

        ll mid = (l + r)/2;
        ll left = query(2*pos+1,l,mid,ql,qr);
        ll right = query(2*pos+2,mid+1,r,ql,qr);
        return left + right;

    }

    ll query(ll ql, ll qr) {
        return query(0,0,MAXM,ql,qr);
    }

};

/*
	seg.init(n);
	seg.build(a);
	seg.update(idx,num);
	seg.query(ql,qr);
*/

// each bucket represents values from (i*1000)+1 ... (i+1)*1000

int bucket_no(int a) {
	return ((a-1)/1000);
}

int partial_overlap(int lo, int hi, map<int,int>& m)
{
    int ans = 0;
    auto it = m.lower_bound(lo);
    while(it != m.end() && it->first <= hi){
        ans += it->second;
        it++;
    }
    return ans;
}

void solve() {

    ll n, q; cin >> n >> q;
    vi bucket(MAXM+1,0), salary(n);

    map<int, int> m;

    rep(i,n) {
    	cin >> salary[i];
    	m[salary[i]]++;
    	int bucketno = bucket_no(salary[i]);
    	bucket[bucketno]++;
    }

    SegmentTree seg;
    seg.build(bucket);

    while(q--) {
    	char op; cin >> op;
    	if(op == '?') {
    		int a, b, ans = 0; 
    		cin >> a >> b;
    		int bucketA = bucket_no(a);
    		int bucketB = bucket_no(b);

    		// cover overlap in left bucket
    		int endOfBucketA = (bucketA+1)*1000;
    		int lo = a, hi = min(endOfBucketA,b);
    		ans += partial_overlap(lo,hi,m);

    		// // cover overlap in right bucket
    		int startOfBucketB = (bucketB*1000)+1; 
    		lo = max(startOfBucketB,a), hi = b;
    		if(bucketA != bucketB) {
    			ans += partial_overlap(lo,hi,m);
    		}

    		ans += seg.query(bucketA+1,bucketB-1);

    		p1(ans);
    	
    	} else {
    		int k, newSalary; cin >> k >> newSalary;
    		k--;
    		int oldSalary = salary[k];
    		salary[k] = newSalary;
    		int oldBucket = bucket_no(oldSalary), newBucket = bucket_no(newSalary);
    		bucket[oldBucket]--;
    		bucket[newBucket]++;
    		m[oldSalary]--;
    		m[newSalary]++;
    		seg.update(oldBucket,bucket[oldBucket]);
    		seg.update(newBucket,bucket[newBucket]);
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