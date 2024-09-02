// https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem?isFullScreen=false

DoublyLinkedListNode *reverse(DoublyLinkedListNode *llist)
{
    DoublyLinkedListNode *current = llist, *temp, *tail;
    for (DoublyLinkedListNode *current = llist; current != NULL; current = current->next)
    {
        tail = current;
    }
    tail = llist;
    for (current = llist; current != NULL; current = current->prev)
    {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        llist = current;
    }
    return llist;
}
