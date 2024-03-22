class Solution {
private:
    ListNode* getMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head->next) return 1;
        
        ListNode* middle = getMiddle(head);
        
        ListNode* temp = middle->next;
        middle->next = reverse(temp);
        
        ListNode* head1 = head;
        ListNode* head2 = middle->next;
        while(head2){
            if(head2->val!=head1->val){
                return 0;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        return 1;
    }
};
