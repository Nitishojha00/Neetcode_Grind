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
    ListNode* removeNthFromEnd(ListNode* head, int e) {
        int n = 0;
        e++;
        ListNode *temp = new ListNode(2);
        temp->next = head;
        head = temp;
        while(temp)
        {
            n++;
            temp = temp->next;
        }
        e = n-e+1;
        n = 0;
        temp = head;
        while(temp)
        {
            n++;
            if(e==n)
            {
                ListNode *d = temp->next;
                temp->next = d->next;
                d->next = nullptr;
                delete d;
                break;
            }
            temp = temp->next;
        }
        return head->next;
    }
};
