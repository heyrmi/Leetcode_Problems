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

//&& fast->next->next != NULL

/*  
    TC: O(n)
    SC: O(1)
*/

class Solution {
public:
    
    ListNode* reverseList(ListNode* head){
        ListNode* pre = NULL;                                       //make 2 dummy variables
        ListNode* next = NULL;
        while(head != NULL){        
            next = head->next;                                      //structure will be {pre, head, next}
            head->next = pre;                                       //head points to pre
            pre = head;                                             //pre increments by one element
            head = next;                                            //head increments by one elemment
        }
        return pre;                                                 //return the final reversed list
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;         //return true if empty or 1 element
   
        ListNode *slow = head;                                      //assign slow and fast pointer to head
        ListNode *fast = head; 
        
        while(fast->next != NULL && fast->next->next != NULL ){     //find middle of LL  
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverseList(slow->next);                       //reverse list from slow's next element
        slow = slow->next;                                          //slow one element ahead
        
        while(slow != NULL){                                        
            if(head->val != slow->val)                              //compare values form start with slow 
                return false;                                       //if reached here then its not palindrome
            head = head->next;                                      //moving slow and head forward
            slow = slow->next;
        }
        return true;                                                //if reached here then palindrome
        
        
    }
    
     
    
};