#include<stdio.h>
int dp[1000];


int fib(int num)
{
  if(dp[num-1] != -1 ) return dp[num-1];

  if(num == 0) return 0;
  if(num == 1) return 1;
  dp[num-1] = fib(num-1)+fib(num-2);
  return dp[num-1];
}

int main()
{

  return 0;
}
