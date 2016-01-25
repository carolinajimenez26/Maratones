#include <bits/stdc++.h>

using namespace std;


int main(void){
	string nombre, edad, estatura, cadena, nombre1 = "c", edad1="b", estatura1="a";
	cadena = "a b c";

	ostringstream s2;
	s2 << nombre1 << "," << edad1 << "," << estatura1 << "." << endl;
	cout << s2.str();

	istringstream s(cadena);
	s >> nombre >> edad >> estatura;
	cout << nombre << edad << estatura << endl;
}
