class Solution {

    int longestTrue(string s, int k){
        int left=0;
        int ans=0;
        int t=0;
        for(int right=0; right<s.length(); right++){
            if(s[right]=='T') t++;

            while(t>k){
               if(s[left]=='T') t--;
               left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }

    int longestFlase(string s, int k){
        int left=0;
        int ans=0;
        int f=0;
        for(int right=0; right<s.length(); right++){
            if(s[right]=='F') f++;

            while(f>k){
               if(s[left]=='F') f--;
               left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }

public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int a = longestTrue(answerKey, k);
        int b = longestFlase(answerKey, k);
        return max(a, b);        
    }
};