#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0) return true;
        if(s.length()<=t.length()){
            int i=0, j=0;
            bool flag;
            while(i<s.length() && j<t.length()){
                flag = false;
                if(s[i]==t[j]){
                    i++;
                    flag = true;
                }
                j++;
            }
            if(i==s.length()) return flag;
            else return false;
        }
        return false;
    }
};