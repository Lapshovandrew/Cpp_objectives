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
    ifstream file("D:\\in.txt");
    int length = 0;
    int i = 0;

    while(getline(file, s)) {
        length += 1;
    }
    file.close();

    ifstream file_("D:\\in.txt");

    float X[length];
    float Y[length];
    float distances[length - 1];
    float angles[length - 1];
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

    int right_a_el;
    for(int k = 1; k < length; k++) {
        if (X[0]*Y[k] - X[k]*Y[0] == 0.0) {
            angles[k-1] = 2.0;
            sign[k-1] = 0.0;
            distances[k-1] = 0.0;
            right_a_el = k;
        }

        else {
            angles[k-1] = (X[0]*X[k] + Y[0]*Y[k])/(sqrt(X[0]*X[0] + Y[0]*Y[0])*sqrt(X[k]*X[k] + Y[k]*Y[k])) - 1.0;
            sign[k-1] = abs(X[0]*Y[k] - X[k]*Y[0])/(X[0]*Y[k] - X[k]*Y[0]);
            distances[k-1] = sqrt((X[k]*X[k] + Y[k]*Y[k])*((X[k] - X[0])*(X[k] - X[0]) + (Y[k] - Y[0])*(Y[k] - Y[0])) - (X[k]*(X[k] - X[0]) + Y[k]*(Y[k] - Y[0]))*(X[k]*(X[k] - X[0]) + Y[k]*(Y[k] - Y[0])))/sqrt(X[0]*X[0] + Y[0]*Y[0]);
            angles[k-1] = sign[k-1]*angles[k-1];
            distances[k-1] = sign[k-1]*distances[k-1];
        }
    }

    right_a_el = max_element(angles, angles + length - 1) - angles;
    int left_a_el = min_element(angles, angles + length - 1) - angles;
    int right_d_el = max_element(distances, distances + length - 1) - distances;
    int left_d_el = min_element(distances, distances + length - 1) - distances;

    cout << "rightest by angle: " << X[right_a_el] << " " << Y[right_a_el] << endl;
    cout << "leftest by angle: " << X[left_a_el] << " " << Y[left_a_el] << endl;
    cout << "rightest by distance: " << X[right_d_el] << " " << Y[right_d_el]<< endl;
    cout << "leftest by distance: " << X[left_d_el] << " " << Y[left_d_el] << endl;

    return 0;

}


