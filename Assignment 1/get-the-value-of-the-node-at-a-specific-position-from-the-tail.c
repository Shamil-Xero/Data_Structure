// https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem?isFullScreen=false

int getNode(SinglyLinkedListNode *llist, int positionFromTail)
{
    SinglyLinkedListNode *current = llist;
    int num_nodes = 0;
    if (llist != NULL)
    {
        while (current != NULL)
        {
            num_nodes++;
            current = current->next;
        }
    }
    current = llist;
    for (int i = 1; i < num_nodes - positionFromTail; i++)
    {
        current = current->next;
    }
    return current->data;
}
