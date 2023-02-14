// color_test.cpp

//
// To compile this program, compile each .cpp file separately:
//
//     > g++ -c RGB_color.cpp   // creates RGB_color.o
//     > g++ -c color_test.cpp  // creates color_test.o
//
// Link the .o files together to create the executable color_test:
//
//     > g++ RGB_color.o color_test.o -o color_test  // creates color_test
//
// Now you can you can run the program:
//
//     > ./color_test
//     ...
//

#include "RGB_color.h"
#include <iostream>

using namespace std;

int main()
{
	RGB_color bg(200, 100, 55);
	cout << "bg=" << bg << "\n";

	RGB_color fill(55, 155, 200);
	cout << "fill=" << fill << "\n";

	double d = dist(bg, fill);
	cout << "dist(" << bg << ", " << fill << ") = " << d << "\n";
}
