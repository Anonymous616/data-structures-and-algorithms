package main

import (
	"fmt"
	"math/rand"
)

type TreeNode struct {
	Val   int
	left  *TreeNode
	right *TreeNode
}

func createNode(val int) *TreeNode {
	return &TreeNode{
		Val:   val,
		left:  nil,
		right: nil,
	}
}

func constructBinaryTree(vals []int) *TreeNode {
	var head *TreeNode

	for _, val := range vals {

		if head == nil {
			head = createNode(val)
			continue
		}

		var prev *TreeNode
		node := head

		for node != nil {
			prev = node

			if val <= node.Val {
				node = node.left
			} else {
				node = node.right
			}
		}

		if val <= prev.Val {
			prev.left = createNode(val)
		} else {
			prev.right = createNode(val)
		}
	}

	return head
}

func preorder(node *TreeNode) []int {
	res := make([]int, []int{node.Val})

	if node.left != nil {
		res = append(res, preorder(node.left)...)
	}

	if node.left != nil {
		res = append(res, preorder(node.right)...)
	}

	return res
}

func main() {
	arr := rand.Perm(10)
	fmt.Println(arr)
	tree := constructBinaryTree(arr)

	fmt.Println(preorder(tree))
}
