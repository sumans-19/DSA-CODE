// 4) Design, Develop and implement menu driven program to simulate processing of
// batch jobs by a computer system. The scheduling of these jobs should be handled
// using a priority queue.
// Note: The Program should allow users to add or remove items from the queue and it should
// also display current status i.e. the total number of items in the queue.

CODE : 
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int front = -1, rear = -1;
typedef struct process
{
    int pid;
    int pr;
    int bt;
} job;
job pjob[MAX];
void insert()
{
    int pid, pr, bt;
    if (rear == MAX - 1)
    {
        printf("Overflow");
    }
    else
    {
        printf("Enter PID, PR AND BT: ");
        scanf("%d %d %d", &pid, &pr, &bt);
        if (rear == -1)
        {
            rear++;
            front++;
        }
        else
        {
            rear++;
        }
        pjob[rear].pid = pid;
        pjob[rear].pr = pr;
        pjob[rear].bt = bt;
    }
}
void delete()
{
    int i, pos = 0, max = 0;
    if (front == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            for (i = front; i <= rear; i++)
            {
                if (pjob[i].pr > max)
                {
                    max = pjob[i].pr;
                    pos = i;
                }
            }
            for (i = pos; i <= rear; i++)
            {
                pjob[i].pid = pjob[i + 1].pid;
                pjob[i].pr = pjob[i + 1].pr;
                pjob[i].bt = pjob[i + 1].bt;
            }
            rear--;
        }
    }
}
void display()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("PID\t PR\t BT\n");
            printf("%d\t %d\t %d\n", pjob[i].pid, pjob[i].pr, pjob[i].bt);
        }
    }
}
void main()
{
    int ch;
    while (ch < 5)
    {
        printf("\n1.Insert\t 2.Display\t 3.Delete\t 4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            delete();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid choice:\n");
            break;
        }
    }
}

// Fuck you bitch