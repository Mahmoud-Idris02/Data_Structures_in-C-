#ifndef STACK_H
#define STACK_H

#include<stdio.h>
#include "platform.h"

typedef struct {
    void ** Array ;
    sint32_t ElementCount;
    uint32_t MaxSize;
    sint32_t top;
}stack_t;

typedef enum {
    full,
    empty,
    not_full
}Stack_State;

/**
 * @brief 
 * 
 * @param size 
 * @param ret 
 * @return stack_t* 
 */
stack_t * Stack_create(uint32_t size,return_status * ret);
/**
 * @brief 
 * 
 * @param stack 
 * @param ret 
 * @return stack_t* 
 */
stack_t * Stack_Destroy(stack_t * stack,return_status * ret);
/**
 * @brief 
 * 
 * @param stack 
 * @param valuePtr 
 * @return return_status 
 */
return_status Stack_push(stack_t * stack,void * valuePtr);
/**
 * @brief 
 * 
 * @param stack 
 * @param ret 
 * @return void* 
 */
void * Stack_pop(stack_t * stack,return_status * ret);
/**
 * @brief 
 * 
 * @param size 
 * @param ret 
 * @return void* 
 */
void * Stack_top(uint32_t size,return_status * ret);
/**
 * @brief 
 * 
 * @param stack 
 * @return Stack_State 
 */
static Stack_State Stack_full(stack_t* stack);
/**
 * @brief 
 * 
 * @param stack 
 * @return Stack_State 
 */
static Stack_State Stack_empty(stack_t* stack);
#endif