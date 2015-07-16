#include <pebble.h>
Window *my_window;
TextLayer *text_layer;
static void main_window_load(Window *window){
int some_integer = 0;  
static char output_string[200] = "";
  // basic definition list from: http://www.tutorialspoint.com/cprogramming/c_operators.htm
//try to monkey with the code below and see if you can guess what effect it will have when you hit "run"
  
// Arithmetic operators:  
// + 	Adds two operands 	A + B will give 30
// - 	Subtracts second operand from the first 	A - B will give -10
// * 	Multiplies both operands 	A * B will give 200
// / 	Divides numerator by de-numerator 	B / A will give 2
// % 	Modulus Operator and remainder of after an integer division 	B % A will give 0
// ++ 	Increments operator increases integer value by one 	A++ will give 11
// -- 	Decrements operator decreases integer value by one 	A-- will give 9

some_integer = 1+2;
  
// Relational Operators:
// == 	Checks if the values of two operands are equal or not, if yes then condition becomes true. 	(A == B) is not true.
// != 	Checks if the values of two operands are equal or not, if values are not equal then condition becomes true. 	(A != B) is true.
// > 	Checks if the value of left operand is greater than the value of right operand, if yes then condition becomes true. 	(A > B) is not true.
// < 	Checks if the value of left operand is less than the value of right operand, if yes then condition becomes true. 	(A < B) is true.
// >= 	Checks if the value of left operand is greater than or equal to the value of right operand, if yes then condition becomes true. 	(A >= B) is not true.
// <= 	Checks if the value of left operand is less than or equal to the value of right operand, if yes then condition becomes true. 	(A <= B) is true. 
  
if(some_integer >= 3){
  some_integer++;
}
  
  
// Logical Operators:
//   && 	Called Logical AND operator. If both the operands are non-zero, then condition becomes true. 	(A && B) is false.
// || 	Called Logical OR Operator. If any of the two operands is non-zero, then condition becomes true 	(A || B) is true.
// ! 	Called Logical NOT Operator. Reverses result.  If a condition is true then Logical NOT operator will make false.	!(A && B) is true

  if(some_integer > 1 && some_integer <= 4){
  some_integer = some_integer/2;
  }
  else{
    some_integer--;
  }
  
  

// Assignment Operators:  
// = 	Simple assignment operator, Assigns values from right side operands to left side operand 	C = A + B will assign value of A + B into C
// += 	Add AND assignment operator, It adds right operand to the left operand and assign the result to left operand 	C += A is equivalent to C = C + A
// -= 	Subtract AND assignment operator, It subtracts right operand from the left operand and assign the result to left operand 	C -= A is equivalent to C = C - A
// *= 	Multiply AND assignment operator, It multiplies right operand with the left operand and assign the result to left operand 	C *= A is equivalent to C = C * A
// /= 	Divide AND assignment operator, It divides left operand with the right operand and assign the result to left operand 	C /= A is equivalent to C = C / A

  some_integer += some_integer;
  

  
  
  
 //----------------------------------------------------------------------------------------------------------------------------------------------------------- 
  
  snprintf(output_string, sizeof(output_string), "The result is: %d", some_integer);
  
  Layer *window_layer = window_get_root_layer(window);
  text_layer = text_layer_create(GRect(0, 0, 144, 60));
  
  
  text_layer_set_text(text_layer, output_string );
  text_layer_set_text_color(text_layer, GColorBlack);
  
  layer_add_child(window_layer, text_layer_get_layer(text_layer));
  
  

}

static void main_window_unload(){
   text_layer_destroy(text_layer);
}

void handle_init(void) {
  my_window = window_create();
 
  
  window_set_window_handlers(my_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload,
  });
  
  window_stack_push(my_window, true);
}

void handle_deinit(void) {
 window_destroy(my_window);
}


int main(void) {
  handle_init();
  app_event_loop();
  handle_deinit();
}