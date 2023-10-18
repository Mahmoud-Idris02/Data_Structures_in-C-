#ifndef STACK_H
#define STACK_H

#include"platform.h"
#define Maxelements 5


typedef struct {
    uint32_t data [Maxelements];
    sint32_t top; 
}stack_t; 
  
typedef enum{
    empty,
    full,
    not_full
}stack_status;


return_status Stack_init(stack_t * stack);
static stack_status Stack_full(stack_t * stack);
static stack_status Stack_empty(stack_t * stack);

return_status Stack_push(stack_t * stack, uint32_t value);
return_status Stack_pop(stack_t * stack, uint32_t* value);
return_status Stack_top(stack_t * stack, uint32_t* value);
return_status Stack_size(stack_t * stack, uint32_t* size);
return_status Stack_display(stack_t *stack);



#endif 