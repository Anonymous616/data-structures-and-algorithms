weights = [3, 4, 5, 6]
weights = [2, 4, 6]
res = [0]*len(weights)
target = 13
target = 6

def printRes(res):
    print(", ".join([str(weights[i]) for i in range(len(res)) if res[i] == 1]))

def promising(l, curr, rem):
    if curr + weights[l] <= target and curr + rem >= target:
        return True
    return False

def sum_subset(l, curr, rem):
    if curr == target:
        printRes(res)
        return

    elif l >= len(weights):
        return

    elif (promising(l, curr, rem)):
        res[l] = 1
        sum_subset(l+1, curr + weights[l], rem - weights[l])
        res[l] = 0
        sum_subset(l+1, curr, rem - weights[l])


if __name__ == "__main__":
    print("== Weights selected ==")
    sum_subset(0, 0, sum(weights))
