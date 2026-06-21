#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> pii;

// Simulate multiset with unique IDs
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        indexed_multiset s;
        int n1 = nums1.size(), n2 = nums2.size();
        int id = 0;

        for(int i = 0; i < n1; i++) s.insert({nums1[i], id++});
        for(int i = 0; i < n2; i++) s.insert({nums2[i], id++});

        int total = n1 + n2;
        int mid = total / 2;

        if (total % 2 != 0) {
            return s.find_by_order(mid)->first;
        } else {
            int a = s.find_by_order(mid - 1)->first;
            int b = s.find_by_order(mid)->first;
            return (a + b) / 2.0;
        }
    }
};