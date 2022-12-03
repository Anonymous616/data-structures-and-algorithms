package main

import "fmt"

var graph map[string][]string

func depth_first_search(source string, visited map[string]bool) {
	fmt.Print(source, " ")
	visited[source] = true

	if _, found := graph[source]; !found {
		return
	}

	for _, w := range graph[source] {
		// fmt.Print(value, " ")
		if !visited[w] {
			depth_first_search(w, visited)
		}
	}
}

func breadth_first_search(source string) {
	queue := make([]string, 0)
	visited := make(map[string]bool)

	queue = append(queue, source)

	for len(queue) > 0 {
		// Get front of queue
		u := queue[0]

		// Print element
		fmt.Print(u, " ")

		// Remove front of queue
		queue = queue[1:]

		// Mark node as visited
		visited[u] = true

		// Check if node exists
		if _, found := graph[u]; !found {
			continue
		}

		for _, w := range graph[u] {
			if !visited[w] {
				queue = append(queue, w)
			}
		}
	}
}

func main() {
	graph = map[string][]string{
		"0": {"1", "2"},
		"1": {"3"},
		"3": {"4", "5"},
		"2": {"6", "7"},
		"6": {"8", "9"},
	}

	fmt.Print("Depth First Search : ")
	depth_first_search("0", map[string]bool{})
	fmt.Println()

	fmt.Print("Breadth First Search : ")
	breadth_first_search("0")
	fmt.Println()
}
