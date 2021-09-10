import random

# Linear Search Algorithm
def bubble_sort(collection):

    for i in range(len(collection)):

        for j in range(len(collection)-i-1):
            
            # Check if value at j > j+1
            if collection[j] > collection[j+1]:
                # Swapping values at j and j+1
                temp = collection[j+1]
                collection[j+1] = collection[j]
                collection[j] = temp
        
    return collection


if __name__ == "__main__":
    GREEN = '\033[92m'
    RESET = '\033[0m'
    print(f"{GREEN}Bubble Sort{RESET}")
    
    # Create random collection of items
    data = [random.randint(1, 40) for i in range(10)]

    print (data)
  
    # Call bubble sort
    result = bubble_sort(data)

    # Print result
    print(result)