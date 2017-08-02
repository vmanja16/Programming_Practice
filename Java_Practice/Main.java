package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here

        // Instantiate Array_Functions object
        Array_Functions AF = new Array_Functions();

        Node node = new Node(0);
        Node Head = node, tempNode;

        for (int i=0; i<10; i++){
            tempNode = new Node(i+1);
            node.setNext(tempNode);
            node = node.getNext();
        }

        Head.printList();

    }
}
