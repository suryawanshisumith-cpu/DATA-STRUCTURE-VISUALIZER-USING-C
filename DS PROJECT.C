#include <stdio.h>
#include <stdlib.h>

/* ================= STACK ================= */

int stack[100], top = -1;

/* ================= QUEUE ================= */

int queue[100], front = -1, rear = -1;

/* ================= LINKED LIST ================= */

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

/* ================= STACK ================= */

void push()
{
    int x;

    if(top == 99)
    {
        printf("\nStack Full\n");
        return;
    }

    printf("\nEnter element: ");
    scanf("%d", &x);

    stack[++top] = x;

    printf("Pushed %d\n", x);
}

void pop()
{
    if(top == -1)
    {
        printf("\nStack Empty\n");
        return;
    }

    printf("\nPopped %d\n", stack[top--]);
}

void displayStack()
{
    int i;

    if(top == -1)
    {
        printf("\nStack Empty\n");
        return;
    }

    printf("\nStack: ");

    for(i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
}

/* ================= QUEUE ================= */

void enqueue()
{
    int x;

    if(rear == 99)
    {
        printf("\nQueue Full\n");
        return;
    }

    printf("\nEnter element: ");
    scanf("%d", &x);

    if(front == -1)
    {
        front = 0;
    }

    queue[++rear] = x;

    printf("Inserted %d\n", x);
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("\nQueue Empty\n");
        return;
    }

    printf("\nRemoved %d\n", queue[front++]);
}

void displayQueue()
{
    int i;

    if(front == -1 || front > rear)
    {
        printf("\nQueue Empty\n");
        return;
    }

    printf("\nQueue: ");

    for(i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}

/* ================= LINKED LIST ================= */

void insertEnd()
{
    int x;

    struct node *newnode, *temp;

    printf("\nEnter element: ");
    scanf("%d", &x);

    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("Inserted %d\n", x);
}

void deleteNode()
{
    int x;

    struct node *temp = head;
    struct node *prev = NULL;

    if(head == NULL)
    {
        printf("\nList Empty\n");
        return;
    }

    printf("\nEnter element to delete: ");
    scanf("%d", &x);

    if(temp != NULL && temp->data == x)
    {
        head = temp->next;

        free(temp);

        printf("Deleted %d\n", x);

        return;
    }

    while(temp != NULL && temp->data != x)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("\nElement Not Found\n");
        return;
    }

    prev->next = temp->next;

    free(temp);

    printf("Deleted %d\n", x);
}

void displayList()
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("\nList Empty\n");
        return;
    }

    printf("\nLinked List: ");

    while(temp != NULL)
    {
        printf("%d", temp->data);

        if(temp->next != NULL)
        {
            printf(" -> ");
        }
        else
        {
            printf(" -> NULL");
        }

        temp = temp->next;
    }
}

/* ================= BUBBLE SORT ================= */

void bubbleSort()
{
    int arr[100], n, i, j, temp;

    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        printf("\nPass %d: ", i + 1);

        for(j = 0; j < n; j++)
        {
            printf("%d ", arr[j]);
        }
    }

    printf("\nSorted Array: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

/* ================= MAIN ================= */

int main()
{
    int ch;

    while(1)
    {
        printf("\n\n===== FULL DATA STRUCTURE SIMULATOR =====");

        printf("\n1. Stack Push");
        printf("\n2. Stack Pop");
        printf("\n3. Stack Display");

        printf("\n4. Queue Insert");
        printf("\n5. Queue Delete");
        printf("\n6. Queue Display");

        printf("\n7. Linked List Insert");
        printf("\n8. Linked List Delete");
        printf("\n9. Linked List Display");

        printf("\n10. Bubble Sort");

        printf("\n11. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                displayStack();
                break;

            case 4:
                enqueue();
                break;

            case 5:
                dequeue();
                break;

            case 6:
                displayQueue();
                break;

            case 7:
                insertEnd();
                break;

            case 8:
                deleteNode();
                break;

            case 9:
                displayList();
                break;

            case 10:
                bubbleSort();
                break;

            case 11:
                exit(0);

            default:
                printf("\nInvalid Choice");
        }
    }

    return 0;
}