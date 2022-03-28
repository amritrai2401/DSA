int solve(int e,int f){
  if(f==0 || f==1 || e==1)return f;
  int ans=INT_MAX;
  for(int k=1;k<=f;k++){
    int temp=1+max(solve(e-1,k-1),solve(e,f-k));
    ans=min(ans,temp);
  }
  return ans;
}
