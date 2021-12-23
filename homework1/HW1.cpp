#include <iostream>
#include <cstring>
#include <fstream>
#include <malloc.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

int max_el(float* A, int length) {
    float s = A[0];
    int index = 0;
    for(int i = 1; i < length; i++) {
        if ((A[i] > s) || (A[i] == s)) {
            s = A[i];
            index = i;
        }
    }
    return index;
}

int min_el(float* A, int length) {
    float s = A[0];
    int index = 0;
    for(int i = 1; i < length; i++) {
        if ((A[i] < s) || (A[i] == s)) {
            s = A[i];
            index = i;
        }
    }
    return index;
}

using namespace std;

int main() {

    string s;
    string xy;
    ifstream file("in.txt");
    int length = 0;
    int i = 0;

    while(getline(file, s)) {
        length += 1;
    }
    file.close();


    ifstream file_("in.txt");

    float* X = new float[length];
    float* Y = new float[length];
    float* distances = new float[length - 1];
    float* sign = new float[length - 1];

    string *XYs;
    XYs = new string[length];

    while(getline(file_, s)) {
        XYs[i] = s;
        i = i + 1;
    }

    file.close();

    for (int j = 0; j < length; j++) {
        string _x;
        string _y;
        while (XYs[j][0] != ' ') {
            _x += XYs[j][0];
            XYs[j].erase(0, 1);
        }
        XYs[j].erase(0, 1);
        _y += XYs[j];

        X[j] = stof(_x);
        Y[j] = stof(_y);
    }

    float d1, d2, d3;
    for(int k = 1; k < length; k++) {
        if (X[0]*Y[k] - X[k]*Y[0] == 0.0) {
            sign[k - 1] = 0.0;
            distances[k - 1] = 0.0;
        }

        else {
            sign[k - 1] = (0 - 1)*abs(X[0]*Y[k] - X[k]*Y[0])/(X[0]*Y[k] - X[k]*Y[0]);
            d1 = X[k]*X[k] + Y[k]*Y[k];
            d2 = (X[0]*X[k] + Y[0]*Y[k])*(X[0]*X[k] + Y[0]*Y[k]);
            d3 = X[0]*X[0] + Y[0]*Y[0];
            distances[k - 1] = sign[k - 1]*abs(sqrt(d1 - (d2/d3)));
        }
        d1 = 0.0;
        d2 = 0.0;
        d3 = 0.0;

    }

    int left_d_el = min_el(distances, length - 1);
    int right_d_el = max_el(distances, length - 1);

    cout << "Leftmost: " << X[left_d_el + 1] << " " << Y[left_d_el + 1] << endl;
    cout << "Rightmost: " << X[right_d_el + 1] << " " << Y[right_d_el + 1] << endl;

    return 0;

}




