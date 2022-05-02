//Knight Tour ::

int DirX[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int DirY[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
 
// Function to find if (i, j) is a valid
// cell for the knight to move and it
// exists within the chessboard
bool isSafe(int i, int j, int n,
            vector<vector<int> >& Board)
{
    return (i >= 0 and j >= 0 and i < n and j < n
            and Board[i][j] == 0);
}
 
// Stores whether there exist any valid path
bool isPossible = false;
 
// Recursive function to iterate through all
// the paths that the knight can follow
void knightTour(vector<vector<int> >& ChessBoard, int N,
                int x, int y, int visited = 1)
{
    // Mark the current square of the chessboard
    ChessBoard[x][y] = visited;
 
    // If the number of visited squares are equal
    // to the total number of squares
    if (visited == N * N) {
        isPossible = true;
 
        // Print the current state of ChessBoard
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << ChessBoard[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
 
        // Backtrack to the previous move
        ChessBoard[x][y] = 0;
        return;
    }
 
    // Iterate through all the eight possible moves
    // for a knight
    for (int i = 0; i < 8; i++) {
 
        // Stores the new position of the knight
        // after a move
        int newX = x + DirX[i];
        int newY = y + DirY[i];
 
        // If the new position is a valid position
        // recursively call for the next move
        if (isSafe(newX, newY, N, ChessBoard)
            && !ChessBoard[newX][newY]) {
            knightTour(ChessBoard, N, newX, newY,
                       visited + 1);
        }
    }
 
    // Backtrack to the previous move
    ChessBoard[x][y] = 0;
}
 
// Driver Code
int main()
{
    vector<vector<int> > ChessBoard(5, vector<int>(5, 0));
    int N = ChessBoard.size();
    int X = 1;
    int Y = 1;
 
    knightTour(ChessBoard, N, X - 1, Y - 1);
 
    // If no valid sequence of moves exist
    if (!isPossible) {
        cout << -1;
    }
 
    return 0;
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

