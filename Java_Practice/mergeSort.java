

public class mergeSort {

    private static void merge(int [] arr, int low, int high){

        int mid = (high + low)/2;

        // Allocate space for temporary arrays
        int [] lowHalf = new int[mid-low+1];
        int [] highHalf= new int[high-mid];
        int j = 0;

        // Copy halves from original to tempArray

        for (int i = low; i < low+lowHalf.length; i++){
            lowHalf[j] = arr[i];
            j++;
        }

        j = 0;

        for (int i = mid+1; i < high+1; i++){
            highHalf[j] = arr[i];
            j++;
        }

        // compare and merge
        j = low;
        low = 0;
        high = 0;
        while((low < lowHalf.length) && (high < highHalf.length)){
            if (lowHalf[low] < highHalf[high]){
                arr[j] = lowHalf[low];
                low++;
            }
            else{
                arr[j] = highHalf[high];
                high++;
            }
            j++;
        }

        // copy any tempArray data that wasnt copied above
        for (int i = low; i < lowHalf.length; i++){
            arr[j] = lowHalf[i];
            j++;
        }
        for (int i = high; i < highHalf.length; i++){
            arr[j] = highHalf[i];
            j++;
        }
    }


    private static void mSort(int [] arr, int low, int high){
        if (high <= low) return;

        int mid = (low + high)/2;

        mSort(arr, low, mid);
        mSort(arr, mid+1, high);
        merge(arr, low, high);
    }

    public static void sort(int [] arr){
        mSort(arr, 0, arr.length-1);
    }

}
