package com.company;

/**
 * Created by Vikram on 8/2/2017.
 */

public class Node {

    private Node next;
    private Integer num;

    public Node(int number){
        num = number;
        next = null;
    }
    public Node getNext(){
        return next;
    }
    public Integer getNum(){
        return num;
    }
    public void setNext(Node next){
        this.next = next;
    }
    public void setNum(int num){
        this.num = num;
    }
    public void printNum(){
        System.out.println(this.num);
    }
    public void printList(){
        Node node = this;
        while (node != null){
            System.out.println(node.getNum());
            node = node.getNext();
        }
    }

}
