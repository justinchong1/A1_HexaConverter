// A1_HexaConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Write a function that receives a string containing a 32-bit hexadecimal integer. The function must return the decimal integer value of the hexadecimal integer. Demonstrate your function with a driver program.
// By Justin Chong, COSC 2325, Assignment 1

#include <iostream>
using namespace std;

//function that takes in hexadecimal string and converts it into decimal integer.
void hexaConverter(string& myHexa) {
    int answer{ 0 }; //answer output
    int powerOf{ 0 }; //power of the value
    int myInt{ 0 }; //char to digit
    int hexaLength = myHexa.length(); //length of hexa string

    for (int i{ hexaLength - 1 }; i >= 0; i--) { //iterates right to left

        //DIGITS 0-9
        if (myHexa[i] >= '0' && myHexa[i] <= '9') {
            //convert char to int, knowing ASCII '0' is 48, subtract '0' or 48 to get desired hexa integer
            myInt = myHexa[i] - '0';
            answer += myInt * pow(16, powerOf); //equation: sum up the product of the digits by their respective base 16 power value

        }
        else if ((myHexa[i] >= 'A' && myHexa[i] <= 'F') || (myHexa[i] >= 'a' && myHexa[i] <= 'f')) {
            //converts any lowercase letters to uppercase
            if (myHexa[i] >= 'a' && myHexa[i] <= 'f') {
                myHexa[i] = toupper(myHexa[i]);
            }

            //convert char to int, knowing ASCII 'A' = 65, subtract 55 or '7' to get desired hexa integer
            myInt = myHexa[i] - '7';
            answer += myInt * pow(16, powerOf); //equation: sum up the product of the digits by their respective base 16 power value

        }
        else {
            cerr << "Invalid character noticed. \"" << myHexa[i] << "\"" << endl;
            return;
        }

        powerOf++;
    }

    cout << "The hexadecimal: " << myHexa << ", is this in decimal: " << answer << endl;
}

int main()
{
    //DRIVER PROGRAM
 
    //good hexadecimal examples
    string driverHexa1{ "a1B2C" };
    string driverHexa2{ "7d1E3" }; 

    //bad hexadecimal examples
    string driverHexa3{ "cs2325" }; 
    string driverHexa4{ "$100" }; 


    cout << "Good hexadecimals: " << driverHexa1 << ", " << driverHexa2 << "\n" << endl;

    hexaConverter(driverHexa1);
    hexaConverter(driverHexa2);

    cout << "\nBad hexadecimals: " << driverHexa3 << ", " << driverHexa4 << "\n" << endl;

    hexaConverter(driverHexa3); 
    hexaConverter(driverHexa4);

    return 0;
}

