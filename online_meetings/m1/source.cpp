#include <iostream>
#include <vector>

using namespace std;

// in: real value - x - polynomial point
// in: array of real values - coefficients - the polynomial coeffs.
// in: integer - length - the length of coeff. array
// out: real value - the evaluation of the poly. in the given point x

float eq_gamma(float x, float coefficients[], int length) {
    // coefficients: 4, 2, 3
    // problem: 3x^2 + 2x^1 + 4x^0

    // initialization: define the smallest polynomial
    // 3x + 2
    float result = coefficients[length - 1]*x + coefficients[length - 2];

    // decide for how long are you gonna loop:
    //    - given the fact that you already have a poly of degree 1 you
    //      must loop for (degree - 1) times. The length of the coeffs.
    //      gives you the degree of the given poly.
    //    - so we have to iterate for (length - 2) times.
    // loop:
    //    step i: multiply the previous polynomial with x then add the next coeff.
    // (3x^1 + 2)*x + 4
    //         pos:  0  1  2
    // coefficients: 4  2  3
    // length: 3
    for(int i = 0; i < length - 2; i++) {
        result *= x;
        result += coefficients[length - 3 - i];
    }
    return result;

}

// in: real value - x - polynomial point
// in: array of real values - coefficients - the polynomial coeffs.
// in: integer - length - the length of coeff. array
// out: real value - the evaluation of the poly. in the given point x

float eq_beta(float x, float coefficients[], int length) {
    float result = 0;
    float factor = 1;
    for(int i=0; i <= length; i++) {
        result = result + (factor * coefficients[i]);
        factor = factor * x;
    }

    return result;
}

float eq_alpha(float x, const vector<float>& coefficients) {
    float result = 0;
    float factor = 1; // factor is just a way of monitoring the
    // evolution of x's value over time
    for(float coefficient : coefficients) {
        result = result + (factor * coefficient);
        factor = factor * x;
    }
    return result;
}

int main() {
    // Testing some simple use cases of eq_alpha.
    cout << "eq_alpha testing: " << endl;
    vector<float> v = vector<float>{4, -3, 1};
    cout << eq_alpha(1.0, v) << endl; // 2
    cout << eq_alpha(2.0, v) << endl; // 2
    cout << eq_alpha(3.0, v) << endl; // 4
    cout << eq_alpha(4.0, v) << endl << endl; // 8

    // Testing some simple use cases of eq_alpha.
    float t[4] = {4, -3, 1};
    cout << "eq_beta testing: " << endl;
    cout << eq_beta(1.0, t, 3) << endl; // 2
    cout << eq_beta(2.0, t, 3) << endl; // 2
    cout << eq_beta(3.0, t, 3) << endl; // 4
    cout << eq_beta(4.0, t, 3) << endl << endl; // 8

    // Testing some simple use cases of eq_gamma.
    float p[4] = {4, -3, 1};
    cout << "eq_beta testing: " << endl;
    cout << eq_gamma(1.0, p, 3) << endl; // 2
    cout << eq_gamma(2.0, p, 3) << endl; // 2
    cout << eq_gamma(3.0, p, 3) << endl; // 4
    cout << eq_gamma(4.0, p, 3); // 8
    return 0;
}
