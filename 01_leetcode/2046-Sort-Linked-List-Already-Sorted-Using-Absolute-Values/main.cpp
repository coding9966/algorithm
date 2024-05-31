#include <iostream>
#include <vector>

using namespace std;

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

   ListNode* sortLinkedList(ListNode* head) {
        // Create a dummy node to simplify insertion at the beginning
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;

        while (curr->next) {
            if (curr->next->val < 0) {
                // If the next node is negative, move it to the beginning
                ListNode* temp = curr->next;
                curr->next = temp->next; // Remove temp from its current position
                temp->next = dummy->next; // Insert temp at the beginning
                dummy->next = temp; // Update dummy's next pointer
            } else {
                // Move to the next node if it's positive
                curr = curr->next;
            }
        }

        // Return the head of the sorted list (dummy's next pointer)
        return dummy->next;
   }    

};

ListNode* buildList(vector<int> value ) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for(auto i : value) {
        ListNode* node = new ListNode(i);
        curr->next = node;
        curr = curr->next;        
    }
    return dummy->next;
}

void printList(ListNode* list) {
    ListNode* curr = list;
    while(curr) {
        cout << " " << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {

    vector<int> listValues = {1, 2, -3};
    ListNode* list = buildList(listValues);
    printList(list);

    ListNode* sortedList = Solution().sortLinkedList(list);
    printList(sortedList);

    return 0;
}
