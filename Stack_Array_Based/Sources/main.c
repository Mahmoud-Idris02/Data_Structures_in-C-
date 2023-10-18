#include <stdio.h>
#include "..\Headers\stack.h"

stack_t myStack ;

uint32_t value;
uint32_t size ;
uint32_t myStackTop;


int main(void){
    return_status ret = Stack_init(&myStack);
    if (R_NOK == ret){
        printf("stack is not intialized successfully\n");
    }
    else{

        Stack_push(&myStack,5);
        Stack_push(&myStack,2);
        Stack_push(&myStack,3);
        Stack_push(&myStack,8);

        Stack_size(&myStack,&size);
        printf("\nStack size = %i\n", size);
        
        Stack_top(&myStack,&myStackTop);
        printf("Stack top = %i\n",myStackTop);

        printf("----------------------------------------------\nTrying stack display function\n");
        ret = Stack_display(&myStack);
        if (R_NOK ==  ret){
            printf("display is not working \n");
        }
        printf("----------------------------------------------\n\n");


        for ( uint8_t i = 5; i > 0 ; i--)
        {
           ret = Stack_pop(&myStack,&value);
           if (R_NOK ==  ret){
            printf("stack is empty \"nothing to be popped\" \n");
            break;
           }
           
           printf("Stack element %i is popped = %i\n",i-1,value);
        }
        
        
    }
    
    return 0;   
}