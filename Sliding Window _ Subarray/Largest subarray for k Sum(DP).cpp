Tc=o(nlogn)
int maxLen(vector<int>&arr, int k)//k=sum{   
    int n=arr.size();
    map<int, int>m;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == k) maxLen = i + 1;              //For total subarrays with sum k : if(..)tot++;   //For Index of largest subarray : if(..) 0 to i;
        if (m.find(sum) == m.end())
            m[sum] = i;
        if (m.find(sum - k) != m.end()) {
                                                   //For total subarrays with sum k :total+=um[sum-k]; 
            if (maxLen < (i - m[sum - k]))
                maxLen = i - m[sum - k];           //For Index of largest subarray : if(..) m[sum-k] to i;
        }
    }
    return maxLen;                                 //For total subarrays with sum k : return tot;
}
