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
ListNode *reverse(ListNode *l)
{
    ListNode *curr = l->next;
    ListNode *prev = l;
    prev->next = nullptr;
    while(curr)
    {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp ;
    }

    return prev;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();
        ListNode *temp = head;
        int carry = 0;
        while(l1 && l2)
        {
            int sum = carry+l1->val+l2->val;
            ListNode *t = new ListNode(sum%10);
            t->next = temp;
            temp = t;
            carry = sum/10; 
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1)
        {
            int sum = carry+l1->val;
            ListNode *t = new ListNode(sum%10);
            t->next = temp;
            temp = t;
            carry = sum/10; 
            l1 = l1->next;
        }
        while(l2)
        {
            int sum = carry+l2->val;
            ListNode *t = new ListNode(sum%10);
            t->next = temp;
            temp = t;
            carry = sum/10; 
            l2 = l2->next;
        }

        while(carry)
        {
            int sum = carry;
            ListNode *t = new ListNode(sum%10);
            t->next = temp;
            temp = t;
            carry = sum/10; 
        }
        head = reverse(temp);
        return head->next;
    }
};
