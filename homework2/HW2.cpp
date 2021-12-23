#include <iostream>
#include <cstring>
#include <fstream>
#include <malloc.h>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include <bits/stdc++.h>
#include <utility>

using namespace std;

float* del_first(float* arr, int length) {
    float* s = new float[length - 1];
    for(int i = 0; i < length - 1; i++) {
        s[i] = arr[i+1];
    }
    delete arr;
    return s;
}

float* reverse(float* X, int position) {
    float* Rev = new float[position];
    for(int i = 0, j = position; i < position; i++, j--) {
        Rev[i] = abs(X[position] - X[j - 1]);
    }
    return Rev;
}

int check(float* Xs, float* Hs, float H0, float vx, float vy, float length) {
    int sector;
    int k;
    for(int i = 0; i < length - 2; i++) {
        float yi = H0 + vy*Xs[i]/vx - 9.81*Xs[i]*Xs[i]/(2*vx*vx);
        if ((yi < Hs[i]) && (i == 0)) {
            return i;
        }
        else if (yi < Hs[i]) {
            H0 = yi;
            vx = -vx;
            vy = vy + 9.81*Xs[i]/vx;
            Xs = reverse(Xs, i);
            Hs = reverse(Hs, i);
            k = check(Xs, Hs, H0, vx, vy, i);
            sector = i - 1;

        }
        else {
            H0 = yi;
            vy = vy - 9.81*Xs[i]/vx;
            vx = vx;
            //
            Xs = del_first(Xs, length - 2);
            Hs = del_first(Hs, length - 2);
            length = length - 1;
            k = check(Xs, Hs, H0, vx, vy, length);
            sector = 1 + i;
        }
    }
    return sector;
}

void Sort(float* X, float* Y, int length) {
    float temp;
    for(int i = 1; i < length; i++) {
        for(int j = 0; j < length - i; j++) {
            if (X[j] > X[j+1]) {
                temp = X[j];
                X[j] = X[j+1];
                X[j+1] = temp;
                temp = Y[j];
                Y[j] = Y[j+1];
                Y[j+1] = temp;
            }
        }
    }
}

int main(int argc, char** argv) {
    if (argc == 2) {
        string FN = argv[1];
        string s;
        ifstream file(FN);
        int length = 0;
        int i = 0;

        while(getline(file, s)) {
            length += 1;
        }
        file.close();


        ifstream file_(FN);
        float H0;

        float vx, vy;
        float *Xs = new float[length - 2];
        float *Hs = new float[length - 2];
        int k = 0;

        while(getline(file_, s)) {
            i = i + 1;
            if (i == 1) {
                H0 = stof(s);
            }
            else if (i == 2) {
                string VX, VY;
                while (s[0] != ' ') {
                    VX += s[0];
                    s.erase(0, 1);
                }
                s.erase(0, 1);
                VY = s;
                vx = stof(VX);
                vy = stof(VY);
            }
            else {
                string VX, VY;
                while (s[0] != ' ') {
                    VX += s[0];
                    s.erase(0, 1);
                }
                s.erase(0, 1);
                VY = s;
                Xs[k] = stof(VX);
                Hs[k] = stof(VY);
                k = k + 1;
            }
        }


        file_.close();
        k = 0;
        Sort(Xs, Hs, length - 2);

        if (length - 2 == 1) {
            if (vx > 0) {
                double dt = Xs[0]/vx;
                double Y_ = H0 + vy*dt - 9.81*dt*dt/2;
                if (Y_ <= Hs[0]) {
                    k = 0;
                }
                else {
                    k = 1;
                }
            }
            else {
                k = 0;
            }
        }

        else {
            k = check(Xs, Hs, H0, vx, vy, length);
        }
        cout << k << endl;
    }
    else {
        exit(1);
    }
    return 0;
}

