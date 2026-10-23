class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s = "";
        int i=0;
        int j=0;
        int n1 = word1.length();
        int n2 = word2.length();

        while(i<n1 && j<n2){
            s += word1[i];
            s += word2[i];
            i++;
            j++;

        }

        while(i<n1){
            s += word1[i];
            i++;
        }
        while(j<n2){
            s += word2[j];
            j++;
        }
        return s;
    }
};