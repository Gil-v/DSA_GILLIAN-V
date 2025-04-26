#include <iostream>
using namespace std;

char stack[20];
int top = -1;

string stackOutput = "";

void push(char val){
    stack[++top] = val;
    stackOutput += val;
}

char pop(){
    stackOutput.erase(top, 1);
    char val = stack[top--];
    return val;
}

char peek(){
    return stack[top];
}

int checkLevel(char operation){
    int level;
   
    if(operation == '(' || operation == ')'){
        level = 0;
    }else if(operation == '^'){
        level = 1;
    }else if(operation == '/' || operation == '*'){
        level = 2;
    }else if(operation == '+' || operation == '-'){
        level = 3;
    }else{
        level = 0;
    }
   
    return level;
}

void convertToPostfix(string input){
    string output ="";
   
    cout << "| Input | Stack | Output |" << endl;
    cout << "|------------------------|" << endl;
   
    for (int i=0; i <input.length(); i++){
       
           if(isdigit(input[i])){
    output += input[i];
}else{
       
        if(top == -1){
            push(input[i]);
        }
        else{
           
            if(input[i] == '(' || peek() == '('){
                push(input[i]);
            }else{
                if(input[i] == ')'){
                    while(top >= 0 && peek() != '('){
                        output += pop();
                    }
                    if(top >= 0 && peek() == '('){
                        pop();
                    }else{
                        while(checkLevel(peek()) <= checkLevel(input[i])){
                        output += pop();
                    }    
                    push(input[i]);
                }
            }
        }    
    }      
}      
       
   
   
        cout << "|  "  << input[i] <<  "  | " << stackOutput <<"  |  " << output << " |" << endl;
        cout << "|------------------------| " << endl;

   
}
while(top >= 0 ){
        output += pop();
    }
    cout << "The equivalent postfix is: " << output <<endl;
}  

       



int main()
{
 
    string input = "(1+2)*3";
    convertToPostfix(input);
    string input_1 = "(2+3)-5*4/5";
    convertToPostfix(input_1);
    string input_2 = "(5+5)*(8-2)";
    convertToPostfix(input_2);
    string input_3 = "5+5+3*4-7";
    convertToPostfix(input_3);
    string input_4 = "(5+6)*2+1";
    convertToPostfix(input_4);
    string input_5 = "(5+6)*(2+1)";
    convertToPostfix(input_5);

    return 0;
}