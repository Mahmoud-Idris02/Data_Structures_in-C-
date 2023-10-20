#include "..\Headers\stack.h"

static uint8_t Stack_full(stack_t* stack){
    if (NULL == stack ){
        return 0;
    }else if (stack->MaxSize == stack->ElementCount){
        return 1;
    }
    return 0 ;
}

static uint8_t Stack_empty(stack_t* stack){
    if (NULL == stack ){
        return 0;
    }else if (stack->ElementCount == 0){
        return 1 ;
    }
    return 0 ;
}

stack_t * Stack_create(uint32_t size,return_status * ret){
    stack_t * mystack = NULL;
    if (NULL == ret ){
        *ret = R_NOK;
    }else{
       mystack = (stack_t*)malloc(sizeof(stack_t));
       if (!mystack){
        *ret = R_NOK;
        mystack = NULL;
       }else{
        mystack->top = -1;
        mystack->MaxSize = size;
        mystack->ElementCount = 0;
        mystack->Array = (void**) calloc(mystack->MaxSize,sizeof(void*));
        if (NULL ==  mystack->Array){
            free(mystack);
            mystack = NULL;
            *ret = R_NOK;
        }
        *ret= R_OK;
       }
       
    }
    return mystack;
}

stack_t * Stack_Destroy(stack_t * stack,return_status * ret){
    if (NULL == ret ){
        *ret = R_NOK;
    }else{
        free(stack->Array);
    }
    free(stack);
    *ret = R_OK;
    return NULL;
}

return_status Stack_push(stack_t * stack,void * valuePtr){
    if (NULL == stack || NULL == valuePtr ){
        return R_NOK;
    }else{
        
        if (Stack_full(stack)){
            return full;
        }else{
            (stack->top)++;
             stack->Array[stack->top] = valuePtr;
            (stack->ElementCount)++;
        }
    }
    return R_OK;
}

void * Stack_pop(stack_t * stack,return_status * ret){
    void * l_dataPtr = NULL ;
    if (NULL == ret ){
        *ret =  R_NOK;
    }else{
        if (Stack_empty(stack)){
            return empty ;
        }else{
            l_dataPtr = stack->Array[stack->top];
            (stack->top)--;
            (stack->ElementCount)--;
            *ret = R_OK;
        }
    }
    return l_dataPtr;
}

void * Stack_top(stack_t *stack,return_status * ret){
    void * l_topPtr = NULL;
    if (NULL == ret ){
        *ret =  R_NOK;
    }else{
        l_topPtr = stack->Array[stack->top];
        *ret = R_OK;
    }
    return l_topPtr;
}