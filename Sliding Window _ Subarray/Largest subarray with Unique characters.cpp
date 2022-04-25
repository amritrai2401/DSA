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
