package main

import (
	"fmt"
	"log"
)

type Queue struct {
	items []string
	front int `default:"-1"`
	back  int `default:"-1"`
	MAX   int
}

func CreateQueue(size int) *Queue {
	return &Queue{
		items: make([]string, size, size),
		front: -1,
		back:  -1,
		MAX:   size,
	}
}

func (q *Queue) IsOverflow() bool {
	if q.back < q.MAX-1 {
		return false
	}

	log.Println("Queue overflow")
	return true
}

func (q *Queue) IsUnderflow() bool {
	if q.front > -1 {
		return false
	}

	log.Println("Queue underflow")
	return true
}

func (q *Queue) Insert(val string) bool {
	if q.IsOverflow() {
		return false
	}

	if q.IsUnderflow() {
		q.front = 0
	}

	q.back++
	q.items[q.back] = val

	return true
}

func (q *Queue) Remove() string {
	if q.IsUnderflow() {
		return ""
	}

	q.front++
	return q.items[q.front-1]
}

func (q *Queue) Print() {
	fmt.Print("Queue => ")
	for i := 0; i <= q.back; i++ {
		fmt.Printf("%s ", q.items[i])
	}
	fmt.Println()
}

func (q *Queue) Front() string {
	if q.IsUnderflow() {
		return ""
	}

	return q.items[q.front]
}

func main() {
	q := CreateQueue(5)

	q.Insert("10")
	q.Insert("20")
	q.Insert("30")
	q.Insert("40")
	q.Insert("50")
	q.Insert("60")

	q.Print()
	fmt.Println(q.items[q.front])
	fmt.Printf("Top => %s\n", q.Front())

	q.Print()

	fmt.Printf("Removed => %s\n", q.Remove())
	fmt.Printf("Top => %s\n", q.Front())
	fmt.Printf("Removed => %s\n", q.Remove())

	q.Print()
}
