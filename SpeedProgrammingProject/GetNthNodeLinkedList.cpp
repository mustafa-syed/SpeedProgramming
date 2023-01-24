

// Print the nth node in the linked list. Node is defined as:
// Link list node
#include<iostream>
struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }
};


// Should return data of node at given index. The function may
//  assume that there are at least index+1 nodes in linked list
int GetNth(struct node* head, int index) {
    // Code here
    if (index == 1)
        return head->data;
    else
        return GetNth(head->next, index - 1);
}