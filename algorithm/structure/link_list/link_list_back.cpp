#include <iostream>

typedef struct LinkListNode
{
    int data;
    struct LinkListNode *next;
} NODE;

/**
 * @brief 链表尾插
 * @param head 头结点
 * @param x 要插入的值
 */
void push_back(NODE *&tail, int x)
{
    NODE *node = new NODE;
    node->data = x;
    tail->next = node;
    tail = node;
    node->next = nullptr;
}

/**
 * @brief 在 pos 处插入
 * @param p 头结点
 * @param pos 插入 x 的位置
 * @param x 要插入的值
 * @return 如果插入成功，返回 true，否则返回 false
 */
bool insert(NODE *p, NODE *&tail, int pos, int x)
{
    if (pos <= 0 || p == nullptr)
        return false;
    NODE *node = new NODE;
    node->data = x;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
        if (p == nullptr)
            return false;
    }
    if (p->next == nullptr)
    {
        tail = node;
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
bool del(NODE *p, NODE *&tail, int pos)
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
    // 如果删除元素是尾元素，那么调整尾指针
    if (p->next->next == nullptr)
        tail = p;
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
    head = new NODE;
    head->next = nullptr;
    return head;
}

int main()
{
    NODE *head, *tail;
    tail = head = createLinkList();

    return 0;
}