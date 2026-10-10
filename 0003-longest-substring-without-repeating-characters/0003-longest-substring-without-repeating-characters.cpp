class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=INT_MIN;
        int low=0;

        for(int high=0; high<s.length(); high++){
            for(int i=low; i<high; i++){
                if(s[i]==s[high]){
                    low = i + 1;
                    break;
                }
            }
            ans = max(ans, high-low+1);
        }
        if(ans==INT_MIN) return 0;
        return ans;
    }
};