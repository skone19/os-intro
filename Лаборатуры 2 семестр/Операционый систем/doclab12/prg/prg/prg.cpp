#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
	int n=0;
	cout << "Input number\n";
	cin>>n;
	if (n != 0)
	{
		if (n > 0)
			exit(1);
		else
			exit(2);
	}
	return 0;
}

