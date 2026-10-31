class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int car = 0;

        while (temp1 != NULL && temp2 != NULL) {
            int x = temp1->val;
            int y = temp2->val;

            int z = x + y + car;
            car = z / 10;

            temp1->val = z % 10;
            temp2->val = z % 10;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if (temp1 != NULL) {
            ListNode* prev = NULL;

            while (temp1 != NULL) {
                prev = temp1;

                int cur = temp1->val + car;
                car = cur / 10;
                temp1->val = cur % 10;

                temp1 = temp1->next;
            }

            if (car != 0) {
                prev->next = new ListNode(car);
            }

            return head1;
        }

        if (temp2 != NULL) {
            ListNode* prev = NULL;

            while (temp2 != NULL) {
                prev = temp2;

                int cur = temp2->val + car;
                car = cur / 10;
                temp2->val = cur % 10;

                temp2 = temp2->next;
            }

            if (car != 0) {
                prev->next = new ListNode(car);
            }

            return head2;
        }

        // both lists ended together
        if (car != 0) {
            ListNode* tail = head1;

            while (tail->next != NULL) {
                tail = tail->next;
            }

            tail->next = new ListNode(car);
        }

        return head1;
    }
};