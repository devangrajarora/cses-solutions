

# Range Queries

### Static Range Sum Queries

\#1 Using Prefix Sum array.\
Build: O(N), Query: O(1)

\#2 Using Range Sum Segment tree. \
Build: O(N), Query: O(logN)

### Static Range Minimum Queries

\#1 Using Range Minimum Segment tree. \
Time complexity: O(Q\*logN)

### Dynamic Range Sum Queries

\#1 Using Range Sum Segment tree \
Time complexity: O(Q\*logN)

### Dynamic Range Minimum Queries

\#1 Using Range Minimum Segment tree \
Time complexity: O(Q\*logN)

### Range Xor Queries

Create segment tree where each node represents XOR of all elements of the segment which the node represents. \
Time complexity: O(Q\*logN)

### Forest Queries

- Create a prefix sum matrix.\
 Relation: psa[i][j]  = psa[i-1][j]  + psa[i][j-1]  - psa[i-1][j-1]  +  (a[i][j] ==  '\*')
- Answer queries in O(1) \
For (r1,c1) and (r2,c2), \
ans = psa[r2][c2]  - psa[r1-1][c2]  - psa[r2][c1-1]  + psa[r1-1][c1-1]

### Hotel Queries
For each group, we have to assign the first hotel which has enough number of rooms

\#1 Traverse hotels for each query and assign the first one with enough rooms, and update the number of rooms in that hotel. \
Time complexity: O(N\*M)

\#2 Say we know the hotel with maximum number of rooms. If the max value is less than our need then we output 0 or this query, else there exists some hotel with enough rooms. Since we have to find the leftmost hotel with enough rooms, we can check the left half of this segment to see if it has at least one hotel with enough rooms(max of left half). If it does we check the left half of that segment, else we can check the right half.

Create a segment tree where each node holds the maximum element and index of maximum element of that node. A query on the segment should give the leftmost element in that segment with enough rooms. \
In each query, \
if the node represents a single element, we return it, \
else if the max of left half of segment is >= required rooms, we return the result of a query on the left segment, else we return the result of query on right segment. \
Update number of rooms left in the assigned hotel after every query.

```
pair<int,int> query(int req,  int pos,  int l,  int r)  {
	if(l == r)  return  {maxEle[pos], maxPos[pos]};
	int mid =  (l + r) / 2;
	if(maxEle[2*pos+1] >= req) {
		return query(req,2*pos+1,l,mid);
	} else {
		return query(req,2*pos+2,mid+1,r);
	}
}
```
Time complexity: O(M\*logN)

### List Removals

\#1 Maintain an array *available[n]* and intialise it with 1. For each query traverse from left and find the kth one and mark it as 0. This is the answer for current query.\
Time Complexity: O(Q\*N) ie O(N\*N) as Q = N

\#2 Find the kth one for each query by maintaining a range sum segment tree.\
At each segment [L,R] if it denotes a single element and k == 1, return the index L.
If sum of left segment id >= k, it contains the kth element, and we query for kth element in left segment.\
Otherwise the right segment contains the kth element, and we query for (k - seg[2\*pos+1]) element in right segment.

```
int query(int pos, int l, int r, int k) {
        
	if(l == r and k == 1) {
		return l;
	}

	ll mid = (l + r)/2;
	return (k <= seg[2*pos+1]) ? query(2*pos+1,l,mid,k) : query(2*pos+2,mid+1,r,k - seg[2*pos+1]);  
}
```
Time complexity: O(N\*logN)

### Salary Queries

n = 10<sup>9</sup> is too big to create a segment tree. If constraints would have been smaller we could've used Range sum segment tree to calculate number of employees in salary range [a,b].\
To make this possible, we consider buckets of size 1000, such that bucket 0 represents salary range 1 to 1000, bucket 1 represents range 1001 to 2000 and so on.\
More generally, bucket i represents range (i\*1000)+1 to (i+1)\*1000.\
We can have 10<sup>6</sup> such buckets to represent range upto 10<sup>9</sup> salary values. We make the segment tree on these buckets.\
For a query [a,b], on the ends of the query we can have a...i and j...b lie partially in a bucket and i+1...j-1 can be completely divided into some buckets. \
Example, if a = 990 and b = 2010, 990...1000 and 2001...2010 partially lie in some buckets, and 1001...2000 are completely covered by buckets. \
For the partial overlap we can add to the ans by manually checking the values in that partial overlap (The number of elements we have to check would be atmost 999 on each side).

Refer to the code for more clarity.

Time complexity: \
Build: O(10<sup>7</sup>) \
Query: O(log 10<sup>7</sup> + QlogN) \
Update: O(log 10<sup>7</sup>)