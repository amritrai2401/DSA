Tc=o(n)
//Sliding window is only  for positive array
int subarraySum(vector<int>& nums, int k) {
        map<int, int> seen = {{0, 1}};
        int count = 0, sum = 0;
        for (auto n: nums) {
            sum += n;
            count += seen[sum - k];
            seen[sum]++;
        }
        return count;
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
