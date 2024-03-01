#include <iostream>
#include <time.h>

template <typename T>
void vvod(T* arr, T* Copy, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = T(rand() % 101);   
    }

    for (int i = 0; i < n; i++)
    {
        Copy[i] = arr[i];
    }
}


template <typename T>
void copy(T* arr, T* Copy, int n) // ��������������� ������������ ������ ������������, ����� ������������ ��� ����� ����������
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = Copy[i];
    }
}


template <typename T>
void Print(T arr[], int size) // ����� ���������������� ������� �� �����
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

template <typename T>
int permutation(T arr[], int first, int last) // ������ ����� ������ ����� �� pivot
{
    int pivot = arr[last]; // ���������� ��������� pivot ��� ����� �� ��������� ����� ������������� �����

    int i = first;

    for (int j = first; j <= last - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            std::swap(arr[i], arr[j]); // �������� ������� �����, ��� pivot �����
            i++;
        }
    }
    std::swap(arr[i], arr[last]); //i - ����� ������� pivot
    return (i);
}

template <typename T>
int rand_pivot(T arr[], int first, int last) //������� ������ ���������� ����� - pivot
{
    srand(time(NULL));
    int random = first + rand() % (last - first); // ������ ���������� ����� �� �������

    std::swap(arr[random], arr[last]);

    return permutation(arr, first, last);
}

template <typename T>
void quickSort(T arr[], int first, int last) // ������� ����������; first- ���������� ������ � ������������� �����; last- ���������� ������ � ������������� �����
{
    if (first < last)
    {
        int p = rand_pivot(arr, first, last); //������ pivot

        quickSort(arr, first, p - 1);
        quickSort(arr, p + 1, last);
    }
}

template <typename T>
void bubbleSort(T* arr, int n) //���������� ���������
{
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);

                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }

}

template <typename T>
void insertionSort(T* arr, int n) //���������� ���������
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (arr[j - 1] > arr[j]) {
            T t = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = t;
            j--;
        }
    }
}

int main()
{
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    int* arr = new int[n];
    int* Copy = new int[n]; //������ ��������� ����� ������������� �������

    vvod(arr, Copy, n);

    int num;
    clock_t begin, end; // ��� �������� ����� ����� ������� � ������� ������ ���������� ���������
    std::cout << "1 - Quick Sort" << std::endl;
    std::cout << "2 - Bubble Sort" << std::endl;
    std::cout << "3 - Insertion Sort" << std::endl;
    std::cout << "4 - Output sorted array" << std::endl;
    std::cout << "5 - Original array" << std::endl;
    std::cout << "0 - Complete the work" << std::endl;
    std::cout << "Enter the required number: ";
    std::cin >> num;
    while (num)
    {
        switch (num)
        {
        case 1:
            copy(arr, Copy, n); //��������������� ������ ������ �� ������������
            begin = clock(); //���������� ����� ������ ������ ����������
            quickSort(arr, 0, n - 1);
            end = clock();
            std::cout << "Time = " << (end - begin) / (float)CLOCKS_PER_SEC << std::endl; //������ ������� ������ �������, ��������� � �������
            break;

        case 2:
            copy(arr, Copy, n); //��������������� ������ ������ �� ������������
            begin = clock(); //���������� ����� ������ ������ ����������
            bubbleSort(arr, n);
            end = clock();
            std::cout << "Time = " << (end - begin) / (float)CLOCKS_PER_SEC << std::endl; //������ ������� ������ �������, ��������� � �������
            break;

        case 3:
            copy(arr, Copy, n); //��������������� ������ ������ �� ������������
            begin = clock(); //���������� ����� ������ ������ ����������
            insertionSort(arr, n);
            end = clock();
            std::cout << "Time = " << (end - begin) / (float)CLOCKS_PER_SEC << std::endl; //������ ������� ������ �������, ��������� � �������
            break;
        case 4:
            Print(arr, n);
            break;
        case 5:
            Print(Copy, n);
            break;
     
        }
        std::cin >> num;
    }
    delete[] arr;
    delete[] Copy;
    return 0;
}