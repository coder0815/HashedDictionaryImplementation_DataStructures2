#pragma once
#include "HashedEntry.h"
#include <vector>
#include <string>

using namespace std;

template<class KeyType, class ItemType>
class HashedDictionary
{
private:
	HashedEntry<KeyType, ItemType>** hashTable; // Array of pointers to entries
	int itemCount; // Count of dictionary entries
	int hashTableSize; // Table size must be prime
	static const int DEFAULT_SIZE = 101;
	vector<int> keyValues; // list to hold integer key values	
	int powerOfTwo; // exponent to raise 2 to
	int evaluatedPowerOfTwo; // 2 raised to 'powerOFTwo'
	int evaluatedValue; // value of key

	
	int GetPowerOfTwo(int number);
	void SetPowerOfTwo(int number);
	void RaiseToPower(int num, int power);	// Raise evaluatedPowerOfTwo to the indicated power of two
	void SetEvaluatedPowerOfTwo(int number);	// Set the value of 'EvaluatedPowerOfTwo"
	int EvaluateHornersRule(int evalPower, vector<int> key);	// evaluate horner's rule for hashing values in a dictionary
	void GetASCIIValues(KeyType key);	// get the ASCII values of the given string key


public:
	HashedDictionary();
	HashedDictionary(int tableSize);
	bool AddEntry(KeyType key, ItemType newEntry);
	ItemType GetEntry(const KeyType key);
	int GetHashIndex(KeyType key);
};
#include "HashedDictionary.cpp"

