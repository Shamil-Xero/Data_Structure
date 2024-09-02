// https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem?isFullScreen=false

SinglyLinkedListNode *removeDuplicates(SinglyLinkedListNode *llist)
{
    if (llist == NULL || llist->next == NULL)
    {
        return llist;
    }

    SinglyLinkedListNode *current = llist, *next_node = current->next;

    while (next_node != NULL)
    {
        if (current->data == next_node->data)
        {
            current->next = next_node->next;
        }
        else
        {
            current = next_node;
        }
        next_node = next_node->next;
    }

    return llist;
}
