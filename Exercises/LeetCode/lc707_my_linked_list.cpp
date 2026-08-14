#include <string.h>
#include <stdlib.h>

typedef struct MyLinkedList
{
    int val;
    struct MyLinkedList *next;
} MyLinkedList;

MyLinkedList *myLinkedListCreate()
{
    MyLinkedList *head = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    head->next = NULL;
    head->val = -1;
    return head;
}

int myLinkedListGet(MyLinkedList *obj, int index)
{
    if (index < 0)
        return -1;
    MyLinkedList *cur = obj->next;
    for (int i = 0; cur != NULL; i++)
    {
        if (i == index)
            return cur->val;
        cur = cur->next;
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    MyLinkedList *node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    node->val = val;
    node->next = obj->next;
    obj->next = node;
}

void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    MyLinkedList *node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    node->val = val;
    node->next = NULL;

    MyLinkedList *cur = obj;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = node;
}

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    MyLinkedList *pre = obj;
    for (int i = 0; i < index && pre != NULL; i++)
        pre = pre->next;
    if (pre == NULL) return;

    MyLinkedList *node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    node->val = val;
    node->next = pre->next;
    pre->next = node;
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
    MyLinkedList *pre = obj;
    for (int i = 0; i < index && pre != NULL; i++)
        pre = pre->next;
    if (pre == NULL || pre->next == NULL) return; 
    MyLinkedList *tmp = pre->next;
    pre->next = pre->next->next;
    free(tmp);
}

void myLinkedListFree(MyLinkedList *obj)
{
    MyLinkedList *cur = obj->next;
    while (cur != NULL)
    {
        MyLinkedList *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/