/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        int n = 0;
        ListNode *temp = head;
        vector<int>v;
        while(temp)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        n = v.size()-1;
        int i = 0;
        temp = head;
        bool turn = 0;
        while(n>=i)
        {
            if(!turn)
            {
                temp->val = v[i];
                i++;
            }
            else
            {
                temp->val = v[n];
                n--;
            }
            temp = temp->next;
            turn = !turn;
        }

        return;
    }
};
