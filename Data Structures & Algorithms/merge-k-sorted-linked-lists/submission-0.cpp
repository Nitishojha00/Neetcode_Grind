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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
          priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<>>pq;
        ListNode *ans = new ListNode(-1);
        ListNode *temp = ans;
        for(int i=0;i<lists.size();i++)
        {
             pq.push({lists[i]->val,lists[i]});
        }

        while(!pq.empty())
        {
            auto [v,t] = pq.top();
            pq.pop();
            temp->next = t;
            temp = temp->next;
            if(t->next)
              pq.push({t->next->val,t->next});
        }
            return ans->next;
    }
};
