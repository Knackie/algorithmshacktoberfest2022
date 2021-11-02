#include <iostream>
using namespace std;

// Defining the maximum size of the stack to be 10
#define MAX 10

float evaluatePostfix();

// Defining a class to store the member variables
// and member functions required
class Stack {
  float stk[MAX];

public:
  int top;
  Stack(): top(-1) {}
  void push(float );
  float pop();
  void display();
};


/*
ALGORITHM FOR PUSHING AN ELEMENT IN THE STACK:
  1) IF TOP = MAX-1
        WRITE Overflow
        EXIT
  2) TOP = TOP + 1
  3) STACK[TOP] = VALUE
  4) EXIT
*/

void Stack :: push(float value) {
  // When the size of stack has reached maximum,
  // we cannot insert any element
  if(top == MAX-1) {
    cout<<"The Stack is full !\n";
  }
  else {
    // Incrementing top
    top++;

    // Store the value in the stack at top position
    stk[top] = value;
  }
}


/*
ALGORITHM FOR POPPING AN ELEMENT FROM THE STACK:
  1) IF TOP = -1
        WRITE Underflow
        RETURN -1
        EXIT
  2) VALUE = STK[TOP]
  3) TOP = TOP - 1
  4) RETURN VALUE
  5) EXIT
*/

float Stack :: pop() {
  // When the size of stack is -1, the stack is empty
  if(top == -1) {
    return -1;
  }
  else {
    // Store the top value
    float value = stk[top];

    // Decrement top
    top --;

    return value;
  }
}


float evaluatePostfix() {
  Stack s;
  string exp;
  int i=0;
  float op1, op2, value;

  cout<<"Enter the experssion: ";
  getline(cin, exp);

  while(exp[i] != '\0') {
    if(isdigit(exp[i])) {
      s.push((float)exp[i]-'0');
      i++;
    }
    else {
      op2 = s.pop();
      op1 = s.pop();

      switch(exp[i]) {
        case '+': value = op1 + op2;
                  break;

        case '-': value = op1 - op2;
                  break;

        case '*': value = op1 * op2;
                  break;

        case '/': value = op1 / op2;
                  break;

        case '%': value = (int)op1 % (int)op2;
                  break;
      }
      s.push(value);
    }
    i++;
  }
  return s.pop();
}

int main() {
  int option;
  float result;

  result = evaluatePostfix();
  cout<<"The result is "<<result<<endl;
}
