//INSTRUCTION
//Look for ** to complete this program
//The output should match my hw1stackDemo.out

//=========================================================
//HW#: HW1P1 stack
//Your name: Harjinder Gill
//Complier:  g++ and CodeBlock
//File type: client1 program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "stack.h"
//#include "queue.h"

//Purpose of the program: **
//Algorithm: **
int main(){
   stack postfixstack;  // integer stack
   string expression;   // user entered expression


   cout << "type a postfix expression: " ;
   cin >> expression;


   int i = 0;  // character position within expression
   char item;  // one char out of the expression
   int result = 0;

   int box1;  // receive things from pop
   int box2;  // receive things from pop

   int Operator = 0;
   int Oprand = 1;

   while (expression[i] != '\0'){
       try{
           item = expression[i];  // current char

           //2.  if it is an operand (number),
           //    push it (you might get Overflow exception)
           // **
           if((item == '0')||(item == '1')||(item == '2')||(item == '3')||(item == '4')||
              (item == '5')||(item == '6')||(item == '7')||(item == '8')||(item == '9')){

               box1 = item - 48;
               postfixstack.push(box1);
               Operator++;
           }

           //3.  else if it is an operator,
           //    pop the two operands (you might get Underflow exception), and
           //	apply the operator to the two operands, and
           //    push the result.
           else if ( (item == '+') || (item == '-') || (item == '*')){
               postfixstack.pop(box1);
               postfixstack.pop(box2);
               //cases for different operators follow:
               if ((item == '+') || (item == '-') || (item == '*')) {
                   if(item == '+'){
                       result = box2 + box1;
                       Oprand++;
                   }else if(item == '-'){
                       result = box2 - box1;
                       Oprand++;
                   }else if (item == '*'){
                       result = box2 * box1;
                       Oprand++;
                   }
                   postfixstack.push(result);
               }
     // ** also do the + and * cases
     // ** Finally push the result
           }else
               throw item;
       }





       // Catch exceptions and report problems and quit the program now.
       // Error messages describe what is wrong with the expression.
       catch (stack::Overflow){
           cout << "expression too long" << endl;
           postfixstack.clearIt();
       }
       catch (stack::Underflow){    // for too few operands
           cout << "too few operands" << endl;
           return 0;
       }
       catch (char errorcode){ // for invalid item

           cout <<"ERROR '" << errorcode << "' is invalid item!!!!!" << endl;
           return 0;
       }


       // go back to the loop after incrementing i
       //
       i++;
   }// end of while

       try{
           if(Operator != Oprand){
               throw "incomplete expression";
           }
       }
       catch (...){
           cout <<"incomplete expression" << endl;
           return 0;
       }

// After the loop successfully completes:
// The result will be at the top of the stack. Pop it and show it.
//**
// If anything is left on the stack, an incomplete expression was found.
// Inform the user.

// **
   postfixstack.topElem(result);
   cout << "The result is: " << result << endl;

   if(postfixstack.isEmpty()){
       cout << "There is still some elements in the stack" << endl;
   }

   return 0;
}// end of the program



