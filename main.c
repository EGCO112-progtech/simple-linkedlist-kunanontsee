//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int t=5;
    struct node a,b,*head ;
    a.value = t;
    a.next=&b;
    head=&a;
    b.value=head->value+3;

    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
    4. print using head
 */
    struct node c;
    b.next = &c;
    c.value = 11;
    c.next = NULL;
    printf("Value c is %d\n", head->next->next->value);
    
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
*/
    struct node d;
    head = &d;
    d.value = 2;
    d.next = &a;
    printf("Value d is %d\n", head->value);
    printf("Value a is %d\n", head->next->value);
    printf("Value b is %d\n", head->next->next->value);
    printf("Value c is %d\n", head->next->next->next->value);
    
    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate
    
    /*  Exercise III Use loop to print everything
        int i,n=5;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
          // What is missing???
        }
    */
    int i,n=5;
    printf("Use For loop");
    for(i=0;i<n-1;i++)
    {
        printf("%3d", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
    
   /*  Exercise IV change to while loop!! (you can use NULL to help)
       
         while(){
            printf("%3d", tmp->value);
           // What is missing???
        }
    */

    tmp = head;
    printf("Use While loop : ");
    while(tmp != NULL)
    {
        printf("%3d", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
    
 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
          
     */
    
    struct node *head1, *temp1;

    head1 = (struct node*)malloc(sizeof(struct node));
    temp1 = head1;

    for(int i=2; i<=11; i+=3)
    {
        temp1->value = i;
        if(i==11) temp1->next = NULL;
        else
        {
            temp1->next = (struct node*)malloc(sizeof(struct node));
        }
        temp1 = temp1->next;
    }
    


    /*  Exercise VI Free all node !!
         //use a loop to help
          
     */
    temp1 = head1;
    printf("Allocate and Free : ");
    while(head1 != NULL)
    {
        head1 = head1->next;
        printf("%3d", temp1->value);
        free(temp1);
        temp1 = head1;
    }
    
    return 0;
}
