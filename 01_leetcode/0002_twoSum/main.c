#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode_test {
    int b; 
    double c;
    long d;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* result = NULL; // Pointer to the head of the result list
    struct ListNode* tail = NULL; // Pointer to the last node of the result list
    int carry = 0; // Carry from the previous addition
    
    // Traverse both input lists until both are empty and no carry left
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        
        // Add the current digit of l1 to sum if l1 is not NULL
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        // Add the current digit of l2 to sum if l2 is not NULL
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10; // Calculate the carry for the next iteration
        sum %= 10; // Calculate the current digit of the result

        printf("sizeof(struct ListNode) = %d\n", sizeof(struct ListNode));
        printf("sizeof(struct ListNode_test) = %d\n", sizeof(struct ListNode_test));
        // Create a new node for the current digit of the result
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (newNode == NULL) {
            // Memory allocation failed, return NULL
            return NULL;
        }
        newNode->val = sum;
        newNode->next = NULL;
        
        // If result is empty, set the head and tail to the new node
        if (result == NULL) {
            result = newNode;
            tail = newNode;
        } else {
            // Append the new node to the end of the result list
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    return result; // Return the head of the result list
}

int main() {
    // Test case 1: l1 = 2 -> 4 -> 3, l2 = 5 -> 6 -> 4
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val = 2;
    l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->val = 4;
    l1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->next->val = 3;
    l1->next->next->next = NULL;
    
    struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->val = 5;
    l2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->val = 6;
    l2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;
    
    struct ListNode* result = addTwoNumbers(l1, l2);
    
    /*printf("Test Case 1:\n");
    printf("Input: 2 -> 4 -> 3 + 5 -> 6 -> 4\n");
    printf("Expected Output: 7 -> 0 -> 8\n");
    printf("Actual Output: ");*/
    while (result != NULL) {
        printf("%d -> ", result->val);
        result = result->next;
    }
    printf("\n");
    
    // Free memory allocated for test case 1
    struct ListNode* temp;
    while (l1 != NULL) {
        temp = l1;
        l1 = l1->next;
        free(temp);
    }
    while (l2 != NULL) {
        temp = l2;
        l2 = l2->next;
        free(temp);
    }
    while (result != NULL) {
        temp = result;
        result = result->next;
        free(temp);
    }
    
    return 0;
}
