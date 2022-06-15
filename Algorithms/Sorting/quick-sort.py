def partition(data, low, high):
    pi = data[high]
    i = low - 1

    for j in range(low, high):
        if data[j] <= pi:
            i += 1
            data[i], data[j] = data[j], data[i]

    data[i+1], data[high] = data[high], data[i+1]
    return i+1

def quickSort(data, low, high):
    if low < high:
        pi = partition(data, low, high)
        quickSort(data, low, pi - 1)
        quickSort(data, pi + 1, high)

if __name__ == "__main__":
    data = [6, 2, 9, 10, 3, 4]
    quickSort(data, 0, len(data) - 1)
    print(data)
