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
	vector<int> binaryNumbers; // list to hold the binary representation of the keyValues
	vector<vector<int>> binary; // list to hold the list of binary representations of keyValues for finding the largest power of 2.
	int powerOfTwo; // exponent to raise 2 to
	int evaluatedPowerOfTwo; // 2 raised to 'powerOFTwo'
	int evaluatedValue; // value of key

	void ConvertToBinary(int num);
	void SetPowerOfTwo(vector<vector<int>> list);
	void RaiseToPower(int num, int power);
	int EvaluateHornersRule(int evalPower, vector<int> key);


public:
	HashedDictionary();
	HashedDictionary(int tableSize);
	bool AddEntry(KeyType key, ItemType newEntry);
	ItemType GetEntry(const KeyType key);
	int GetHashIndex(KeyType key);
};
#include "HashedDictionary.cpp"

