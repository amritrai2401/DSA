int solve(string s,int i,int j,char istrue){
  if(i>j)return 0;
  if(i==j){
    if(s[i]==istrue)return 1;
    else return 0;
  }
  int ans=0;
  for(int k=i+1;k<j;k=k+2){
    int leftT=solve(s,i,k-1,1);
    int leftF=solve(s,i,k-1,0);
    int rightT=solve(s,k+1,j,1);
    int rightF=solve(s,k+1,j,0);
    if(s[k]=='&'){
      if(istrue) ans+=leftT*rightT;
      else ans+=leftF*rightF +leftT*rightF +leftF*rightT;
    }
    else if(s[k]=='|'){
      if(istrue)ans+=leftT*rightT + leftT*rightF + leftF*rightT;
      else ans+=leftF*rightF;
    }
    else if(s[k]=='^'){
      if(istrue) ans+=leftF*rightT +leftT*rightF;
      else ans+=leftT*rightT + leftF*rightF;
    }
  }
  return ans;
}
