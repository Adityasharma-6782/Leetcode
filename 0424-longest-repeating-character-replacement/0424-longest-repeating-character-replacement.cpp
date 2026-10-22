class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int ans=0;
        int left=0;
        int maxFreq=0;
        for(int right=0; right<s.length(); right++){
            mp[s[right]]++;
            maxFreq = max(maxFreq, mp[s[right]]);
            while(((right-left+1)-maxFreq)>k){
                mp[s[left]]--;
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};
