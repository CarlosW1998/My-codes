def best(i, f, cust, size, capacity, dp) :
	if i == f or capacity <= 0:
		return 0
	if dp[i][capacity] != -1 :
		return dp[i][capacity]
	if size[i] > capacity :
		dp[i][capacity] = best(i+1, f, cust, size, capacity,dp)
		return dp[i][capacity]
	dp[i][capacity] = max(cust[i]+best(i+1, f, cust, size, capacity-size[i], dp), best(i+1, f, cust, size, capacity, dp))
	return dp[i][capacity]

tam, capacity = map(int, input().split())

cust = list(map(int, input().split()))
size = list(map(int, input().split()))
dp = []
for a in range(tam):
	dp.append([-1]*(capacity+2))

print(best(0, tam, cust, size, capacity,  dp))
