/* TITLE lab9_1.cpp
 * ABSTRACT: this program will prompt for a text file of intergers
 * the program will then insert and sort every interger form the
 * into the array 
 * Author: Kyle Dilbeck 
 * ID: 1996
 * Date: 4/5/19
 */
 
#include <iostream>
#include <fstream>

using namespace std;

int power(int x, int n); 


int main()
{
    int x, n; 
    
    cout << "Enter x value: "; 
    cin  >> x; 
    
    cout << "Enter n value: "; 
    cin >> n; 
    
    //cout << "Result: " ; 
    cout << "Result " <<power(x, n); 
    
    
}


int power(int num1, int num2) 
{
    if (num2 == 1)             // Base case
        return num1;
    else 
        return num1 * power(num1, num2-1);  // Recursive case
}

