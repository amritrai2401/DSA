void dfs(int c) {
    vis[c] = 1;
    for(auto i:g[c]){
        if(vis[i]==0) {
            dfs(i);
        }
    }
}
