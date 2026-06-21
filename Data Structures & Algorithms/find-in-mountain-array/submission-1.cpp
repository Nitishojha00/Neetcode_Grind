/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int FindL(int target,int s,int e, MountainArray &mountainArr)
    {
        while(e>=s)
        {
            int mid = s+(e-s)/2;
            int val = mountainArr.get(mid);
            if(val==target) return mid;

            else if(val>target)
            {
                e = mid-1;
            }
            else
            {
                s = mid+1;
            }
        }
        return -1;
    }
    int FindR(int target, int s, int e, MountainArray &mountainArr) {
    while(s <= e) {
        int mid = s + (e-s)/2;
        int val = mountainArr.get(mid);
        if(val == target) return mid;
        else if(val > target) {
            // since array is decreasing, go right
            s = mid+1;
            } else {
                // go left
                e = mid-1;
            }
        }
        return -1;
}

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int r = mountainArr.length()-1;
        int n = r;
        int l = 0;
        while(l < r) {
            int mid = l + (r-l)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)) {
                l = mid+1; // peak is to the right
            } else {
                r = mid;   // peak is at mid or to the left
            }
        }
        int peak = l; // peak index
        r = mountainArr.length()-1;
        int val1 = FindL(target,0,peak,mountainArr);
        int val2 = FindR(target,peak+1,r,mountainArr);
        //cout<<val2<<endl;
        if(val1==-1) swap(val1,val2);

        return val1;
    }
};