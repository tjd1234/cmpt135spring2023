// RGB_color_allInOne.cpp

#include "cmpt_error.h"
#include <cmath>
#include <iostream>

using namespace std;

class RGB_color
{
	int red = 0;
	int green = 0;
	int blue = 0;

public:
	RGB_color() // default constructor
	{
	} // member initialization is used to set red, green, blue

	RGB_color(int r, int g, int b)
		: red(r), green(g), blue(b)
	{
		if (red < 0 || red > 255)
			cmpt::error("bad red value");
		if (green < 0 || green > 255)
			cmpt::error("bad green value");
		if (blue < 0 || blue > 255)
			cmpt::error("bad blue value");
	}

	// copy constructor
	RGB_color(const RGB_color &other)
		: RGB_color(other.red, other.green, other.blue)
	{
	}

	// getters
	int get_red() const { return red; }
	int get_green() const { return green; }
	int get_blue() const { return blue; }

	void invert()
	{
		red = 255 - red;
		green = 255 - green;
		blue = 255 - blue;
	}

}; // class RGB_color

ostream &operator<<(ostream &out, const RGB_color &c)
{
	out << "(" << c.get_red() << ", "
		<< c.get_green() << ", "
		<< c.get_blue()
		<< ")";
	return out;
}

// returns the distance between two colors
double dist(const RGB_color &a, const RGB_color &b)
{
	int dr = a.get_red() - b.get_red();
	int dg = a.get_green() - b.get_green();
	int db = a.get_blue() - b.get_blue();
	return sqrt(dr * dr + dg * dg + db * db);
}

int main()
{
	RGB_color bg(200, 100, 55);
	cout << "bg=" << bg << "\n";

	RGB_color fill(55, 155, 200);
	cout << "fill=" << fill << "\n";

	double d = dist(bg, fill);
	cout << "dist(" << bg << ", " << fill << ") = " << d << "\n";
}
