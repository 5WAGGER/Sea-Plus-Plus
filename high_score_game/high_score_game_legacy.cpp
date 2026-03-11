/*
 * Quentin Jeriko
 * COMS-215
 * Dave Harden
 * No documentation is required for this project.
 */

#include <iostream>
using namespace std;

void noNegatives(int* x);
void swap(int* a, int* b);

int main() {

    int x;
    int y;

    int* p1;

    p1 = &x;

    *p1 = 99;

    cout << "# 5: x contains: " << x << endl;

    cout << "# 6: x contains: " << *p1 << endl;

    p1 = &y;

    *p1 = -300;

    int temp;
    int* p2 = &x;

    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    noNegatives(&x);
    noNegatives(&y);

    p2 = &x;
    cout << "#13: x is: " << *p2;
    p2 = &y;
    cout << " and y is: " << *p2 << endl;

    int a[2];
    p2 = a;

    *p2 = x;

    p2[1] = y;

    cout << "#17: The adress of the first element is " << p2 << endl;

    cout << "#18: The adress of the second element is " << (p2+1) << endl;

    p1 = a;
    p2 = a + 1;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    cout << "#20: The first element in a[] is " << a[0] << " and the second element in a[] is " << a[1] << endl;

    swap(&x, &y);
    cout << "#22: Now, x contains: 99 and y contains: 0" << endl;

    swap(&x, &y);
    cout << "#23: Now, a[0] contains: 0 and a[1] contains: 99" << endl;



} 

void noNegatives(int* x) {
    if (*x < 0) {
        *x = 0;
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
