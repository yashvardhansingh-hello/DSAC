#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int size;
    char* arr;
};

int isEmpty(struct stack* ptr){
    if (ptr->top == -1) return 1;
    else return 0;
}

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size-1) return 1;
    else return 0;
}

int pop(struct stack* ptr){
    if(isEmpty(ptr)) {printf("Stack Underflow");return -1;}
    else{
        char val = ptr->arr[ptr->top];
        (ptr->top)--;
        return val;
    }
}

void push(struct stack* ptr, char value){
    if(isFull(ptr)){printf("Stack Overflow");}
    else{
        (ptr->top)++;
        ptr->arr[ptr->top] = value;
    }
}


char stackTop(struct stack* ptr){
   return ptr->arr[ptr->top]; 
}

int main(){
    char str[10] = "3+4{(8*7})";
    char *ptr = str;
    struct stack* s;
    s->size = 20;
    s->top = -1;
    s->arr = (char*)malloc(sizeof(char)*s->size);
     
    while (*ptr != '\0')
    {
        // printf("%c\n", *ptr);
        if(*ptr == '(' || *ptr == '{' || *ptr == '['){
            push(s, *ptr);
        }
        else if(*ptr == ')' || *ptr == '}' || *ptr == ']') {
            if(isEmpty(s)) {printf("Unbalanced");exit(1);}
            switch (*ptr)
            {
            case ')':
                if(stackTop(s) != '(') {printf("Unbalanced");exit(1);}
                else pop(s);
                break;
            
            case '}':
                if(stackTop(s) != '{') {printf("Unbalanced");exit(1);}
                else pop(s);
                break;
            
            case ']':
                if(stackTop(s) != '[') {printf("Unbalanced");exit(1);}
                else pop(s);
                break;
            }
        }
        ptr = ptr+sizeof(char);
    }
    if(isEmpty(s)) {printf("Balanced");exit(0);}
    else {printf("Unbalanced");exit(1);}
    
}