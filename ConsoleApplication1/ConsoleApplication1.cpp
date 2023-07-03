//
//  main.cpp
//  unordered_multiset
//
//  Jean Goulet 2022-03-23
//

#include <iostream>
#include <iomanip>
#include "unordered_set.h"


using namespace std;

int main(int argc, const char* argv[]) {















	unordered_multiset<double> UM;
	cout << "Un ensemble vide" << endl;
	UM.afficher();
	cout << endl << "Construire un petit ensemble de base" << endl;

	UM.insert(5);
	cout << endl << "apres UM.insert(5)" << endl;
	UM.afficher();


	UM.insert(1);
	cout << endl << "apres UM.insert(1)" << endl;
	UM.afficher();


	//UM.insert(1);
	//cout << endl << "apres UM.insert(1)" << endl;
	//UM.afficher();



	//UM.insert(3);
	//cout << endl << "apres UM.insert(3)" << endl;
	//UM.afficher();


	//for (double d = 55; d < 100; d += 12)UM.insert(d);
	//for (double d = 37; d < 100; d += 9)UM.insert(d);
	//UM.afficher();

	//cout << endl << "Enlever 91" << endl;
	//UM.erase(91);
	//UM.afficher();

	/*cout << endl << "Enlever le premier" << endl;
	auto it = UM.erase(UM.begin());
	cout << "Le suivant est " << *it << endl;
	UM.afficher();

	size_t nb = UM.count(55);
	cout << "Il y a " << nb << " 55 dans l'ensemble" << endl;
	cout << "enlever le premier" << endl;
	it = UM.find(55);
	UM.erase(it);
	UM.afficher();

	cout << endl << "Itérer sur l'ensemble" << endl;
	for (it = UM.begin(); it != UM.end(); ++it)cout << *it << " ";
	cout << endl;
	cout << endl << "Itérer à reculons" << endl;
	for (it = UM.end(); it != UM.begin();)cout << *--it << " ";
	cout << endl;

	cout << endl << "Enlever les 5 premiers" << endl;
	UM.erase(UM.begin());
	UM.erase(UM.begin());
	UM.erase(UM.begin());
	UM.erase(UM.begin());
	UM.erase(UM.begin());
	UM.afficher();


	cout << endl << "Grossir l'ensemble" << endl;
	for (double d = 1; d < 100; d += 3)UM.insert(d);
	for (double d = 7; d < 100; d += 6)UM.insert(d);
	for (double d = 37; d < 100; d += 9)UM.insert(d);
	for (double d = 55; d < 100; d += 12)UM.insert(d);

	UM.afficher();
*/
	cout << "Fin du programme" << endl;

	return 0;
}
