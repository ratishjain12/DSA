#include <iostream>
using namespace std;

class Heap
{
    int size;
    int capacity;
    int arr[];
    Heap(int c)
    {
        size = 0;
        capacity = c;
        arr = new int[c];
    }
    int leftChild(int i)
    {
        return (2 * i + 1);
    }
    int rightChild(int i)
    {
        return (2 * i + 2);
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    insert(int x) // time complexity o(logn)
    {
        if (size == capacity)
            return;
        size++;
        arr[size - 1] = x;
        int i = size - 1;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }
    void minHeapify(int i)
    { // T.C. O(logN)
        int li = leftChild(i), ri = rightChild(i);
        int smallest = i;
        if (li < size && arr[li] < arr[smallest])
        {
            smallest = li;
        }
        if (ri < size && arr[ri] < arr[smallest])
        {
            smallest = ri;
        }
        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }
    int getMin()
    {
        return arr[0];
    }

    int extractMin()
    {
        if (size == 0)
            return INT_MAX;
        if (size == 1)
        {
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        minHeapify(0);
        return arr[size];
    }
    void decreaseKey(int i, int x)
    {
        arr[i] = x;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    void buildHeap() // T.C. O(N)
    {
        for (int i = (size - 2) / 2; i >= 0; i--)
        {
            minHeapify(i);
        }
    }
}