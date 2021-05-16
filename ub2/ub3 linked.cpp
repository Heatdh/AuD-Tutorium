#include <stdio.h>
#include <limits.h>
struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int v)
    {
        data = v;
        next = NULL;
    }
};
class LinkedList
{
    ListNode *head;

public:
    LinkedList() { head = NULL; }
    void append(int v)
    {
        append(v, head);
    }
    void print()
    {
        print(head);
    }
    int max() { return max(head); }
    int sum(int i, int j) { return sum(i, j, head); }
    void insertion_sort() { insertion_sort(head); }

private:
    void append(int v, ListNode *&ptr)
    {
        if (ptr == NULL)
            ptr = new ListNode(v);
        else
            append(v, ptr->next);
    }
    void print(ListNode *&ptr)
    {
        if (ptr == NULL)
            return;
        printf("%d ", ptr->data);
        print(ptr->next);
    }
    int max(ListNode *&ptr)
    {
        if (ptr == NULL)
        { // the list is empty
            return INT_MIN;
        }
        else
        { // sonst
            int max_rec = max(ptr->next);
            if (ptr->data > max_rec)
                return ptr->data;
            else
                return max_rec;
        }
    }
    int sum(int i, int j, ListNode *&ptr)
    {
        if (ptr == NULL || j < 0)
        {
            return 0;
        }
        else
        {
            if (i > 0)
            {
                return sum(i - 1, j - 1, ptr->next);
            }
            else
            {
                return ptr->data + sum(0, j - 1, ptr->next);
            }
        }
    }
    void sorted_insert(ListNode *node)
    {
        return sorted_insert(node, head);
    }
    void sorted_insert(ListNode *node, ListNode *&ptr)
    {
        // case where the list empty or in the correct place
        if (ptr == NULL || ptr->data >= node->data)
        {
            node->next = ptr;
            ptr = node;
        }
        else
            //Search more
            sorted_insert(node, ptr->next);
    }
    void insertion_sort(ListNode *&head)
    {
        // empty list nothing to sort
        if (head == NULL)
            return;
        // sorting starting from  head->next recursively
        insertion_sort(head->next);
        // fuege dann das Element auf das head zeigt in die sortierte Liste an den richtigen Platz ein
        ListNode *help = head;
        head = head->next;
        sorted_insert(help, head);
    }
};
int main()
{
    //Test
    LinkedList *l = new LinkedList();
    l->append(8);
    l->append(9);
    l->append(10);
    l->append(7);
    l->append(6);
    printf("Unsorted:\n");
    l->print();
    printf("\n");
    l->insertion_sort();
    printf("Sorted:\n");
    l->print();
    printf("\n");
    return 0;
}
