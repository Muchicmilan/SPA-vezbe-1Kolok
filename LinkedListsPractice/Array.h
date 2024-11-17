//
// Created by Milan on 11/3/2024.
//

#pragma once
#include<iostream>
using namespace std;

#ifndef ARRAY_H
#define ARRAY_H

inline void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

#endif //ARRAY_H
