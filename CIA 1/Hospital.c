#include <stdio.h>
#include <stdlib.h>

typedef struct Patient
{
    int id;
    int severity;
    struct Patient *next;
} Patient;

typedef struct Priority
{
    Patient *front;
} Priority;

void initialize(Priority *q)
{
    q->front = NULL;
}

void enqueue(Priority *q, int id, int severity)
{
    Patient *newPatient = (Patient *)malloc(sizeof(Patient));
    newPatient->id = id;
    newPatient->severity = severity;
    newPatient->next = NULL;

    if (q->front == NULL || q->front->severity < severity)
    {
        newPatient->next = q->front;
        q->front = newPatient;
    }
    else
    {
        Patient *current = q->front;
        while (current->next != NULL && current->next->severity >= severity)
        {
            current = current->next;
        }
        newPatient->next = current->next;
        current->next = newPatient;
    }
}

void dequeue(Priority *q)
{
    if (q->front == NULL)
    {
        printf("Priority queue is empty.\n");
        return;
    }
    Patient *temp = q->front;
    q->front = q->front->next;
    printf("\nTreated Patient ID: %d, Severity: %d\n", temp->id, temp->severity);
    free(temp);
}

void display(Priority *q)
{
    Patient *current = q->front;
    printf("\nPatients...\n");
    while (current != NULL)
    {
        printf("\nPatient ID: %d, Severity: %d", current->id, current->severity);
        current = current->next;
    }
}

int main()
{
    Priority q;
    initialize(&q);

    enqueue(&q, 1, 10);
    enqueue(&q, 2, 5);
    enqueue(&q, 3, 8);
    enqueue(&q, 4, 2);

    display(&q);

    dequeue(&q);

    display(&q);

    return 0;
}
