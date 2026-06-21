class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // shifiting all element behind in nums1 i can do it in O(n)
        int s = m+n;
        int i = 1;
        while(m-i>=0)
        {
            swap(nums1[s-i],nums1[m-i]);
            i++;
        }
        i = n;
        int j = 0;
        s = 0;
        while(i<m+n && j<n)
        {
            if(nums1[i]>=nums2[j])
            {
                nums1[s] = nums2[j];
                j++,s++;
            }
            else
            {
                nums1[s] = nums1[i];
                i++,s++;
            }
        }

        while(j<n) nums1[s++] = nums2[j++];

         return ;
    }
};