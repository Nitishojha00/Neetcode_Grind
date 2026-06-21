class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        vector<int>freq(1001);
        int n = hand.size();
        for(int i=0;i<n;i++)
        {
            freq[hand[i]]++;
        }
        for(int i=0;i<1001;i++)
        {
            if(freq[i])
            {
                int val = freq[i];
                for(int j=i+1;j<i+groupSize;j++)
                {
                    cout<<j<<endl;
                    if(freq[j]<val) return false;
                    freq[j]-=val;
                }
            }
        }

        return true;
    }
};
