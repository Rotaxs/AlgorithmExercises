#include <iostream>

typedef struct LinkListNode
{
    int data;
    struct LinkListNode *next;
} NODE;

/**
 * @brief 链表头插
 * @param head 头结点
 * @param x 要插入的值
 */
void push_front(NODE *head, int x)
{
    // NODE *node = (NODE *)malloc(sizeof(NODE));
    NODE *node = new NODE;
    node->data = x;
    node->next = head->next;
    head->next = node;
}

// /**
//  * @brief 链表尾插
//  * @param head 头结点
//  * @param x 要插入的值
//  */
// void push_back(NODE **ptail, int x)
// {
//     NODE *node = (NODE *)malloc(sizeof(NODE));
//     node->data = x;
//     (*ptail)->next = node;
//     *ptail = node;
//     node->next = nullptr;
// }

/**
 * @brief 在 pos 处插入
 * @param p 头结点
 * @param pos 插入 x 的位置
 * @param x 要插入的值
 * @return 如果插入成功，返回 true，否则返回 false
 */
bool insert(NODE *p, int pos, int x)
{
    if (pos <= 0 || p == nullptr)
        return false;
    // NODE *node = (NODE *)malloc(sizeof(NODE));
    NODE *node = new NODE;
    node->data = x;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
        if (p == nullptr)
            return false;
    }
    node->next = p->next;
    p->next = node;
    return true;
}

/**
 * @brief 删除链表中元素
 * @param p 头结点
 * @param pos 要删除的值的位置
 * @return 如果删除成功，返回 true，否则返回 false
 */
bool del(NODE *p, int pos)
{
    // 检查头指针是否为空 和 pos 是否符合要求
    if (pos <= 0 || p == nullptr)
        return false;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
        // 如果 p == nullptr，说明 pos 超出链表长度
        if (p == nullptr)
            return false;
    }
    // 此时 p 为要删除元素的上一个元素
    if (p->next == nullptr)
        return false;
    NODE *tmp = p->next;
    p->next = p->next->next;
    delete tmp;
    tmp = nullptr;
    return true;
}

/**
 * @brief 打印链表元素
 * @param head 头结点
 */
void print(NODE *head)
{
    NODE *p = head;
    for (p = p->next; p; p = p->next)
        printf("%d ", p->data);
    printf("\n");
}

/**
 * @brief 清空链表内存
 * @param head 头指针
 */
void destroy(NODE *head)
{
    NODE *current = head;
    NODE *next = head->next;

    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }
}

NODE *createLinkList()
{
    NODE *head;
    // head = (NODE *)malloc(sizeof(NODE));
    head = new NODE;
    head->next = nullptr;
    return head;
}

int main()
{
    NODE *head, *tail;
    tail = head = createLinkList();

    for (int i = 0; i < 5; i++)
        push_front(head, i);

    print(head);

    insert(head, 5, 100);

    // delete(head, 2);

    print(head);

    destroy(head);

    return 0;
}