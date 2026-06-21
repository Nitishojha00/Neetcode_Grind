class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // dooing it using 2 pointer approach
        int n = nums1.size() , m = nums2.size();
        int mid = (n+m-1)/2;
        int i = 0 , j = 0;
        while(i<n && j<m  && mid!=0)
        {
            if(nums1[i]<nums2[j])
            {
                i++;
            }
            else 
            {
                j++;
            }
                mid--;
        }

        while(mid && i<n)
           mid--,i++;
        
        while(mid && j<m)
            mid-- , j++;

        if((n+m)%2==0) //okay i have to return mid
        {
            double sum = 0;
            if(i<n && j<m)
            {
                if(nums1[i]<nums2[j])
                {
                    sum+=nums1[i++];
                        if(i==n || nums1[i]>=nums2[j])
                        {
                            sum+=nums2[j];
                        }
                        else
                        {
                            sum+=nums1[i];
                        }
                }
                else
                {
                    sum+=nums2[j++];
                        if(j==m || nums1[i]<=nums2[j])
                        {
                            sum+=nums1[i];
                        }
                        else
                        {
                            sum+=nums2[j];
                        }
                    
                }

                return sum/2;
            }
            else if(i<n)
            {
                return (nums1[i]+nums1[i+1])/2.0;
            }
            else
            {
                 return (nums2[j]+nums2[j+1])/2.0;
            }
        }
        else
        {
            if(i<n && j<m)
            {
                if(nums1[i]<nums2[j]) return nums1[i];
                else return nums2[j];
            }
            else if(i<n)
            {
                return nums1[i];
            }
            else
            {
                return nums2[j];
            }
        }

        return -1;
    }
};