bool cycle;

void dfs(int c){
    vis[c]=1; 
    for(auto i:g[c]){
        if(vis[i]==0){
            dfs(i);
            if(cycle==1)return;
        }
        else if(vis[i]==1){
            cycle=1;
            return; 
        }
    }
    vis[c]=2;
    //topo.pb(c)and reverse(topo)after doing dfs for all nodes
}
