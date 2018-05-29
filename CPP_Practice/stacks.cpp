#include <iostream>
#include <stack>
# include <stdlib.h>

using namespace std;


/* Sort a stack using only a temporary Stack and no other data structures */
void sortStack(stack<int> & s)
{
            
   stack<int> tempStack;
   
   // move from stack to temp
   if (s.empty()) return;
   
   tempStack.push(s.top()); s.pop();
   
   while (!s.empty()){
       if (s.top() < tempStack.top()){
           tempStack.push(s.top()); s.pop();
       }
       else{
           /* INSERT candidate into tempStack */
           int popCount = 0;
           int candidate = s.top(); s.pop();
           // pop off smaller numbers
           while(!tempStack.empty() && (candidate > tempStack.top())){
               s.push(tempStack.top());tempStack.pop();
               popCount ++;
           }
           // push the candidate
           tempStack.push(candidate);
           // push back the smaller numbers
           for (int i = 0; i < popCount; i++){
               tempStack.push(s.top()); s.pop();
           }
       }
   }
   
   // tempStack is now reverse sorted
   // push it onto s as sorted
   while (!tempStack.empty()){
       s.push(tempStack.top()); tempStack.pop();
   }
   
}

void printIntStack(stack<int> s){
    int in;

    stack<int> tempStack;

    // pop and print
    while (!s.empty()){
      tempStack.push(s.top());
      cout <<  s.top() << " ";
      s.pop();
    }
    cout << "\n";
    // push back
    while(!tempStack.empty()){
      s.push(tempStack.top());
      tempStack.pop();
    }
}


void sortStackTest(){
  stack<int> s;
  // create stack
  for (int i = 0; i < 20; i++){
    s.push(rand() % 100);
  }
  printIntStack(s);
  sortStack(s);
  printIntStack(s);

}


int main(void){
  sortStackTest();

  return 0;
}


