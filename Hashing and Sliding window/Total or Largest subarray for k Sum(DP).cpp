Tc=o(nlogn)
int maxLen(vector<int>&arr, int k)//k=sum{   
    int n=arr.size();
    map<int, int>m;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == k) maxLen = i + 1;              //For Index of largest subarray : if(..) 0 to i;
        if (m.find(sum) == m.end())
            m[sum] = i;
        if (m.find(sum - k) != m.end()) {
                                                  
            if (maxLen < (i - m[sum - k]))
                maxLen = i - m[sum - k];           //For Index of largest subarray : if(..) m[sum-k] to i;
        }
    }
    return maxLen;                            
}


Total:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        map<int,int> m;
        int cnt = 0; 
        rec[0]++; 
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            cnt += m[sum-k];  // presence of sum-k represent that k sum subarray is present ending at this element such that   (subarray from 0 index to somewhere in middle)sum-k  + (subarray from somewhere in middle to current index)k = sum  
            m[sum]++;
        }
        return cnt;
    }

    //Total subarray divisible by k 
    for(int i = 0; i < A.size(); i++) {
            sum = (sum + A[i]) % K; 
            if(sum<0) sum+=K; 
            cnt += m[sum]; 
            m[sum]++;
    }
