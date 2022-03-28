void solve(string coins, int i,int amt, int target, vi &vis, vi temp, vector<vi>&ans){
        if(i >coins.size())return;            //All permutations: if(i==coins.size()) ans.pb(temp);
        if(amt == target){          
            ans.push_back(temp);
            return;
        }
        for(int j = 0; j < coins.size(); j++){
            if(used[j] == 0){                                            //Remove for unbounded
                if (i > 0 && num[i] == num[i-1] && visited[i-1]) return; //Remove for unbounded
                vis[j] = 1;                                              //Remove for unbounded
                temp.push_back(coins[j]);                                
                solve(coins, i+1,amt+coins[i], target, used,temp,ans);
                temp.pop_back();                   
                vis[j] = 0;                                              //Remove for unbounded
            }
        }
}
