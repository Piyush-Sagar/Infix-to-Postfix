    #include <stdio.h>
    #include <stdbool.h>
    #include<ctype.h>
    int top=-1;
    int user_input;
    int max=999;
    char stack[999];
    char peek();
    void push(char n);
    char pop();
    bool isFull();
    bool isEmpty();
    int precedence(char c);
    void infixToPostfix(char* infix, char*postfix);

    int main(){
        char infix[999],postfix[999];
        printf("Enter infix exp\n");
        scanf("%s",infix);
        infixToPostfix(infix,postfix);
        printf("Postfix Exp: %s\n",postfix);
        return 0;
    }

    int precedence(char c){
        if (c=='+' || c=='-'){return 1;}
        if(c=='*'||c=='/'){return 2;}
        if(c=='^'){return 3;}
    }

    void infixToPostfix(char* infix, char*postfix){
        int i=0,j=0;
        char ch;
        while((ch=infix[i++])!='\0'){
            if (isalnum(ch)){
                postfix[j++]=ch;
            }
            else if(ch=='('){
                push(ch);
            }
            else if(ch==')'){
                while (!isEmpty() && peek()!='('){
                    postfix[j++]=pop();
                }
                if (!isEmpty() && peek()=='('){
                    pop();
                }
            }
            else{
                while(!isEmpty() && precedence(ch)<=precedence(peek())){
                    postfix[j++]=pop();
                }
                push(ch);
            }
        }
        while(!isEmpty()){
            postfix[j++]=pop();
        }
        postfix[j]='\0';
    }

    char peek(){
        if (top>-1){return(stack[top]);}
        else{return '\0';}
    }
    void push(char n){
        if (top<max-1){
            stack[++top]=n;
        }
        else{
            printf("Stack Overflow\n");
        }
    }
    char pop(){
        if (top>-1){
            return(stack[top--]);
        }
        else{
            return '\0';
        }
    }
    bool isFull(){
        return top==max-1;
    }
    bool isEmpty(){
        return top==-1;
    }