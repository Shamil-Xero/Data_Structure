// https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem?isFullScreen=false

bool has_cycle(SinglyLinkedListNode *head)
{
    SinglyLinkedListNode *temp = head;
    int add[1000], i = 0;
    add[i] = (int)temp;
    while (temp->next != NULL)
    {
        int j;
        temp = temp->next;
        for (j = 0; j <= i; j++)
        {
            if ((int)temp == add[j])
            {
                return 1;
            }
        }
        i++;
        add[i] = (int)temp;
    }
    return 0;
}
