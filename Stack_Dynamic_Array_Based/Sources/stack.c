#include "..\Headers\stack.h"

static Stack_State Stack_full(stack_t* stack){
    if (NULL == stack ){
        return R_NOK;
    }else{
        
    }
}

static Stack_State Stack_empty(stack_t* stack){
    if (NULL == stack ){
        return R_NOK;
    }else{
        
    }
}

stack_t * Stack_create(uint32_t size,return_status * ret){
    stack_t * mystack = NULL;
    if (NULL == ret ){
        return R_NOK;
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
        
    }
}

void * Stack_pop(stack_t * stack,return_status * ret){
    if (NULL == ret ){
        return R_NOK;
    }else{
        
    }
}

void * Stack_top(uint32_t size,return_status * ret){
    if (NULL == ret ){
        return R_NOK;
    }else{
        
    }
}