//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        data[size]=idx;
        upheap(size, weightArr);
        size++;
        // TODO: insert index at end of heap, restore order using upheap()
    }

    int pop(int weightArr[]) {

        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        int d= data[0];
        data[0] = data[size];
        downheap(0  , weightArr);
        size--;
        return d;
        return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        while (weightArr[pos]<weightArr[(pos-1)/2]) {
            swap(data[pos], data[(pos-1)/2]);
            swap(weightArr[pos], weightArr[(pos-1)/2]);
        }
        // TODO: swap child upward while smaller than parent
    }

    void downheap(int pos, int weightArr[]) {
        while (pos*2 <= size) {
            if (weightArr[pos] > weightArr[pos*2]) {
                swap(data[pos], data[(pos)*2]);
                swap(weightArr[pos], weightArr[pos*2]);
                pos=(pos*2);
            }
            else if (pos*2+1==size&&weightArr[pos] > weightArr[pos*2+1]) {
                swap(data[pos], data[(pos)*2+1]);
                swap(weightArr[pos], weightArr[pos*2+1]);
                pos=(pos*2)+1;
            }

        }
        // TODO: swap parent downward while larger than any child
    }
};

#endif