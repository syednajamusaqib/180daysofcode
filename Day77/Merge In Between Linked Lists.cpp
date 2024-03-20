class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp1 = list1;
        ListNode *prev = list1;
        ListNode *temp2 = list1;
        ListNode *tail = list2;

        int index = 0;
        while(temp1 != 0 and index < a)
        {
            prev = temp1;
            temp1 = temp1->next;
            index++;
        }

        index = 0;
        while(temp2 != 0 and index < b)
        {
            temp2 = temp2->next;
            index++;
        }

        while(tail != 0 and tail->next != 0) 
        tail = tail->next;

        cout << prev->val << " " << temp2->val << endl;

        prev->next = list2;
        tail->next = temp2->next;

        return list1;
    }
};
