//Knight Tour ::o(8^(n^2)) 

int DirX[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int DirY[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
 
bool isSafe(int i, int j, int n,vector<vector<int> >& Board){
    return (i>=0 && j>=0 && i<n && j<n && Board[i][j] == 0);
}
 

bool isPossible = false;

void knightTour(vector<vector<int> >& ChessBoard, int N, int x, int y, int visitedOrMoveno){
    ChessBoard[x][y] = visitedOrMoveno;
 
    if(visited == N*N){
        isPossible = true;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                cout << ChessBoard[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        ChessBoard[x][y] = 0;
        return;
    }
 
    for (int i = 0; i < 8; i++) {
        int newX = x + DirX[i];
        int newY = y + DirY[i];
 
        if (isSafe(newX, newY, N, ChessBoard) && !ChessBoard[newX][newY])
            knightTour(ChessBoard, N, newX, newY, visited + 1);
    }
    ChessBoard[x][y] = 0;
}
 

int main(){
    knightTour(ChessBoard, N, X - 1, Y - 1,1);
    if(ifPossible==0)return -1;
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
        grid[i][j]=temp;// Should i always use?? ????? this line meaning // If you are running multiple dfs i.e, dfs from multiple cells then to make visited or grid in its original form to reused in another one 
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

