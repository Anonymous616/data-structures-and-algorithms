import os
import random

# Binary Search Algorithm
def binary_search(collection, target):

    beg = 0
    end = len(collection)-1
    mid = (beg + end) // 2

    # Iterate thorough all items in the collection
    while beg <= end:

        if collection[mid] == target:
            return mid

        elif collection[mid] > target:
            end = mid - 1

        elif collection[mid] < target:
            beg = mid + 1 

        mid = (beg + end) // 2
        
    # Target not found
    return None


if __name__ == "__main__":
    GREEN = '\033[92m'
    RESET = '\033[0m'
    print(f"{GREEN}Binary Search{RESET}")
    
    # Create random collection of items
    data = [random.randint(1, 40) for i in range(10)]

    # Sort the data
    data.sort()

    print(data)

    # Get the target
    target = int(input("Enter data to find : "))

    # Call binary search
    result = binary_search(data, target)

    # Check if data was found
    if result is None:
        print("Data not found")
    else:
        print(f"Found at index : {result}")