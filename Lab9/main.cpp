#include <ctime>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

const int NUMBERS_SIZE = 50000;

int genRandInt(int low, int high)
{
    return (low + rand() % (high - low + 1));
}
//function to fill array of random numbers
void fillArrays(int arr1[], int arr2[],int arr3[])
{
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

//function to display array elements
void displayOutput(int numbers[NUMBERS_SIZE], int NUMBERS_SIZE)
{
    cout << endl<< "Array elements are:" << endl;
    for (int i = 0; i < NUMBERS_SIZE; i++)
    {
        cout << " " << numbers[i];
    }
}

//Quicksort_midpoint function
void Quicksort_midpoint(int numbers[NUMBERS_SIZE], int i, int k)
{
    if (k == i + 1)
    {
        if (numbers[i] > numbers[k])
        {
            int temp;
            temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;
        }
        return;
    }
    if (i >= k)
        return;
    int pivot = numbers[i + (k - i) / 2];
    //cout<<endl<<"pivot: "<<pivot<<" i:"<<i<<" k:"<<k;
    //getchar();
    int num1 = i - 1;
    int num2 = k + 1;
    while (num1 <= num2)
    {
        do
        {
            num1++;
        } 
        while (numbers[num1] < pivot && num1 <= num2);
        do
        {
            num2--;
        } 
        while (numbers[num2] > pivot && num1 <= num2);
        if (num1 <= num2)
        {
            int temp;
            temp = numbers[num1];
            numbers[num1] = numbers[num2];
            numbers[num2] = temp;
        }
    }
    Quicksort_midpoint(numbers, i, num2);
    Quicksort_midpoint(numbers, num2 + 1, k);
}

//function Quicksort_medianOfThree
void Quicksort_medianOfThree(int numbers[NUMBERS_SIZE], int i, int k)
{
    if (k == i + 1)
    {
        if (numbers[i] > numbers[k])
        {
            int temp;
            temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;
        }
        return;
    }
    if (i >= k)
        return;
    int mid = numbers[i + (k - i) / 2];
    int pivot;
    if (numbers[i] < numbers[mid] && numbers[mid] < numbers[k])
        pivot = mid;
    else if (numbers[i] < numbers[mid] && numbers[i] > numbers[k])
        pivot = i;
    else
        pivot = k;
    int num1 = i - 1;
    int num2 = k + 1;
    while (num1 <= num2)
    {
        do
        {
            num1++;
        } 
        while (numbers[num1] < pivot && num1 <= num2);
        do
        {
            num2--;
        } 
        while (numbers[num2] > pivot && num1 <= num2);
        if (num1 <= num2)
        {
            int temp;
            temp = numbers[num1];
            numbers[num1] = numbers[num2];
            numbers[num2] = temp;
        }
    }
    Quicksort_midpoint(numbers, i, num2);
    Quicksort_midpoint(numbers, num2 + 1, k);
}

//function InsertionSort
void InsertionSort(int numbers[], int numbersSize) {
    for (int i = 1; i < numbersSize; ++i) {
        int j = i;
        // Insert numbers[i] into sorted part
        // stopping once numbers[i] in correct position
        while (j > 0 && numbers[j] < numbers[j - 1]) {
            
            // Swap numbers[j] and numbers[j - 1]
            int temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
            --j;
        }
    }
}

//main driver function
int main()
{
    /*int arr1[NUMBERS_SIZE], arr2[NUMBERS_SIZE], arr3[NUMBERS_SIZE];
    fillArrays(arr1, arr2, arr3);
    const int CLOCKS_PER_MS = CLOCKS_PER_SEC / 1000;
    clock_t Start1 = clock();
    Quicksort_midpoint(arr1, 0, NUMBERS_SIZE - 1);
    clock_t End1 = clock();
    int elapsedTime1 = (End1 - Start1) / CLOCKS_PER_MS;
    cout << "Quicksort_midpoint algorithm runtime: " << elapsedTime1 << endl;
    clock_t Start2 = clock();
    Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE);
    clock_t End2 = clock();
    int elapsedTime2 = (End2 - Start2) / CLOCKS_PER_MS;
    cout << "Quicksort_medianOfThree algorithm runtime: " << elapsedTime2 << endl;
    clock_t Start3 = clock();
    InsertionSort(arr3, NUMBERS_SIZE);
    clock_t End3 = clock();
    int elapsedTime3 = (End3 - Start3) / CLOCKS_PER_MS;
    cout << "InsertionSort algorithm runtime: " << elapsedTime3 << endl;*/
    return 0;
}