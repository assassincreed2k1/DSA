package Week_8_BinarySearchTree.Bai_5_Check_BST;

import java.util.Scanner;

class Node {
    int data;
    Node left, right;

    public Node(int data) {
        this.data = data;
        left = right = null;
    }
}

class BinaryTree {
    private Node root;

    public BinaryTree() {
        root = null;
    }

    public void insert(int data) {
        root = insert(root, data);
    }

    public void inOrder() {
        inOrderTraversal(root);
    }

    public void display() {
        displayBinaryTree(root, 0);
    }

    public int height() {
        return treeHeight(root);
    }

    static public boolean checkBST(Node root) {
        return checkBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    private Node insert(Node node, int data) {
        if (node == null) {
            return new Node(data);
        }
        if (data < node.data) {
            node.left = insert(node.left, data);
        } else {
            node.right = insert(node.right, data);
        }
        return node;
    }

    private void inOrderTraversal(Node node) {
        if (node != null) {
            inOrderTraversal(node.left);
            System.out.print(node.data + " ");
            inOrderTraversal(node.right);
        }
    }

    private void displayBinaryTree(Node node, int space) {
        if (node == null) {
            return;
        }

        space += 10;

        displayBinaryTree(node.right, space);

        System.out.println();
        for (int i = 10; i < space; i++) {
            System.out.print(" ");
        }
        System.out.println(node.data);

        displayBinaryTree(node.left, space);
    }

    private int treeHeight(Node node) {
        if (node == null) {
            return -1;
        }

        int leftHeight = treeHeight(node.left);
        int rightHeight = treeHeight(node.right);

        return 1 + Math.max(leftHeight, rightHeight);
    }

    static private boolean checkBST(Node node, int min, int max) {
        if (node == null)
            return true;

        if (node.data <= min || node.data >= max)
            return false;

        return checkBST(node.left, min, node.data) &&
                checkBST(node.right, node.data, max);
    }
}

public class Main {
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        Scanner scanner = new Scanner(System.in);

        int size = scanner.nextInt();

        for (int i = 0; i < size; i++) {
            int data = scanner.nextInt();
            tree.insert(data);
        }
        System.out.println(tree.height());
        tree.inOrder();
        System.out.println();

        Node tree_2 = new Node(10);

        if (BinaryTree.checkBST(tree_2)) {
            System.out.println("YES, This is BST!");
        };

        // System.out.println("Binary Tree:");
        // tree.display();

        scanner.close();
    }
}
