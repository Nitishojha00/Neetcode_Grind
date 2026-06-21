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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode *front = new ListNode(1);
        front->next = head;
        head = front;
        ListNode *temp = head;
        for(int i=1;i<left;i++)
            temp = temp->next;
        // everything fine till now
        ListNode *aga = temp;
        ListNode *agaWala  = temp->next;
        temp = temp->next;
        aga->next = nullptr;
        ListNode *curr = temp->next;
        temp->next = nullptr;
        for(int i=left;i<right;i++)
        {
          ListNode *nxt = curr->next;
          curr->next = temp;
          temp = curr;
          curr = nxt;
        }

        aga->next = temp;
        agaWala->next = curr;

        return head->next;
    }
};