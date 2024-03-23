class Solution {
public:
    ListNode* getMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
           slow=slow->next;
           fast=fast->next->next;   
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head){ 
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(head){
           next=head->next;
           head->next=prev;
           prev=head;
           head=next; 
        }
        return prev;
    }
    void reorderList(ListNode* head) {
         ListNode* mid=getMiddle(head);
         ListNode* second=reverseList(mid->next);
         mid->next=NULL; // set next of middle element to null to avoid cyclic path
         ListNode* first = head;
         
         while(second){
             ListNode* temp1=first->next;     
             ListNode* temp2=second->next;
             first->next = second;
             second->next = temp1;
             first = temp1;
             second = temp2;
         }
    }
};
