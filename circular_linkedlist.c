//circular linked list 

#include <stdio.h> 

#include <stdlib.h> 

struct node 

{ 

    int num; 

    struct node *next; 

}; 

 

struct node *head = NULL; 

 

void create(int); 

int survivor(int); 

 

int main() 

{ 

 

    int winner, k, n; 

start_num: 

    printf("The number of children are:\n"); 

    scanf("%d", &n); 

    if (n <= 0) 

    { 

        printf("\nERROR : Number of children should be greater than 0\n\n"); 

        goto start_num; 

    } 

    create(n); 

 

start_elim: 

    printf("The number of children to be skipped: "); 

    scanf("%d", &k); 

    if (k < 1) 

    { 

        printf("\nERROR : The elimination number should be greater than 0\n\n"); 

        goto start_elim; 

    } 

 

    winner = survivor(k); 

    printf("The person to win is : %d\n", winner); 

    free(head); 

 

    return 0; 

} 

 

int survivor(int k) 

{ 

    struct node *p, *q; 

    int i; 

 

    q = p = head; 

    while (p->next != p) 

    { 

        for (i = 1; i <= k; i++) 

        { 

            q = p; 

            p = p->next; 

        } 

        q->next = p->next; 

        printf("%d has been removed.\n", p->num); 

        free(p); 

        p = q->next; 

    } 

    head = p; 

 

    return (p->num); 

} 

 

void create(int n) 

{ 

    struct node *newnode, *temp; 

    int i; 

 

    for (i = 1; i <= n; i++) 

    { 

 

        newnode = (struct node *)malloc(sizeof(struct node)); 

        newnode->num = i; 

        newnode->next = NULL; 

        if (head == NULL) 

        { 

            head = newnode; 

        } 

        else 

        { 

            temp->next = newnode; 

        } 

        temp = newnode; 

    } 

    temp->next = head; 

} 
