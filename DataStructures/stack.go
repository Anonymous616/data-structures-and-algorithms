package main

import (
	"fmt"
	"log"
)

type Stack struct {
	items []string
	top   int `default:"-1"`
	MAX   int
}

func CreateStack(size int) *Stack {
	return &Stack{
		items: make([]string, size+1),
		MAX:   size,
	}
}

func (s *Stack) IsOverflow() bool {
	if s.top < s.MAX {
		return false
	}

	log.Println("Stack overflow")
	return true
}

func (s *Stack) IsUnderflow() bool {
	if s.top > -1 {
		return false
	}

	log.Println("Stack underflow")
	return true
}

func (s *Stack) Push(val string) bool {
	if s.IsOverflow() {
		return false
	}

	s.top++
	s.items[s.top] = val

	return true
}

func (s *Stack) Pop() string {
	if s.IsUnderflow() {
		return ""
	}

	s.top--
	return s.items[s.top+1]
}

func (s *Stack) Print() {
	fmt.Print("Stack => ")
	for i := 0; i <= s.top; i++ {
		fmt.Printf("%s ", s.items[i])
	}
	fmt.Println()
}

func (s *Stack) Top() string {
	if s.IsUnderflow() {
		return ""
	}

	return s.items[s.top]
}

func main() {
	s := CreateStack(5)

	s.Push("10")
	s.Push("20")
	s.Push("30")
	s.Push("40")
	s.Push("50")

	fmt.Printf("Top => %s\n", s.Top())

	s.Print()

	fmt.Printf("Popped => %s\n", s.Pop())
	fmt.Printf("Top => %s\n", s.Top())

	fmt.Printf("Popped => %s\n", s.Pop())

	s.Print()
}
