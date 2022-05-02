//PATH QUE CAN NEVER ASK PERMUTATION. ex; 1->2->3 you cant permute it like first go 3 then 1 then 2 (3->1->1)wrong
//Cant be in circular manner
// Gives only 1 path
int solve(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size(); 
        vector<vector<int> > dp(m, vector<int>(n, grid[0][0]));
        for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; j++) dp[0][j] = dp[0][j - 1] + grid[0][j];
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j]  = min(dp[i - 1][j],dp[i][j - 1]) + grid[i][j];   // For no of ways to reach : dp[i-1][j]+dp[i][j-1]
        return dp[m - 1][n - 1];
}


// Que:You are standing in top-left cell and are required to move to bottom-right cell and you are allowed to move 1 cell right (h move) or 1 cell down (v move) in 1 motion.
// Sol:
//       int[][] dp = new int[arr.length][arr[0].length];
      
//       for(int i = dp.length - 1; i >= 0; i--){
//           for(int j = dp[0].length - 1; j >= 0; j--){
//               if(i == dp.length - 1 && j == dp[0].length - 1){
//                   dp[i][j] = arr[i][j];
//               } else if(i == dp.length - 1){
//                   dp[i][j] = arr[i][j] + dp[i][j + 1];
//               } else if(j == dp[0].length - 1){
//                   dp[i][j] = arr[i][j] + dp[i + 1][j];
//               } else {
//                   dp[i][j] = arr[i][j] + Math.min(dp[i][j + 1], dp[i + 1][j]);
//               }
//           }
//       }
