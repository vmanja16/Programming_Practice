

public class sortMain {


    public static void printArr(int [] arr){
        for (int i = 0; i < arr.length; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }


    public static void assertSorted(int [] arr){
        if (arr.length <= 1){return;}
        for (int i = 0; i < arr.length-1; i++){
            assert(arr[i] <= arr[i+1]): "Array is UNSORTED";
        }
    }


    public static void main(String [] args){

        int ARRAY_SIZE = 99;
        int MAX_VAL = 100;

        int [] testArray = new int[ARRAY_SIZE];

        for (int i = 0; i < ARRAY_SIZE; i++){
            testArray[i] = (int)(Math.random() * MAX_VAL);
        }
        /* TEST MERGESORT */

        printArr(testArray);
        mergeSort.sort(testArray);
        assertSorted(testArray);
        printArr(testArray);



    }
}
