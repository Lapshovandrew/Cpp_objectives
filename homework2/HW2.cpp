#include <bits/stdc++.h>

using namespace std;

float* del_first(float* arr, int length) {
    float* s = new float[length - 1];
    for(int i = 0; i < length - 1; i++) {
        s[i] = arr[i + 1];
    }
    delete arr;
    return s;
}

float* reverse(float* X, int position) {
    float* Rev = new float[position];
    for(int i = 0, j = position - 1; j > -1; ++i, --j) {
        Rev[i] = X[j];
    }
    return Rev;
}

float Y2(float X, float vX, float vY, float H) {
    float y0 = H + (vY*X/vX) - (9.81*X*X/(2*vX*vX));
    return y0;
}

int check(float H0, float vx, float vy, float* X, float* Y, int length, int N = 0, int f = 1) {
    int S = N;
    while((Y2(X[S], vx, vy, H0) >= Y[S])&&(S < length + 1)) {
        S += f;
    }
    if (S == length + 1) {
        return S;
    }
    else {
        f = f*(-1);
        vx = -vx;
        vy = vy + 9.81*X[S]/vx;
        X = reverse(X, S);
        H0 = Y[S];
        Y = reverse(Y, S);
        length = S - 1;
        N = check(H0, vx, vy, X, Y, length, S, f);
        return N;
    }
}

void Sort(float* X, float* Y, int length) {
    float temp;
    for(int i = 1; i < length; i++) {
        for(int j = 0; j < length - i; j++) {
            if (X[j] > X[j + 1]) {
                temp = X[j];
                X[j] = X[j + 1];
                X[j + 1] = temp;
                temp = Y[j];
                Y[j] = Y[j + 1];
                Y[j + 1] = temp;
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
        if (length - 2 > 1) {
            Sort(Xs, Hs, length - 2);
        }

        if (length - 2 == 1) {
            if (vx > 0) {
                double dt = Xs[0]/vx;
                double Y_ = H0 + vy*dt - 9.81*dt*dt/2;
                if (Y_ < Hs[0]) {
                    k = 0;
                    cout << k << endl;
                }
                else {
                    k = 1;
                    cout << k << endl;
                }
            }
            else {
                k = 0;
                cout << k << endl;
            }
        }

        else {
            k = check(H0, vx, vy, Xs, Hs, length - 2);
            cout << k << endl;
        }
    }
    else {
        exit(1);
    }
    return 0;
}
