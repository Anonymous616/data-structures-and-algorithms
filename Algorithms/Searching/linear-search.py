import random

# Linear Search Algorithm
def linear_search(collection, target):

    # Iterate thorough all items in the collection
    for i in range(len(collection)):

        # Check if the item has the same value as target
        if collection[i] == target:
            return i 

    # Target not found
    return None


if __name__ == "__main__":
    GREEN = '\033[92m'
    RESET = '\033[0m'
    print(f"{GREEN}Linear Search{RESET}")
    
    # Create random collection of items
    data = [random.randint(1, 40) for i in range(10)]

    print (data)

    # Get the target
    target = int(input("Enter data to find : "))

    # Call linear search
    result = linear_search(data, target)

    # Check if data was found
    if result is None:
        print("Data not found")
    else:
        print(f"Found at index : {result}")