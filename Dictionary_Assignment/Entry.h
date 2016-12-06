#pragma once
template<class KeyType, class ItemType>
class Entry
{
private:
	ItemType item;
	KeyType searchKey;

protected:
	void SetKey(const KeyType& key);

public:
	Entry();
	Entry(ItemType newEntry, KeyType key);
	ItemType GetItem() const;
	KeyType GetKey() const;
	void SetItem(const ItemType& newEntry);

	bool operator==(const Entry<KeyType, ItemType>& rightHandItem) const;
	bool operator>(const Entry<KeyType, ItemType>& rightHandItem) const;
};
#include "Entry.cpp"

