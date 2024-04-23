#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode_1 {
    int b; 
    double c;
    long d;
};

struct ListNode_2 {
    char c[3];
    char d[4];
    int a;
};

struct ListNode_3 {
    char a;
    //int b;
    //char c;
};


int main() {
     
    printf("sizeof(char) = %d\n", sizeof(char));
    printf("sizeof(int) = %d\n", sizeof(int));
    printf("sizeof(double) = %d\n", sizeof(double));
    printf("sizeof(long) = %d\n", sizeof(long));
    printf("sizeof(long int) = %d\n", sizeof(long int));
    printf("sizeof(longlong) = %d\n", sizeof(long long));
    printf("sizeof(float) = %d\n", sizeof(float));
    printf("sizeof(long double) = %d\n", sizeof(long double));
    
    printf("\n");
    struct ListNode_1* node_1 = (struct ListNode_1*)malloc(sizeof(struct ListNode_1));
    printf("sizeof(ListNode) = %d\n", sizeof(struct ListNode));
    printf("sizeof(ListNode_1) = %d\n", sizeof(struct ListNode_1));
    printf("sizeof(ListNode_2) = %d\n", sizeof(struct ListNode_2));
    printf("sizeof(ListNode_3) = %d\n", sizeof(struct ListNode_3));
}