#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* ReverseListNode(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* curr = head;
    while(curr) {
        ListNode* temp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = temp;
    }
    return pre;
}

ListNode* buildListNode(int array[], int n) {
    ListNode* dummy = new ListNode(-1);
    ListNode* curr = dummy;
    for(int i = 0; i < n; i++) {
        ListNode* node = new ListNode(array[i]);
        curr->next = node;
        curr = curr->next;
    }
    return dummy->next;
}

void printListNode(ListNode* listNode) {
    ListNode* curr = listNode;
    while(curr != nullptr) {
        cout << " " << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode* PlusOne(ListNode* head) {
    ListNode* rHead = ReverseListNode(head);
    ListNode* curr = rHead;
    curr->val += 1;
    while(curr) {
        if(curr->val > 10) {
            int newValue = curr->val % 10;
            int carry =  curr->val / 10;
            curr->val = newValue;
            ListNode* newNode = new ListNode(carry);
            ListNode* temp = curr->next;
            curr->next = newNode;
            newNode->next = temp;            
        } 
        curr = curr->next;
        
    }
    return ReverseListNode(rHead);
}


int main() {
    cout << "ListNode add 1 test." << endl;
    int array[] = {1, 2, 3};
    int n = sizeof(array) / sizeof(array[0]);

    ListNode* listNode = buildListNode(array, n);
    printListNode(listNode);

    //ListNode* reversedListNode = ReverseListNode(listNode);
    //printListNode(reversedListNode);

    ListNode* plusOne = PlusOne(listNode);
    printListNode(plusOne);


}