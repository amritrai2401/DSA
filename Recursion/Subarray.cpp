Tc:n^2 
void solve(vector<int>&arr, int c, vector<vector<int>>&ans){
        if(c==arr.size())return;
        vector<int>temp;
        for (int i = c; i <arr.size() ; i++) {
            temp.push_back(arr[i]);
            ans.push_back(temp);
        }
        
        solve(arr,c+1,ans); 
}

Iterative:
void solve(vector<int>&arr){
     vector<vector<int>>ans;
     vector<int>temp;
     for(int i=0;i<arr.size();i++){
         temp.clear();
         for(int j=i;j<arr.size();j++){
               temp.push_back(arr[i]);
               ans.push_back(temp);
         }
     }
}
