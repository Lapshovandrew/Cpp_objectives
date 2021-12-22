#include <iostream>
#include <cstring>
#include <fstream>
#include <malloc.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

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

    float X[length];
    float Y[length];
    float distances[length - 1];
    float sign[length - 1];

    string *XYs;
    XYs = new string[length];

    while(getline(file_, s)) {
        XYs[i] = s;
        i = i + 1;
    }
    XYs[0].erase(0, 1);
    XYs[0].erase(0, 1);
    XYs[0].erase(0, 1);

    file.close();

    for (int j = 0; j < length; j++) {
        string _x;
        string _y;
        while (XYs[j][0] != ' ') {
            _x += XYs[j][0];
            XYs[j].erase(0, 1);
        }
        XYs[j].erase(0, 1);
        _y = XYs[j];
        X[j] = stof(_x);
        Y[j] = stof(_y);
    }

    for(int k = 1; k < length; k++) {
        if (X[0]*Y[k] - X[k]*Y[0] == 0.0) {
            sign[k-1] = 0.0;
            distances[k-1] = 0.0;
        }

        else {
            sign[k-1] = abs(X[0]*Y[k] - X[k]*Y[0])/(X[0]*Y[k] - X[k]*Y[0]);
            distances[k-1] = sqrt((X[k]*X[k] + Y[k]*Y[k])*((X[k] - X[0])*(X[k] - X[0]) + (Y[k] - Y[0])*(Y[k] - Y[0])) - (X[k]*(X[k] - X[0]) + Y[k]*(Y[k] - Y[0]))*(X[k]*(X[k] - X[0]) + Y[k]*(Y[k] - Y[0])))/sqrt(X[0]*X[0] + Y[0]*Y[0]);
            distances[k-1] = sign[k-1]*distances[k-1];
        }
    }

    int right_d_el = max_element(distances, distances + length - 1) - distances;
    int left_d_el = min_element(distances, distances + length - 1) - distances;

    cout << "Leftmost: " << X[right_d_el] << " " << Y[left_d_el]<< endl;
    cout << "Rightmost: " << X[left_d_el] << " " << Y[right_d_el] << endl;

    return 0;

}





