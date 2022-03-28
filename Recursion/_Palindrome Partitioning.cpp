bool palindrome(string s,int i,int j){
  
}


int solve(string s,int i,int j){
  if(i>=j)return 0;
  if(palindrome(s,i,j)==1)return 0;
  int ans=INT_MAX;
  for(int k=i;i<j;k++){
    int temp= 1 + solve(s,i,k) + solve(s,k+1,j);
    ans=min(ans,temp);
  }
  return ans;
}
