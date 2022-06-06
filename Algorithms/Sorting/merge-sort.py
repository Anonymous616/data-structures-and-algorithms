def merge(data, low, mid, high):
    i = low
    j = mid + 1
    temp = []

    while i <= mid and j <= high:
        if data[i] <= data[j]:
            temp.append(data[i])
            i += 1
        else:
            temp.append(data[j])
            j += 1

    while i <= mid:
        temp.append(data[i])
        i += 1

    while j <= high:
        temp.append(data[j])
        j += 1

    for i in range(low, high + 1):
        data[i] = temp[i-low]

def mergeSort(data, low, high):
    if low >= high:
        return
    mid = (low + high) // 2
    mergeSort(data, low, mid)
    mergeSort(data, mid + 1, high)
    merge(data, low, mid, high)

if __name__ == "__main__":
    data = [6, 2, 9, 10, 3, 4]
    mergeSort(data, 0, len(data) - 1)
    print(data)
