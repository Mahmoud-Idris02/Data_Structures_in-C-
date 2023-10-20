#include<stdio.h>
#include"..\Headers\stack.h"

stack_t *mystack;
return_status ret;
void * valuptr ;

int main(void){
    mystack = Stack_create(5,&ret);
    mystack = Stack_Destroy(mystack,&ret);
    if (NULL == mystack){
        printf("stack has been destroyed successfully\n");
    }
    return 0; 
}