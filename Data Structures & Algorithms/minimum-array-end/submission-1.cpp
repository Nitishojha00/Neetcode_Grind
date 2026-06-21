class Solution {
public:
    using ll = long long;

    long long minEnd(int n, int x) {
        ll res = x;
        ll fill = n - 1;  // bits to embed
        ll mask = 1;      // scan through bit positions

        while (fill > 0) {
            if ((res & mask) == 0) {
                if (fill & 1) res |= mask; // fill this unset bit
                fill >>= 1;                // consume one bit of (n-1)
            }
            mask <<= 1; // move to next bit position
        }

        return res;
    }
};
