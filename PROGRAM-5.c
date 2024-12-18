// 5) Design, Develop and implement c program using singly linked list for the following
// scenario
// a. There are two linked list A and B containing the following data: A: 3,7,10,15,16,09,22,17,32
// and B: 16,02,09,13,37,08,10,01,28
// b. Create a linked list C that contains only those elements that are common in linked list A
// and B
// c. Create a linked list D which contains all elements of A as well as B ensures that there is no
// repetition of elements.

CODE : 
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} NODE;
NODE *LLone, *LLtwo, *unionLL, *interLL;
NODE *insert(NODE **first, int num)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = num;
    newNode->link = *first;
    *first = newNode;
    return *first;
}
int search(NODE *first, int num)
{
    while (first != NULL)
    {
        if (first->data == num)
        {
            return 1;
        }
        first = first->link;
    }
    return 0;
}
NODE *findunion(NODE *LLone, NODE *LLtwo)
{
    unionLL = NULL;
    NODE *temp = LLone;
    while (temp != NULL)
    {
        insert(&unionLL, temp->data);
        temp = temp->link;
    }
    while (LLtwo != NULL)
    {
        if (!search(LLone, LLtwo->data))
        {
            insert(&unionLL, LLtwo->data);
        }
        LLtwo = LLtwo->link;
    }
    return unionLL;
}
NODE *intersection(NODE *LLone, NODE *LLtwo)
{
    interLL = NULL;
    while (LLone != NULL)
    {
        if (search(LLtwo, LLone->data))
        {
            insert(&interLL, LLone->data);
        }
        LLone = LLone->link;
    }
    return interLL;
}
void printList(NODE *cur)
{
    while (cur != NULL)
    {
        printf("-->%d", cur->data);
        cur = cur->link;
    }
}
void main()
{
    int i, LLonecount, LLtwocount, temp;
    printf("\n Enter number of nodes in first Linked List: ");
    scanf("%d", &LLonecount);
    printf("\n Enter data of first linked list: ");
    for (i = 0; i < LLonecount; i++)
    {
        scanf("%d", &temp);
        insert(&LLone, temp);
    }
    printList(LLone);
    printf("\n Enter number of nodes in second Linked List: ");
    scanf("%d", &LLtwocount);
    printf("\n Enter data of second linked list: ");
    for (i = 0; i < LLtwocount; i++)
    {
        scanf("%d", &temp);
        insert(&LLtwo, temp);
    }
    printList(LLtwo);
    findunion(LLone, LLtwo);
    intersection(LLone, LLtwo);
    printf("\nUnion Linked List\n");
    printList(unionLL);
    printf("\nIntersection Linked List\n");
    printList(interLL);
}
