import random
import numpy as np

# Stack
class Stack:

    # Initializes size of stack and allocates memory
    def __init__(self, max=10) -> None:
        self.max = max
        self.top = -1
        self.stack = [None for x in range(max)]

    # Is stack full?
    def isOverflow(self) -> bool:
        if self.top >= self.max-1:
            print("Stack Overflow")
            return True
        return False

    # Is stack empty?
    def isUnderflow(self) -> bool:
        if self.top <= -1:
            print("Stack Underflow")
            return True
        return False

    # Pushes data on top of stack
    def push(self, data) -> None:
        if not self.isOverflow():
            self.top += 1
            self.stack[self.top] = data

    # Return data if stack is not empty
    def pop(self):
        if not self.isUnderflow():
            data = self.stack[self.top]
            self.stack[self.top] = None
            self.top -= 1
            return data
        return None

    # Returns top most element
    def displayTop(self):
        if not self.isUnderflow():
            return self.stack[self.top]
        return None

    # Returns stack elements
    def getStack(self) -> list:
        return [i for i in self.stack if i is not None]

    # Displays stack
    def display(self) -> None:
        if self.isUnderflow():
            print("Stack is Empty")
            return
        stack = self.getStack()[::-1]
        print(stack[0], "<- top")
        for data in stack[1:]:
            print(data)

# Main
if __name__ == "__main__":
    GREEN = '\033[92m'
    RESET = '\033[0m'
    print(f"{GREEN}Stack{RESET}")

    stack = Stack(5)

    print("Size of Stack is 5")
    
    # Generating Random Data
    data = [random.randint(0,100) for x in range(0,6)]

    # Displaying Random Data Generated
    print(f"Random Data Generated : {data}")

    # Pushing Data
    print("\nPushing Data ...")
    for i in data:
        stack.push(i)

    # Displaying Stack
    print("\nStack: ")
    stack.display()

    # Popping Data from Stack
    print("\nPopping data: ")
    for j in range(0,6):
        poppedData = stack.pop()

        if poppedData is None:
            break

        print(f"Data Popped : {poppedData}")