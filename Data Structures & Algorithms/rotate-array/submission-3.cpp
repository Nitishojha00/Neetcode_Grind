class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    int count = 0;  // how many elements have been moved

    int i = 0;
    while(count<n)
    {
       int value = nums[i];
       int j = (i+k)%n;
       while(j!=i)
       {
          swap(nums[j],value);
          count++;
          j = (j+k)%n;
       }
       nums[i] = value;
       count++;
       i++;
    }

    return ;

}

};