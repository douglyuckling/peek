/**
 * \file Set.hpp
 * \author Douglas W. Paul
 *
 * Declares the Set template class and defines its behavior
 */

#pragma once

#include <vector>

using namespace std;

namespace peek {

	/**
	 * Stores a set of objects
	 * 
	 * Since std::set is ordered, and the STL hash_set is not part of the C++
	 * standard, here we have our own template for an unordered set of items.
	 * There are many ways it could be more efficient and more comprehensive.
	 */
	template <class T>
	class Set {
	public:

		/** Non-initializing constructor */
		Set();

		/** Initializing constructor (from a Set) */
		inline Set(const Set<T> &tSet) {
			addAll(tSet);
		}

		/** Initializing constructor (from a vector) */
		inline Set(const vector<T> &tList) {
			addAll(tList);
		}

		/** Determines if the given object is in the set */
		bool has(const T &t) const;

		/** Adds an object to the set */
		void add(const T &t);

		/** Adds a vector of objects to this set */
		void addAll(const vector<T> &tList);

		/** Adds a set of objects to this set */
		void addAll(const Set<T> &tSet);

		/** Removes an object from the set */
		void remove(const T &t);

		/** Subtracts a set of objects from this set */
		void removeAll(const Set<T> &tSet);

		/** Intersects a set of objects with this set */
		void retainAll(const Set<T> &tSet);

		/** Pops any one element out of the set */
		T popOne();

		/** Gets a list of the objects in this set */
		inline vector<T> getAsList() const { return this->elements; }

		/** Gets the size of the set */
		inline size_t size() const { return this->elements.size(); }

		// Container stuff...

		typedef typename vector<T>::iterator iterator;
		typedef typename vector<T>::const_iterator const_iterator;
		typedef typename vector<T>::reference reference;
		typedef typename vector<T>::const_reference const_reference;

		inline iterator begin() { return this->elements.begin(); }
		inline const_iterator begin() const { return this->elements.begin(); }
		inline iterator end() { return this->elements.end(); }
		inline const_iterator end() const { return this->elements.end(); }
		inline void clear() { this->elements.clear(); }

	private:

		/** The elements of the set */
		vector<T> elements;

	};



	template <class T>
	Set<T>::Set() {}

	/**
	 * \param t The object whose membership is to be determined
	 */
	template <class T>
	bool Set<T>::has(const T &t) const {
		vector<T>::const_iterator i;

		for (i = this->elements.begin(); i != this->elements.end(); i++) {
			if (t == (*i)) {
				return true;
			}
		}

		return false;
	}

	/**
	 * \param t The object to add
	 */
	template <class T>
	void Set<T>::add(const T &t) {
		if (!has(t)) {
			this->elements.push_back(t);
		}
	}

	/**
	 * \param tList The object list whose members to add
	 */
	template <class T>
	void Set<T>::addAll(const vector<T> &tList) {
		vector<T>::const_iterator i;

		for (i = tList.begin(); i != tList.end(); i++) {
			add(*i);
		}
	}

	/**
	 * \param tSet The object set whose members to add
	 */
	template <class T>
	void Set<T>::addAll(const Set<T> &tSet) {
		addAll(tSet.elements);
	}

	/**
	 * \param t The object to remove, if it is in the set
	 */
	template <class T>
	void Set<T>::remove(const T &t) {
		vector<T>::iterator i;

		for (i = this->elements.begin(); i != this->elements.end(); i++) {
			if (t == *i) {
				this->elements.erase(i);
				break;
			}
		}
	}

	/**
	 * \param tSet The object set whose members to subtract
	 */
	template <class T>
	void Set<T>::removeAll(const Set<T> &tSet) {
		vector<T> resultingElements;
		vector<T>::const_iterator i;

		for (i = this->elements.begin(); i != this->elements.end(); i++) {
			// Only keep the object if the given set DOES NOT contain it
			if (!tSet.has(*i)) {
				resultingElements.push_back(*i);
			}
		}

		this->elements = resultingElements;
	}

	/**
	 * \param tSet The object set whose members to retain
	 */
	template <class T>
	void Set<T>::retainAll(const Set<T> &tSet) {
		vector<T> resultingElements;
		vector<T>::const_iterator i;

		for (i = this->elements.begin(); i != this->elements.end(); i++) {
			// Only keep the object if the given set DOES contain it
			if (tSet.has(*i)) {
				resultingElements.push_back(*i);
			}
		}

		this->elements = resultingElements;
	}

	/**
	 * The returned element is removed from the set.
	 *
	 * \return Any element from the set
	 */
	template <class T>
	T Set<T>::popOne() {
		T t = this->elements.back();
		this->elements.pop_back();
		return t;
	}


	/**
	 * Calculates the union of two sets
	 * \param set1 The first set
	 * \param set2 The second set
	 * \return The union of the two sets
	 */
	template <class T>
	Set<T> setUnion(const Set<T> &set1, const Set<T> &set2) {
		Set<T> unionSet = set1;
		unionSet.addAll(set2);

		return unionSet;
	}

	/**
	 * Calculates the intersection of two sets
	 * \param set1 The first set
	 * \param set2 The second set
	 * \return The intersection of the two sets
	 */
	template <class T>
	Set<T> setIntersection(const Set<T> &set1, const Set<T> &set2) {
		Set<T> intersectionSet = set1;
		intersectionSet.retainAll(set2);

		return intersectionSet;
	}

	/**
	 * Calculates the difference between two sets
	 * \param set1 The set whose unique elements are to be found
	 * \param set2 The set to subtract from the first set
	 * \return The elements that are unique to the first set
	 */
	template <class T>
	Set<T> setDifference(const Set<T> &set1, const Set<T> &set2) {
		Set<T> differenceSet = set1;
		differenceSet.removeAll(set2);

		return differenceSet;
	}

}