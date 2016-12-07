#include "HashedDictionary.h"


template<class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::GetPowerOfTwo(int number)
{
	int power = 0;  // power of two
	int value = number; // number to get power of two from

	while (value > 1)
	{
		value /= 2;
		power++; // increaase the power of two
	}
	return power + 1;
}

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::SetPowerOfTwo(int number)
{
	powerOfTwo = number;
}

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::RaiseToPower(int num, int power)
{
	int number = num;
	for (int i = 0; i < power; i++)
	{
		number *= number;
	}
	SetEvaluatedPowerOfTwo(number);
}

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::SetEvaluatedPowerOfTwo(int number)
{
	evaluatedPowerOfTwo = number;
}

template<class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::EvaluateHornersRule(int evalPower, vector<int> key)
{
	int length = key.size();
	int result;
	for (int i = 0; i < key.size(); i++)
	{
		if (i == 0) // this is the first run
		{
			result = keyValues[i] * evalPower;
		}
		else if (i > 0 && i < length - 1) // if it is in between the start and end
		{
			result = (result + keyValues[i]) * 32;
		}
		else // this is the last value
		{
			result = result + keyValues[i];
		}

	}
	return result;
}

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::GetASCIIValues(KeyType key)
{
	// if key is a string convert it into integer format
	for (int i = 0; i < key.length(); i++)
	{
		key[i] = tolower(key[i]);
		keyValues.push_back((key[i] - 96));
	}
}

template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary()
{
	hashTable = new HashedEntry<KeyType, ItemType>*[DEFAULT_SIZE];
	hashTableSize = DEFAULT_SIZE;
	
}

template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary(int tableSize)
{
	hashTable = new HashedEntry<KeyType, ItemType>*[tableSize];
	hashTableSize = tableSize;
	
}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::AddEntry(KeyType key, ItemType newEntry)
{
	// Create entry to add to dictionary
	HashedEntry<KeyType, ItemType>* entryToAddPtr = new HashedEntry<KeyType, ItemType>(newEntry, key);

	// Computer the hashed index into the array
	int itemHashIndex = GetHashIndex(key);

	// Add the entry to the chain at itemHashIndex
	if (hashTable[itemHashIndex] == nullptr)
	{
		hashTable[itemHashIndex] = entryToAddPtr;
	}
	else
	{
		entryToAddPtr->SetNext(hashTable[itemHashIndex]);
		hashTable[itemHashIndex] = entryToAddPtr;
	}
	return true;
}

template<class KeyType, class ItemType>
ItemType HashedDictionary<KeyType, ItemType>::GetEntry(const KeyType key)
{
	int index = GetHashIndex(key); // index in the table the key points to
	HashedEntry<KeyType, ItemType>* currentPtr = hashTable[index]; // where are we currently pointing two?

	// if we are pointing to a nullPtr then we have an invalid key
	if (currentPtr == nullptr)
	{
		return -1; // indicates a bad key
	}
	else if (currentPtr->GetKey() == key)
	{
		return currentPtr->GetItem(); // we found the item with the given key
	}
	else
	{
		// check the next item in the chain
		currentPtr = currentPtr->GetNext();
		GetEntry(key);
	}
}

template<class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::GetHashIndex(KeyType key)
{
	int power = 0; // power of two
	int tempPower; // temp power of two
	GetASCIIValues(key);

	for (int j = 0; j < keyValues.size(); j++)
	{		
		tempPower = GetPowerOfTwo(keyValues[j]);
		if (tempPower > power)
		{
			// if we have a higher power of two, set power to that number
			power = tempPower;
		}
	}		
	
	SetPowerOfTwo(power); // determine what power we will raise 2 to. 
	RaiseToPower(2, powerOfTwo); // Raise 2, to the 'powerOfTwo'

	// evaluate h(x) + x mod tableSize
	evaluatedValue = EvaluateHornersRule(evaluatedPowerOfTwo, keyValues);
	
	int index = (evaluatedValue % hashTableSize);
	keyValues.clear(); // clear keyvalues;
	

	
	return index;
}
