class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {  

    int l = 0;
    int h = arr.size() - 1;
    int max = arr[0];
    int index=0;

    while (l <= h)
    {
        int m = (l + h) / 2;
        if (arr[m] > max)
        {
            max=arr[m];
            index=m;
        }
        if (arr[m] < max)
        {
            l = m + 1;
        }
        else
            h = m - 1;
    }
    return index;
    }
};