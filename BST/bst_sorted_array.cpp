/*


BinaryTreeNode<int> *constructHelper(int *input, int start_index,
                                     int end_index) {
  if (start_index > end_index) {
    return NULL;
  }
  int mid = (start_index + end_index) / 2;
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);

  root->left = constructHelper(input, start_index, mid - 1);
  root->right = constructHelper(input, mid + 1, end_index);
  return root;
}

BinaryTreeNode<int> *constructTree(int *input, int n) {
  return constructHelper(input, 0, n - 1);
} 

*/