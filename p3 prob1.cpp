#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort
void bubbleSort(vector<int> arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }

    cout << "Bubble Sort: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

// Selection Sort
void selectionSort(vector<int> arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(arr[i], arr[minIndex]);
    }

    cout << "Selection Sort: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

// Insertion Sort
void insertionSort(vector<int> arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    cout << "Insertion Sort: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of marks: ";
    cin >> n;

    vector<int> marks(n);

    cout << "Enter marks:\n";
    for (int i = 0; i < n; i++)
        cin >> marks[i];

    bubbleSort(marks);
    selectionSort(marks);
    insertionSort(marks);

    return 0;
}