#include <iostream>
using namespace std;

class Shape {
public:
	virtual float calculateArea(){
		return 0;
	}
	virtual float calculateKeliling(){
		return 0;
	}
};

class Rectangle : public Shape {
private:
	float length, width;
public:
	Rectangle(float length, float width) {
		this->length = length;
		this->width = width;
	}
	float calculateArea(){
		return length * width;
	}
	float calculateKeliling() {
		return 2 * (length + width);
	}
};

int main() {
	Rectangle rect(5.0f, 4.0f);
	Shape* shape1 = &rect;
	
	cout << "Luasnya adalah : " << shape1->calculateArea() << endl;
	cout << "kelilingnya adalah : " << shape1->calculateKeliling() << endl;
}
