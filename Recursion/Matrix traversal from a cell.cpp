//Knight Tour ::

int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool isValid(int x, int y, int sol[N][N]) {
   return ( x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

int knightTour(int x, int y, int move, int sol[N][N], int xMove[N], int yMove[N]) {
   if (move == N*N) return true;

   for (int k = 0; k < 8; k++) {  //NO OF MOVES knight can move NOT NO of rows or columns 
      int xNext = x + xMove[k], yNext = y + yMove[k];
      if (isValid(xNext, yNext, sol)) {
         sol[xNext][yNext] = move;
         if (knightTour(xNext, yNext, move+1, sol, xMove, yMove) == true) return true;
         else sol[xNext][yNext] = -1;
      }
   }
   return false;
}



// Maximum Gold 

static vector<int> directions={0,1,0,-1,0};

int dfs(vector<vector<int>> &grid,int i,int j){
        int temp=grid[i][j],result=0;
        grid[i][j]=0;
        for(int d=0;d<4;d++){                   //Try all 4 possible directions
            int x=i+directions[d],y=j+directions[d+1];
            if(x>=0&&y>=0&&x<grid.size()&&y<grid[x].size()&&grid[x][y]!=0)
                result=max(result,grid[x][y]+dfs(grid,x,y));  //Set grid[i][j] to 0 to mark as visited before next dfs and reset the values after the dfs ends
        }
        grid[i][j]=temp; // If you are running multiple dfs i.e, dfs from multiple cells then to make visited or grid in its original form to reused in another one 
        return result;
}
    
int getMaximumGold(vector<vector<int>>& grid) {
        int result=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]>0)
                    result=max(grid[i][j]+dfs(grid,i,j),result);   //Set grid[i][j] to 0 to mark this cell as visited and reset after the dfs ends.
        return result;
}






//All Matrix Paths with any number of jumps allowed /Nados

vector<string> get_maze_paths(int sr, int sc, int dr, int dc) {
    if(sr == dr && sc == dc){
        vector<string> empty_ans;
        empty_ans.push_back("");
        return empty_ans;
    }
    
    vector<string> ans;
    
    for(int jump = 1; jump+sc <=dc; jump++){  // IF no jumps remove this for loop with if condition  
        vector<string> h_paths = get_maze_paths(sr, sc+jump, dr, dc);
        
        for(string str : h_paths){
            ans.push_back("h" +to_string(jump)+ str);
        }
    }
    
    for(int jump = 1; jump + sr <=dr; jump++){     
        vector<string> v_paths = get_maze_paths(sr+jump, sc, dr, dc);
            for(string str : v_paths){
               ans.push_back("v" +to_string(jump)+ str);
        }
    }
    
    
    for(int jump =1; jump+sr<=dr && jump+sc <=dc; jump++){  //diagonal
        vector<string> d_paths = get_maze_paths(sr+jump, sc+jump, dr, dc);
            for(string str : d_paths){
                ans.push_back("d" +to_string(jump)+ str);
        }
        }
    return ans;
}

