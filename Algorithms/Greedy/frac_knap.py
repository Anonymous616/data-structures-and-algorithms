class KnapItems():
    def __init__(self, item, profit, weight):
        self.item = item
        self.profit = profit
        self.weight = weight
        self.ratio = profit / weight

    def __str__(self):
        return f"Item: {self.item}\tProfit: {self.profit}\tWeight: {self.weight}\tRatio: {self.ratio}"

def frac_knap(items, profits, weights, maxW):
    data = [KnapItems(item, profit, weight)
            for item, profit, weight in
            zip(items, profits, weights)]

    data = sorted(data, key=lambda x: x.ratio, reverse=True)

    W = 0
    sack = []

    for i in data:
        if W + i.weight > maxW:
            break
        else:
            W += i.weight
            sack.append(i.item)

    print(sack)
    for i in data:
        print(str(i))

if __name__ == "__main__":
    items = ["A", "B", "C", "D", "E", "F", "G"]
    profits = [5, 10, 15, 7, 8, 9, 4]
    weights = [1, 3, 5, 4, 1, 3, 2]
    maxW = 15

    frac_knap(items, profits, weights, maxW)
