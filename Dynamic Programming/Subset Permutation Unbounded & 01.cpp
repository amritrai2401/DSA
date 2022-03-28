NEVER ASKED
int CCP(vector<int> coins, int amt, vector<int> dp) {
  dp[0] = 1;
  for (int i = 1; i < dp.size(); i++) {
    for (int coin : coins) {
      if (i - coin >= 0) {
        dp[i] += dp[i - coin];//NEVER ASKED UNBOUNDED
      }
    }
  }
  return dp[amt];
}
