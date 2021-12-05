#include <stdio.h> 

#include <stdlib.h> 

#include <limits.h> 

struct node 

{ 

    int data; 

    struct node *next; 

}; 

 

typedef struct list 

{ 

    struct node *front, *rear; 

    int size; 

} queue; 

 

 

int Hot_potato(int , int ); 

queue init(queue q); 

queue enqueue(queue q, int data); 

int dequeue(queue *q); 

void flush(queue *q); 

 

int main() 

{ 

    int n, k, winner; 

 

start_num: 

    printf("The number of children are:\n"); 

    scanf("%d", &n); 

    if (n <= 0) 

    { 

        printf("\nERROR : Number of children should be greater than 0\n\n"); 

        goto start_num; 

    } 

 

start_elim: 

    printf("The number of children to be skipped: "); 

    scanf("%d", &k); 

    if (k < 1) 

    { 

        printf("\nERROR : The elimination number should be greater than 0\n\n"); 

        goto start_elim; 

    } 

 

    winner = Hot_potato(n, k); 

 

    printf("\nThe person to win is : %d\n", winner); 

    return 0; 

} 

 

queue init(queue q) 

{ 

    q.size = 0; 

    q.front = q.rear = NULL; 

    return q; 

} 

 

queue enqueue(queue q, int data) 

{ 

    struct node *temp = NULL; 

    if ((q).front == NULL && (q).rear == NULL) 

    { 

        temp = (struct node *)malloc(sizeof(struct node)); 

 

        temp->next = NULL; 

        temp->data = data; 

 

        (q).front = (q).rear = temp; 

        (q).size = 1; 

    } 

    else 

    { 

        temp = (struct node *)malloc(sizeof(struct node)); 

 

        (q).rear->next = temp; 

        temp->data = data; 

        temp->next = NULL; 

 

        (q).rear = temp; 

        (q).size++; 

    } 

    return q; 

} 

 

int dequeue(queue *q) 

{ 

    if ((*q).rear == NULL && (*q).front == NULL) 

        return INT_MIN; 

 

    struct node *temp = NULL; 

    temp = (*q).front; 

    int data; 

 

    data = temp->data; 

 

    if (temp->next != NULL) 

    { 

        temp = temp->next; 

        free((*q).front); 

        (*q).front = temp; 

    } 

    else 

    { 

        free((*q).front); 

        (*q).front = (*q).rear = NULL; 

    } 

    (*q).size--; 

    return data; 

} 

 

void flush(queue *q) 

{ 

    struct node *temp = NULL; 

    temp = (*q).front; 

 

    while (temp != (*q).rear) 

    { 

        temp = (*q).front->next; 

        free((*q).front); 

        (*q).front = temp; 

    } 

 

    free(temp); 

    (*q).front = (*q).rear = NULL; 

} 

int Hot_potato(int num, int elim) 

{ 

    int winner = 0, temp; 

    queue circle; 

    circle = init(circle); 

 

    int i, j; 

    for (i = 1; i <= num; i++) 

        circle = enqueue(circle, i); 

 

    while (circle.size > 1) 

    { 

        for (j = 1; j <= elim; j++) 

        { 

            temp = dequeue(&circle); 

            circle = enqueue(circle, temp); 

        } 

        temp = dequeue(&circle); 

        printf("%d has been removed.\n", temp); 

        

    } 

 

    winner = circle.front->data; 

 

    flush(&circle); 

    return winner; 

} 
