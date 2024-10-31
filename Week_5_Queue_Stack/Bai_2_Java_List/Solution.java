package Week_5_Queue_Stack.Bai_2_Java_List;

import java.util.*;

class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    Node headNode;

    public LinkedList() {
        this.headNode = null;
    }

    public void insertNodeAtTail(int data) {
        Node newNode = new Node(data);
        if (headNode == null) {
            headNode = newNode;
            return;
        }
        else {
            Node nextNode = headNode;
            while (nextNode.next != null) {
                nextNode = nextNode.next;
            }
            nextNode.next = newNode;
        }
    }

    public void insertNode(int data, int index) {
        Node insert = new Node(data);

        if (index == 0) {
            insert.next = headNode;
            headNode = insert;
            return;
        }

        Node nextNode = headNode;
        for (int i = 0; i < index - 1; i++) {
            if (nextNode == null) {
                return;
            }
            nextNode = nextNode.next;
        }
        insert.next = nextNode.next;
        nextNode.next = insert;
    }

    public void deleteNode(int index) {
        if (headNode == null) {
            return;
        }

        if (index == 0) {
            headNode = headNode.next;
            return;
        }

        Node current = headNode;
        for (int i = 0; i < index - 1; i++) {
            if (current == null || current.next == null) {
                return;
            }
            current = current.next;
        }
        
        current.next = current.next.next;
    }

    public void print() {
        if (headNode == null) {
            return;
        }
        Node nextNode = headNode;
        while (nextNode != null) {
            System.out.print(nextNode.data + " ");
            nextNode = nextNode.next;
        }
        System.out.println();
    }
}

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList llist = new LinkedList();
        int size = sc.nextInt();

        for (int i = 0; i < size; i++) {
            int data = sc.nextInt();
            llist.insertNodeAtTail(data);
        }

        int sizeQues = sc.nextInt();
        for (int i = 0; i < sizeQues; i++) {
            String str = sc.next();
            if (str.equals("Insert")) {
                int index = sc.nextInt();
                int data = sc.nextInt();
                llist.insertNode(data, index);
            }
            if (str.equals("Delete")) {
                int index = sc.nextInt();
                llist.deleteNode(index);
            }
        }
        llist.print();
        sc.close();
    }
}
