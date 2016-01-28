/* File: char_stack.h       

  Header file for a very basic array-based implementation of a stack.

*/
class char_stack
{
  public:
    char_stack();
    void push( char item );
    char pop(); 
    char top();
    bool empty();
    int size();
  private:
    static const int capacity = 250000; // 250 characters per line * 1000 lines = 250,000 characters according to assignment outline
    char stack_array[capacity];
    int top_of_stack;
};
