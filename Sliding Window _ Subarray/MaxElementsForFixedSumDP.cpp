Tc=o(n)
//Sliding window is only  for positive array   this works for both pos and neg  longest subarray with 0 sum

    int maxLen(vector<int>&arr, int k)//k=sum
    {   
            int n=arr.size();
            unordered_map<int, int> um;
    int sum = 0, maxLen = 0;
 
    // traverse the given array
    for (int i = 0; i < n; i++) {
 
        // accumulate sum
        sum += arr[i];
 
        // when subarray starts from index '0'
        if (sum == k)
            maxLen = i + 1;
 
        // make an entry for 'sum' if it is
        // not present in 'um'
        if (um.find(sum) == um.end())
            um[sum] = i;
 
        // check if 'sum-k' is present in 'um'
        // or not
        if (um.find(sum - k) != um.end()) {
 
            // update maxLength
            if (maxLen < (i - um[sum - k]))
                maxLen = i - um[sum - k];
        }
    }
 
    // required maximum length
    return maxLen;
    }

//Longest subarray without repeting characters
int largest_subarray(int a[], int n)
{
    // Stores index of array elements
    unordered_map<int, int> index;
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
  
        // Update j based on previous
        // occurrence of a[i]
        j = max(index[a[i]], j);
  
        // Update ans to store maximum
        // length of subarray
        ans = max(ans, i - j + 1);
  
        // Store the index of current
        // occurrence of a[i]
        index[a[i]] = i + 1;
    }
  
    // Return final ans
    return ans;
}



//Longest substring without repeting characters
int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        map<char,int>m;
        int mx=0;
        while(j<s.size()){
            m[s[j]]++;   
            while(m.size()<j+1-i){   //while(unique char< substring size)        For Longest substring with k unique char: while(m.size()>k) :while(unique char>k)
                    m[s[i]]--;
                    if(m[s[i]]==0)m.erase(s[i]);
                    i++;
            }
            if(m.size()==j-i+1)mx=max(mx,j+1-i);                                 //For long substring with k unique char: if(m.size()==k)
            j++;
        }
        return mx;    //For longest substring with k unique char: if(mx>=k)return mx; else return -1;
}
