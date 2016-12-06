#include "HashedDictionary.h"




template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::ConvertToBinary(int num)
{
	if (num > 0)
	{
		int result = num % 2;
		num = num / 2;
		binaryNumbers.push_back(result);
		ConvertToBinary(num);
	}
	else
	{
		binary.push_back(binaryNumbers);
	}
	

}

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::SetPowerOfTwo(vector<vector<int>> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].size() > powerOfTwo)
		{
			powerOfTwo = list[i].size();
		}
	}
}

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::RaiseToPower(int num, int power)
{
	for (int i = 0; i < power; i++)
	{
		num *= num;
	}
	evaluatedPowerOfTwo = num;
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
HashedDictionary<KeyType, ItemType>::HashedDictionary()
{
	hashTable = new HashedEntry<KeyType, ItemType>*[DEFAULT_SIZE];
	hashTableSize = DEFAULT_SIZE;
	
}

template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary(int tableSize)
{
	hashTable = new HashedEntry<KeyType, ItemType>*0[tableSize];
	
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
	// if key is a string convert it into integer format
	for (int i = 0; i < key.length(); i++)
	{
		key[i] = tolower(key[i]);
		switch (key[i])
		{
		case 'a':
		{
			keyValues.push_back(1);
			break;
		}
		case 'b':
		{
			keyValues.push_back(2);
			break;
		}
		case 'c':
		{
			keyValues.push_back(3);
			break;
		}
		case 'd':
		{
			keyValues.push_back(4);
			break;
		}
		case 'e':
		{
			keyValues.push_back(5);
			break;
		}
		case 'f':
		{
			keyValues.push_back(6);
			break;
		}
		case 'g':
		{
			keyValues.push_back(7);
			break;
		}
		case 'h':
		{
			keyValues.push_back(8);
			break;
		}
		case 'i':
		{
			keyValues.push_back(9);
			break;
		}
		case 'j':
		{
			keyValues.push_back(10);
			break;
		}
		case 'k':
		{
			keyValues.push_back(11);
			break;
		}
		case 'l':
		{
			keyValues.push_back(12);
			break;
		}
		case 'm':
		{
			keyValues.push_back(13);
			break;
		}
		case 'n':
		{
			keyValues.push_back(14);
			break;
		}
		case 'o':
		{
			keyValues.push_back(15);
			break;
		}
		case 'p':
		{
			keyValues.push_back(16);
			break;
		}
		case 'q':
		{
			keyValues.push_back(17);
			break;
		}
		case 'r':
		{
			keyValues.push_back(18);
			break;
		}
		case 's':
		{
			keyValues.push_back(19);
			break;
		}
		case 't':
		{
			keyValues.push_back(20);
			break;
		}
		case 'u':
		{
			keyValues.push_back(21);
			break;
		}
		case 'v':
		{
			keyValues.push_back(22);
			break;
		}
		case 'w':
		{
			keyValues.push_back(23);
			break;
		}
		case 'x':
		{
			keyValues.push_back(24);
			break;
		}
		case 'y':
		{
			keyValues.push_back(25);
			break;
		}
		case 'z':
		{
			keyValues.push_back(26);
			break;
		}
		}
	}

	for (int j = 0; j < keyValues.size(); j++)
	{
		ConvertToBinary(keyValues[j]);
		binaryNumbers.clear();
	}		
	SetPowerOfTwo(binary); // determine what power we will raise 2 to. 
	RaiseToPower(2, powerOfTwo); // Raise 2, to the 'powerOfTwo'

	// evaluate h(x) + x mod tableSize
	evaluatedValue = EvaluateHornersRule(evaluatedPowerOfTwo, keyValues);
	
	int index = (evaluatedValue % hashTableSize);
	keyValues.clear(); // clear keyvalues;
	binary.clear(); // clear binary;
	binaryNumbers.clear(); // clear binarynumbers;

	
	return index;
}
