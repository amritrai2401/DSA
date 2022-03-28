bool cycle;

void dfs(int c, int par) {
    vis[c] = 1; 
    for(auto i:g[c]){
        if(vis[i]==0) {
            dfs(i,c);
            if(cycle==true)return; 
        }
        else if(i!=par)
            cycle=true; 
            return; 
    } 
}
