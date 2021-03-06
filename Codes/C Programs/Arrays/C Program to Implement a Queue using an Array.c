/*This C Program implements a queue using array. Queue is a is a particular kind of abstract data type or collection in which the entities in the collection are kept in order and the principal (or only) operations on the collection are the addition of entities to the rear terminal position and removal of entities from the front terminal position. This makes the queue a First-In-First-Out (FIFO) data structure.*/


/*
 * C Program to Implement a Queue using an Array
 */
#include <stdio.h>

#define MAX 50
int queue_array[MAX];
int rear = - 1;
int front = - 1;
main()
{
    int choice;
    while (1)
        {
            printf("1.Insert element to queue \n");
            printf("2.Delete element from queue \n");
            printf("3.Display all elements of queue \n");
            printf("4.Quit \n");
            printf("Enter your choice : ");
            scanf("%d", &choice);
            switch (choice)
                {
                case 1:
                    insert();
                    break;
                case 2:
                    delete();
                    break;
                case 3:
                    display();
                    break;
                case 4:
                    exit(1);
                default:
                    printf("Wrong choice \n");
                } /*End of switch*/
        } /*End of while*/
} /*End of main()*/
insert()
{
    int add_item;
    if (rear == MAX - 1)
        printf("Queue Overflow \n");
    else
        {
            if (front == - 1)
                /*If queue is initially empty */
                front = 0;
            printf("Inset the element in queue : ");
            scanf("%d", &add_item);
            rear = rear + 1;
            queue_array[rear] = add_item;
        }
} /*End of insert()*/

delete()
{
    if (front == - 1 || front > rear)
        {
            printf("Queue Underflow \n");
            return ;
        }
    else
        {
            printf("Element deleted from queue is : %d\n", queue_array[front]);
            front = front + 1;
        }
} /*End of delete() */
display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
        {
            printf("Queue is : \n");
            for (i = front; i <= rear; i++)
                printf("%d ", queue_array[i]);
            printf("\n");
        }
} /*End of display() */

/*
1.Insert element to queue
2.Delete element from queue
3.Display all elements of queue
4.Quit
Enter your choice : 1
Inset the element in queue : 10
1.Insert element to queue
2.Delete element from queue
3.Display all elements of queue
4.Quit
Enter your choice : 1
Inset the element in queue : 15
1.Insert element to queue
2.Delete element from queue
3.Display all elements of queue
4.Quit
Enter your choice : 1
Inset the element in queue : 20
1.Insert element to queue
2.Delete element from queue
3.Display all elements of queue
4.Quit
Enter your choice : 1
Inset the element in queue : 30
1.Insert element to queue
2.Delete element from queue
3.Display all elements of queue
4.Quit
Enter your choice : 2
Element deleted from queue is : 10
1.Insert element to queue
2.Delete element from queue
3.Display all elements of queue
4.Quit
Enter your choice : 3
Queue is :
15 20 30
1.Insert element to queue
2.Delete element from queue
3.Display all elements of queue
4.Quit
Enter your choice : 4

