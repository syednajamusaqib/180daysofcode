class Solution{
public:
    ListNode *solve(ListNode *head) {
        if (!head) 
            return head;
        

        int sum = 0;
        ListNode *curr = head;
        while (curr) {
            sum = sum + curr->val;
            curr = curr->next;
            if (sum == 0)
                return solve(curr);
        }

        head->next = solve(head->next);
        return head;
    }

    ListNode *removeZeroSumSublists(ListNode *head) {
        return solve(head);
    }
};
