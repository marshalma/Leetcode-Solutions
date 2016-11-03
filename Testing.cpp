#include "Header.hpp"

using namespace std;

class Complex
{
private:
	int real;
	int imag;
public:
	Complex(int r, int i)  {  real = r;   imag = i; }
	int getReal() {return real;}
	int getImag() {return imag;}
	Complex operator ++(int);
	Complex & operator ++();
};

class SingleMember {
	int a;
	public:
		SingleMember(int v) : a(v) {
			
		}
};

// << overload
ostream& operator<<(ostream& os, const vector<int>& vec) {
	for (const auto& item : vec) {
		os << item << ' ';
	}
	return os;
}

ostream& operator<<(ostream& os, Complex c) {
	os << c.getReal() << " + " << c.getImag() << 'i' << endl;
	return os;
}


// function compare
bool what (const int &a, const int &b) {
	return a > b;
}

// class compare
class Greater{
	bool operator() (const int &a, const int &b) {
		return a < b;
	}
};


// ++ overload
Complex &Complex::operator ++()
{
	real++; imag++;
	return *this;
}

Complex Complex::operator ++(int i)
{
	Complex c1(real, imag);
	operator++();
	return c1;
}

class StaticInit {
	const static vector<int> a = {1,2,3,4,5};
};



int main() {	
//	vector<int> vec {1,2,3,4,5,6,7};
//	sort(vec.begin(), vec.end(), [ ](const int& lh, const int& rh) {return lh > rh;});
//	Greater great;
//	priority_queue<int, vector<int>, Greater> pq;
//	cout << vec << endl;
//	
//	Complex c1(10, 15);
//	cout << c1++; 
//	cout << ++c1;
//	SingleMember b = 1;

	vector<int>	v;
	for (int i = 0; i < 10000; i++) {
		cout << v.capacity() << endl;
		v.push_back(1);
		
	}
	return 0;
}