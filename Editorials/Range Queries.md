## Range Queries

### Static Range Sum Queries
#1 Using Prefix Sum array.
Build: O(N), Query: O(1)
#2 Using Range Sum Segment tree.
Build: O(N), Query: O(logN)

### Static Range Minimum Queries
#1 Using Range Minimum Segment tree.
Build: O(N), Query: O(logN), Update: O(logN)

### Dynamic Range Sum Queries
#1 Using Range Sum Segment tree
Build: O(N), Query: O(logN), Update: O(logN)

### Dynamic Range Minimum Queries
#1 Using Range Minimum Segment tree
Build: O(N), Query: O(logN), Update: O(logN)

### Range Xor Queries
Create segment tree where each node represents XOR of all elements of the segment which the node represents.   
Build: O(N), Query: O(logN), Update: O(logN)

### Forest Queries
- Create a prefix sum matrix. 
 Relation: psa[i][j]  = psa[i-1][j]  + psa[i][j-1]  - psa[i-1][j-1]  +  (a[i][j] ==  '*')
-  Answer queries in O(1)
For (r1,c1) and (r2,c2),
ans = psa[r2][c2]  - psa[r1-1][c2]  - psa[r2][c1-1]  + psa[r1-1][c1-1]

### Hotel Queries
For each group, we have to assign the first hotel which has enough number of rooms.

\#1 Traverse hotels for each query and assign the first one with enough rooms, and update the number of rooms in that hotel.
Time complexity: O(N\*M)

\#2 Say we know the hotel with maximum number of rooms. If the max value is less than our need then we output 0 or this query, else there exists some hotel with enough rooms. Since we have to find the leftmost hotel with enough rooms, we can check the left half of this segment to see if it has at least one hotel with enough rooms(max of left half). If it does we check the left half of that segment, else we can check the right half.

Create a segment tree where each node holds the maximum element and index of maximum element of that node. A query on the segment should give the leftmost element in that segment with enough rooms.
In each query, 
if the node represents a single element, we return it,
else if the max of left half of segment is >= required rooms, we return the result of a query on the left segment, else we return the result of query on right segment.
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
Build: O(N), Query: O(logN), Update: O(logN)
