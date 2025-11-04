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
        if (size==0) {
            return -1;
        }
        int d= data[0];
        data[0] = data[size-1];
        size--;
        downheap(0  , weightArr);
        return d;
        return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        int parent= (pos-1)/2;
        while (weightArr[pos]<weightArr[parent]) {
            //swap(data[pos], data[parent]);
            swap(weightArr[data[pos]], weightArr[data[parent]]);
            //changing weightarr position reference
            pos = parent;
        }
        // TODO: swap child upward while smaller than parent
    }

    void downheap(int pos, int weightArr[]) {
        while (true) {
            int min = pos;
            int left= (2*pos)+1;
            int right = left+1;
            if (left<size && weightArr[data[left]]<weightArr[data[min]]) {
                min= left;
                //changing weightarr position reference
            }
            if (right<size && weightArr[data[right]]<weightArr[data[min]]) {//changing weightarr position reference
                min= right;
            }
            if (min==pos) {
                return;
            }
            swap(data[min], data[pos]);
            pos= min;
        }

       /* while (left <= size) {
            if (weightArr[pos] > weightArr[left]) {
                swap(data[pos], data[left]);
                swap(weightArr[pos], weightArr[left]);
                pos=(left);
            }
            else if (right==size&&weightArr[pos] > weightArr[right]) {
                swap(data[pos], data[right]);
                swap(weightArr[pos], weightArr[right]);
                pos=right;
            }

        }*/
        // TODO: swap parent downward while larger than any child
    }
};

#endif