#include <iostream>
using namespace std;


class myArr {
private:
	int *N;
	int len;
public:
	myArr(int a=10):len(a){
		if ( len > 9) {
			N = new int[len];
			for (int k=0;k<len;k++) N[k]=0;
		}
	}
	~myArr(){
		if (len>0){
			len = 0;
			delete [] N;
		}
	}

	// return a reference to the memory location, so that we
	// can modify the location in the main
	int & operator[](int ind){
		if ( ind >=0 && ind <len ) {
			// return a reference not a value
			return N[ind];
		}
		// We can not return just 0 because of the reference
		// This means that the default length of the array can not be zero!!!!
		return N[0];
	}


};

int main(int argc, char* argv[])
{

	myArr arr1(40);

	// Use the returned reference to assign a value
	arr1[3] = 56;

	// Use the returned value
	cout << arr1[3] << endl;
}