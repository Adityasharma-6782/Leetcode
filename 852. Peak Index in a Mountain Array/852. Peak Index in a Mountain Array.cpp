class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0, e = arr.size()-1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        // cout << "mid = " << mid << endl << endl;
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        {
            return mid;
        }
        else if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
            // e=mid;
        }
        else 
        {
            e = mid ;
            // s=mid+1;
        }
    }
    return -1;
    }
};
