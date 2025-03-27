#include <iostream>
#include <stack>

#include "stackReverse.h"

using std::cout;
using std::endl;
using std::stack;

int main() {
    // Test 1
    stack<int> stack_1;
    stack_1.push(1);
    stack_1.push(2);
    stack_1.push(3);

    stackReverse(stack_1);

    cout << stack_1.top() << ", ";
    stack_1.pop();
    cout << stack_1.top() << ", ";
    stack_1.pop();
    cout << stack_1.top() << endl;

    return 0;
}
