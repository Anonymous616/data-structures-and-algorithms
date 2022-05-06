def minmax(data, low, high):
    if low == high:
        return {"min" : low, "max" : low}

    mid = (low + high) // 2
    m1 = minmax(data, low, mid)
    m2 = minmax(data, mid + 1, high)

    return {"min" : m1["min"] if data[m1["min"]] < data[m2["min"]] else m2["min"],
            "max" : m1["max"] if data[m1["max"]] > data[m2["max"]] else m2["max"]}

if __name__ == "__main__":
    data = [102, 21, 4, 31, 12, 32]
    print(minmax(data, 0, len(data) - 1))
