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




total subarrays with k integers
    int count(vector<int>& nums, int k){
        unordered_map<int,int>m;
        int i=0, c=0;
        for(int j=0;j<nums.size();j++){
            m[nums[j]]++;
            while(m.size()>k){
                m[nums[i]]--;
                if(m[nums[i]]==0)
                    m.erase(nums[i]);
                i++;
            }
            c+=(j-i+1);
        }
        return c;
    }
