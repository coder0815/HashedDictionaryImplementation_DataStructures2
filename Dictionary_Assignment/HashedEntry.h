#pragma once
#include "Entry.h"
template <class KeyType, class ItemType>
class HashedEntry :	public Entry<KeyType, ItemType>
{
private:
	HashedEntry<KeyType, ItemType>* nextPtr;
public:
	HashedEntry();
	HashedEntry(ItemType newEntry, KeyType key);
	HashedEntry(ItemType newentry, KeyType key, HashedEntry<KeyType, ItemType>* nextEntryPtr);
	void SetNext(HashedEntry<KeyType, ItemType>* nextEntryPtr);
	HashedEntry<KeyType, ItemType>* GetNext() const;
	
};
#include "HashedEntry.cpp"


