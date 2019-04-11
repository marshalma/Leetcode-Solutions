#include <iostream>

using namespace std;

inline int addone(int in) {return in+1;}

int main() {
	int num = 0;
	clock_t t1,t2;
	t1=clock();
	for (int i = 0; i < (1<<27); i++) {
		num = addone(num);
	}
	t2=clock();
	float diff ((float)t2-(float)t1);
	cout<<diff<<endl;
}