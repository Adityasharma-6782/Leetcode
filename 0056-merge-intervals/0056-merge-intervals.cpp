class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i=0; i<intervals.size(); i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
            if(!ans.empty() && ans.back()[1]>=start) 
                ans.back()[1] = max(ans.back()[1], end);
            else ans.push_back({start, end});
        }
        return ans;
    }
};



// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         sort(intervals.begin(), intervals.end());
//         vector<vector<int>> ans;
//         for (int i = 0; i < intervals.size(); i++) {
//             int start = intervals[i][0];
//             int end = intervals[i][1];
//             for (int j = i + 1; j < intervals.size(); j++) {
//                 if (end >= intervals[j][0]) 
//                     end = max(end, intervals[j][1]);
//                 else break;
//             }
//             ans.push_back({start, end});
//             while (i + 1 < intervals.size() && intervals[i + 1][0] <= end) {
//                 i++;
//             }
//         }
//         return ans;
//     }
// };
