#include <iostream>
#include <vector>
using namespace std;

class Sorting
{
private:
    int arr[10] = {88, 21, 43, 22, 11, 41, 2, 9, 21, 0};
    int length = sizeof(arr) / sizeof(arr[0]);

public:
    Sorting(){
        cout << "Object Invoked\n";
    }

    void print(){
        for (int i = 0; i < this->length; i++)
            cout << this->arr[i] << " ";
    }

    int getMax(){
        int max = arr[0];
        for(int i = 0; i < length; i++){
            if(arr[i] > max)
                max = arr[i];
        }
        
        return max;
    }
    void bubbleSort(){
        for (int i = 0; i < length - 1; i++)
        {
            for (int j = 0; j < length - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void selectionSort(){
        for (int i = 0; i < length - 1; i++){
            int currentMax = i;

            for (int j = i + 1; j < length; j++){
                if (arr[j] < arr[currentMax])
                    currentMax = j;
            }

            if (currentMax != i){
                swap(arr[i], arr[currentMax]);
            }
        }
    }

    void insertionSort(){
        for (int i = 1; i < length; i++){
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key){
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    void merge(int arr[], int left, int mid, int right){
        int i, j, k;
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int L[n1], R[n2];

        for (i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        i = j = 0;
        k = left;

        while (i < n1 && j < n2){
            if (L[i] <= R[j]){
                arr[k++] = L[i++];
            }else
                arr[k++] = R[j++];
        }

        while (i < n1)
            arr[k++] = L[i++];
        while (j < n2)
            arr[k++] = R[j++];
    }
    void mergeSort(int arr[], int l, int r){
        if (l < r){
            int mid = l + (r - l) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }

    void startMerge(){
        mergeSort(arr, 0, length - 1);
    }

    int partition(int arr[], int low, int high){
        int pivot = arr[high];
        int i = (low)-1;

        for (int j = low; j < high; j++){
            if (arr[j] <= pivot){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    void quickSort(int arr[], int low, int high){
        if (low < high){
            int p = partition(arr, low, high);

            quickSort(arr, low, p - 1);
            quickSort(arr, p + 1, high);
        }
    }

    void startQuick(){
        quickSort(arr, 0, length - 1);
    }

    void countingSort(){
        int m = getMax();

        vector<int> counts(m + 1, 0);
        for (int i = 0; i < length; i++)
            counts[arr[i]]++;

        for (int i = 1; i <= m; i++)
            counts[i] += counts[i - 1];

        vector<int> op(length);

        for (int i = length - 1; i >= 0; i--){
            op[counts[arr[i]] - 1] = arr[i];
            counts[arr[i]]--;
        }

        for (int i = 0; i < length; i++){
            arr[i] = op[i];
        }
    }

    void countingSortForRadix(int arr[], int exp){
        int max = getMax();

        int output[length];
        int i, count[10] = {0};

        for (i = 0; i < length; i++)
            count[(arr[i] / exp) % 10]++;
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = length - 1; i >= 0; i--){
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (i = 0; i < length; i++)
            arr[i] = output[i];
    }

    void radixSort(){
        int m = getMax();

        for (int exp = 1; m / exp > 0; exp *= 10){
            countingSortForRadix(arr, exp);
        }
    }
};

int main(){
    Sorting sort;
    // sort.bubbleSort();
    sort.print();
    cout << "\n";
    // sort.selectionSort();
    // sort.insertionSort();
    // sort.startMerge();
    // sort.startQuick();
    // sort.countingSort();
    sort.radixSort();
    sort.print();
    return 0;
}