#include "ArrayStack.h"
void main() {
	ArrayStack stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.display();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.push(4);
	stack.display();
}
