import java.util.*;

public class GenericsTest {
    public Test test_obj;
    
    public class Box <T> {
     private ArrayList<T> list; 
     
     public Box(){
         list = new ArrayList<>();
     }
     
     public void add(T E){
         list.add(E);
     }
     
     public void printContents(){
         for (T e : list){
             System.out.println(e);
         }
     }
     
    }
    
    public class Test{
        public Test(){}
        
        public void test(){
            Box box = new Box<Integer>();
            box.add(5);
            box.add(6);
            box.printContents();    
        }
    }
    
    // Constructor
    public GenericsTest(){
        test_obj = new Test();
    }
    
    public static void main(String args[]) {
        GenericsTest M = new GenericsTest();
        M.test_obj.test();
        
        
    }
}