//No of subsets for given sum     
int coinchangecombination(vector<int> coins, int w, vector<int> dpp) {
        int n = coins.size();        
        vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
        for(int i=0;i<n+1;i++)dp[i][0] = 1;
        for(int i=0;i<w+1;i++)dp[0][i] = 0;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<w+1;j++){
                if(coins[i-1] <= j) dp[i][j]=dp[i-1][j-coins[i-1]]+dp[i-1][j];   
                //For unbounded:dp[i][j-coins[i-1]][  //To get the subset of max coins for given sum : max(dp[i-1][j]+dp[i][j-coins[i-1]]; //For knapsack:max((val[i-1]+dp[i-1][j-coins[i-1]]),..) 
                else dp[i][j] = dp[i-1][j];                     
            }
        }
        cout<<dp[n][w]<<endl; 
}

