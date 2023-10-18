#include <stdio.h>
#include "..\Headers\stack.h"


/**
 * @brief to intialize stack with zero top
 * @param stack 
 * @return return_status ---> R_OK || R_NOK
 */
return_status Stack_init(stack_t * stack){
    if (NULL == stack){
        return R_NOK ;
    }
    else{
        stack->top  = -1 ; 
    }
    return R_OK ;
}

/**
 * @brief checks if the stack is full or not 
 * @param stack 
 * @return stack_status 
 */
static stack_status Stack_full(stack_t * stack){
    if (Maxelements == (stack->top-1) ){
       return full;
    }
    else{
        return not_full;
    }    
}

/**
 * @brief checks if the stack is empty or not 
 * @param stack 
 * @return stack_status 
 */
static stack_status Stack_empty(stack_t * stack){
    if (-1 ==  (stack->top)){
        return empty;
    }
    else{
        return not_full;
    }
}

/**
 * @brief  to  help pushing a certain value to the stack if its not full
 * @param stack passed by referrence 
 * @param value 
 * @return return_status 
 */
return_status Stack_push(stack_t *stack, uint32_t value){

    if (full == Stack_full(stack) || (NULL == stack)){
        return R_NOK;
    }else{
        stack->top++;
        stack->data[stack->top] = value;
        return R_OK;
    }
}

/**
 * @brief to help poping the top value of the stack if it's not empty 
 * @param stack passed by referrence 
 * @param value returning the value by pointer 
 * @return return_status 
 */
return_status Stack_pop(stack_t *stack, uint32_t *value)
{
    if (NULL == stack || NULL == value || empty == Stack_empty(stack) ){
        return R_NOK;
    } else{
        *value = stack->data[stack->top];
        stack->top--;
        return R_OK; 
    }
}

/**
 * @brief to help looking at the top of the stack 
 * @param stack passed by referrence 
 * @param value returning the value by pointer 
 * @return return_status 
 */
return_status Stack_top(stack_t *stack, uint32_t *value)
{
    if (NULL == stack || NULL ==  value ){
        return R_NOK;
    }else{
        *value = stack->data[stack->top];
        return R_OK;
    }
    
}

/**
 * @brief to know the size of the stack 
 * @param stack passed by referrence 
 * @param value returning the value by pointer 
 * @return return_status 
 */
return_status Stack_size(stack_t *stack, uint32_t *size)
{
    if (NULL == stack || NULL ==  size ){
        return R_NOK;
    }else{
        *size = stack->top + 1;
        return R_OK;
    }
}

/**
 * @brief To display stack elements without poping any of them
 * @param stack 
 * @return return_status  
 */
return_status Stack_display(stack_t *stack){
    if (NULL == stack || empty == Stack_empty(stack)){
        return R_NOK;
    }else{
        for (uint8_t i = stack->top; i >= 0; i--){
            printf("Stack element %i = %i\n",i+1,stack->data[i]);
        }   
        return R_OK;
    }
}
