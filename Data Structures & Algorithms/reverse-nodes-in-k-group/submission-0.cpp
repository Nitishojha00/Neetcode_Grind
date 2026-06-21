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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *b = head ;
         ListNode *first = new ListNode(0);

        first->next = head ;

        head = first ;

      ListNode *second , *third , *store , *y ;
        
        int x;
         int count = 0 ;
        
        while(b)
            {
            count++;
            b = b-> next ;
            }
        count = count / k;

        while(first->next && count )

        {

            count--;
            
            second = first->next ;

            third = second-> next ;

            y = second ; 
            
            x = k-1 ;

            while(x-- && third )

            {

                store = third->next ;

                third->next = second ;

                second = third ;

                third = store ;

            }

        first->next = second ;

        y->next = third ;

        first = y ;

        }

        y = head ;

        head = y -> next ;

        delete y;

       return head;

    }
    
};