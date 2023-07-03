//
//  unordered_set_2.h
//  unordered_multiset
//
//  Jean Goulet
//  Copyleft 2017
//


#ifndef unordered_multiset_2_h
#define unordered_multiset_2_h

#include "unordered_set.h";
#include <cassert>
#include <iostream>
/////////////////////////////////////////////////////////////////////
// rehash


template <typename TYPE, typename classe_de_dispersion>
void unordered_multiset<TYPE, classe_de_dispersion>::rehash(size_t nbalv) {

	size_t Asize = REP.size();
	size_t Nsize = (REP.size() * 2) - 1;

	vector<list<TYPE>*> Nrep(Nsize);

	if (nbalv > Asize) {
		for (size_t i = 0; i < REP.size(); ++i) {
			while (REP[i] != nullptr && i != 1) {
				auto it = REP[i]->begin();
				Nrep[disperseur(*REP[i]->begin()) / Nsize] = REP[i];
				delete REP[i];
				REP[i] = nullptr;
			}
		}
		REP = Nrep;
	}
	else if (nbalv > Asize) {

	}

}


///////////////////////////////////////////
// avancer et reculer un iterateur

template <typename TYPE, typename classe_de_dispersion>
void unordered_multiset<TYPE, classe_de_dispersion>::iterator::avancer() {
	assert(this->POS != ALV->begin());
	return ++POS;
}

template <typename TYPE, typename classe_de_dispersion>
void unordered_multiset<TYPE, classe_de_dispersion>::iterator::reculer() {
	assert(this->POS != ALV->end());
	return --POS;
}

/////////////////////////////////////////////////////////////////////
// fonctions generatrices

template <typename TYPE, typename classe_de_dispersion>
typename unordered_multiset<TYPE, classe_de_dispersion>::iterator
unordered_multiset<TYPE, classe_de_dispersion>::insert(const TYPE& VAL) {

	size_t nbAlv = REP.size();
	size_t key = disperseur(VAL);

	size_t index = disperseur(VAL) % nbAlv;
	list<TYPE>* alv = REP[index];

	// le nbr max d'element moyen par alveole
	if ((SIZE / REP.size() > facteur_max) || (index == 1 && REP.size() == 2))
		if (alv == nullptr)
			REP[index] = new list<TYPE>();

		else if (index == 1) rehash(nbAlv);
	REP[index]->push_back(VAL);
	++SIZE;
	return *(new iterator(REP.begin() + index, --REP[index]->end()));
}

template <typename TYPE, typename classe_de_dispersion>
size_t unordered_multiset<TYPE, classe_de_dispersion>::erase(const TYPE& VAL) {
	int index = disperseur(VAL);
	index = (REP.size() - 1) % index;
	auto itAlv = REP.begin();

	if (REP.empty() || (REP.begin() + index) == nullptr)
		return SIZE;
	else {
		auto itPos = (REP.begin() + index)->begin();
		for (itPos; itPos != (REP.begin() + index)->end(); itPos++) {
			if (*itPos == VAL) {
				unordered_multiset<TYPE, classe_de_dispersion>::iterator it = new iterator(itAlv, itPos);
				if (erase(it).ALV->empty()) {
					delete it.ALV;
					it.ALV = nullptr;
				}
			}
			else return SIZE;
		}
	}
	return --SIZE;
}

template <typename TYPE, typename classe_de_dispersion>
typename unordered_multiset<TYPE, classe_de_dispersion>::iterator unordered_multiset<TYPE, classe_de_dispersion>::erase(typename unordered_multiset<TYPE, classe_de_dispersion>::iterator i) {
	i.ALV->eraser(i.POS);
	return i;
}
/////////////////////////////////////////////////////////////////////
// count
template <typename TYPE, typename classe_de_dispersion>
size_t unordered_multiset<TYPE, classe_de_dispersion>::count(const TYPE& VAL)const {
	int index = disperseur(VAL);
	index = (REP.size() - 1) % index;
	auto itAlv = REP.begin();
	int valCmp = 0;
	auto itPos = (REP.begin() + index)->begin();
	for (itPos; itPos != (REP.begin() + index)->end(); itPos++) {
		if (*itPos == VAL) {
			++valCmp;
		}
	}
	return valCmp;
}

/////////////////////////////////////////////////////////////////////
// find
template <typename TYPE, typename classe_de_dispersion>
typename unordered_multiset<TYPE, classe_de_dispersion>::iterator unordered_multiset<TYPE, classe_de_dispersion>::find(const TYPE& VAL) {

	int index = disperseur(VAL);
	index = (REP.size() - 1) % index;
	auto itAlv = REP.begin();
	int valCmp = 0;
	auto itPos = (REP.begin() + index)->begin();
	for (itPos; itPos != (REP.begin() + index)->end(); itPos++) {
		if (*itPos == VAL) {
			++valCmp;
		}
	}
	unordered_multiset<TYPE, classe_de_dispersion>::iterator it = new iterator(itAlv, itPos);
	return it;
}




#endif /* unordered_multiset_2_h */
