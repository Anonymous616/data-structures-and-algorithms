// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) < 1 {
		return nil
	}

	var root TreeNode

	root.Val = preorder[0]

	rootIdx := slices.Index(inorder, preorder[0])

	root.Left = buildTree(preorder[1:rootIdx+1], inorder[:rootIdx])
	root.Right = buildTree(preorder[rootIdx+1:], inorder[rootIdx+1:])

	return &root
}
