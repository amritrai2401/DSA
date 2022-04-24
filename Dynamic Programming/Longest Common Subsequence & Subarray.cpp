int lcs(string X, string Y) {
        int m = X.size(),n = Y.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(X[i-1] == Y[j-1]) dp[i][j] = dp[i-1][j-1] + 1;                      //For substring : {....+1; ans=max(ans,dp[i][j]);}
                else dp[i][j] = max(dp[i][j-1]/*insert*/, dp[i-1][j]/*remove*/);       //For substring : dp[i][j]=0;
            }
        }
        return dp[m][n];
}


// Backtracking:
int i=m,j=n; string s;
while(i>0 && j>0){
    if(X[i-1]==Y[j-1]){s.push_back(X[i-1]);i--;j--;}
    else if(dp[i][j-1]>dp[i-1][j])j--; //For shortest common superseq : s.push_back(X[j-1]; j--;
    else i--;                          //For shortest common superseq : s.push_back(Y[i-1]); i--;
}
reverse(s.begin(),s.end());

// Shortest common superseq = x.size()+y.size()-longest common subsequence
// Min no of insertion and deletion to make string x to string y :  insertion(x.size()-lcs)  +  deletion(y.size()-lcs)   lcs:longest common subsequence
// Min no insertion and deletion and replacement to make string x to y:EDIT DISTANCE  for..{for..
                                                                                         //if(i==0)dp[i][j]=j; 
                                                                                         //else if(j==0)dp[i][j]=i;    
                                                                                         //else if(x[i-1]==y[i-1])dp[i][j]=dp[i-1][j-1];
                                                                                         //else dp[i][j]= 1+ min(dp[i][j-1]insert,min(dp[i-1][j]remove,dp[i-1][j-1]replace));
// LPS:Longest palindromic subsequence of an arr : x=a & y=reverse(a);  lcs(x,y)    Follow up que: Min no of deletion to make array palindrom: arr.size()-lps
// Min no insertion and deletion to make string palindrom : no of insertion = no of deletion = s.size()-lps(s)
// LRS:Longest repeting subsequence of an arr : aabbdd =3 abd coming 2times: x=arr,y=arr; lcs(x,y) with restriction if(X[i-1]==Y[j-1] && i!=j).....
// Check if x is a subsequence of y : if(lcs(x,y)==x.size()) cout<<"yes"; 

// REGULAR STRING MATCHING
// class Solution {
//    public boolean isMatch(String s, String p) {

//     boolean[][] dp = new boolean[s.length()+1][p.length()+1];
//     dp[0][0] = true;
//     for (int i = 0; i < p.length(); i++) {
//         if (p.charAt(i) == '*' && dp[0][i-1]) {
//             dp[0][i+1] = true;
//         }
//     }
//     for (int i = 1 ; i <= s.length(); i++) {
//         for (int j = 1; j <= p.length(); j++) {
//             if (p.charAt(j-1) == s.charAt(i-1) || p.charAt(j-1) == '.') {
//                 dp[i][j] = dp[i-1][j-1];
//             }
//             else if (p.charAt(j-1) == '*') {
//                 dp[i][j]=dp[i][j-2];
//                 if (p.charAt(j-2) == s.charAt(i-1) || p.charAt(j-2) == '.')
//                     dp[i][j] = (dp[i][j-1] || dp[i-1][j] || dp[i][j-2]);
//             }
            
//         }
//     }
//     return dp[s.length()][p.length()];
// }
// }



