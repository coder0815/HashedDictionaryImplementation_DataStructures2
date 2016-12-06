#include "HashedEntry.h"


template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry()
{
}

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(ItemType newEntry, KeyType key)
{
	this->SetItem(newEntry);
	this->SetKey(key);
}

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(ItemType newentry, KeyType key, HashedEntry<KeyType, ItemType>* nextEntryPtr)
{
	this->SetItem(newEntry);
	this->SetKey(key);
	this->SetNext(nextEntryPtr);
}

template<class KeyType, class ItemType>
void HashedEntry<KeyType, ItemType>::SetNext(HashedEntry<KeyType, ItemType>* nextEntryPtr)
{
	nextPtr = nextEntryPtr;
}

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>* HashedEntry<KeyType, ItemType>::GetNext() const
{
	return nextPtr;
}





