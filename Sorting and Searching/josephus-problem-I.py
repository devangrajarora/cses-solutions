def solve():
	n = int(input())
	done = [ False for _ in range(n) ]
	pos, left = 0, n

	if n == 1:
		print(1)
		return


	while left > 0:

		# find next available
		while done[pos]:
			pos = (pos + 1)%n
		if left == 1:
			print(pos+1, end=" ")
			break

		# skip this one
		pos = (pos + 1)%n

		#find next available
		while done[pos]:
			pos = (pos + 1)%n

		#print this one, and mark it visited
		print(pos+1, end=" ")
		done[pos] = True
		left -= 1

solve()
print()