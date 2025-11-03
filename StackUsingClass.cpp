// create stack through class
#include<iostream> // include input-output stream library
using namespace std; // use standard namespace

// define a class named stackThroughClass
class stackThroughClass
{
    int *stack;     // pointer to dynamically allocate stack array
    int count, size1; // count tracks top index, size1 stores stack size

public:
    // constructor to initialize stack with given size
    stackThroughClass(int size)
    {
        size1 = size;               // assign input size to size1
        stack = new int[size];      // dynamically allocate memory for stack
        count = -1;                 // initialize count to -1 (empty stack)
    }

    // method to push value into stack
    void push(int value1)
    {
        if(count < size1 - 1)       // check if stack is not full
        {
            count++;                // increment count to next position
            stack[count] = value1;  // assign value to top of stack
        }
    }

    // method to pop value from stack
    void pop()
    {
        if(count >= 0)              // check if stack is not empty
        {
            cout << "value to pop is : " << stack[count]; // display top value
            count--;                // decrement count to remove top element
        }
    }
};

// main function
int main()
{
    int size; // variable to hold stack size
    cout << "Enter size of array:  "; // prompt user for stack size
    cin >> size; // read stack size from user

    stackThroughClass s(size); // create stack object with given size

    int val; // variable to hold value to push
    for (int i = 0; i < size; i++) // loop to push values into stack
    {
        cout << "Enter value at " << i+1 << " : "; // prompt for value
        cin >> val; // read value
        s.push(val); // push value into stack
    }

    cout << "want to delete item"; // message before popping
    s.pop(); // pop top value from stack

    return 0; // end of program
}
