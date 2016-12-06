#include "Entry.h"





template<class KeyType, class ItemType>
void Entry<KeyType, ItemType>::SetKey(const KeyType & key)
{
	searchKey = key;
}

template<class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry()
{
}

template<class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry(ItemType newEntry, KeyType key)
{
	item = newEntry;
	searchKey = key;
}

template<class KeyType, class ItemType>
ItemType Entry<KeyType, ItemType>::GetItem() const
{
	return item;
}

template<class KeyType, class ItemType>
KeyType Entry<KeyType, ItemType>::GetKey() const
{
	return searchKey;
}

template<class KeyType, class ItemType>
void Entry<KeyType, ItemType>::SetItem(const ItemType & newEntry)
{
	item = newEntry;
}

template<class KeyType, class ItemType>
bool Entry<KeyType, ItemType>::operator==(const Entry<KeyType, ItemType>& rightHandItem) const
{
	return (searchKey == rightHandItem.GetKey());
}

template<class KeyType, class ItemType>
bool Entry<KeyType, ItemType>::operator>(const Entry<KeyType, ItemType>& rightHandItem) const
{
	return (searchKey > rightHandItem.GetKey());
}


