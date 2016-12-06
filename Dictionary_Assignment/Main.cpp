// Main Program File
// Micah Barnhart
// Seminar 4 - Dictionaries and Hashing


#include <iostream>
#include "Entry.h"
#include "HashedEntry.h"
#include "HashedDictionary.h"
#include <string>


using namespace std;



// Test function for entry->GetItem()
// should display value in item
// Assumption is that item is an int
// however item could be any item type and we
// could just switch the return type of the test function to get that value
// result should be the same
void GetEntryItem(Entry<int, int>* entryObject)
{
	cout << "The item for this entry is: " << endl;
	cout << entryObject->GetItem() << endl;
	cout << endl;
}

/*Test function for entry->GetKey()
this mehtod should display the key associated with the given item
for this function we are assuming it is an int type*/
void GetEntryKey(Entry<int, int>* entryObject)
{
	cout << "The key for this item is: " << endl;
	cout<< entryObject->GetKey()<< endl;
	cout << endl;
}

/* Test function for entry->SetItem()
This should set the value of the item associated with the 
entry object*/
void SetEntryItem(int item, Entry<int,int>* entryObject)
{
	entryObject->SetItem(item);
	// display item so we know it was set
	cout << "The item was set to : " << endl;
	cout << entryObject->GetItem() << endl;
	cout << endl;
}

/*Tests the operator overload ==
if the keys in first are equal to the keys in second
display that they are the same otherwise display that they are not the same*/
void AreEntriesEqual(Entry<int, int>* first, Entry<int, int>* second)
{
	if (first->GetKey() == second->GetKey())
	{
		cout << "The entries keys are the same." << endl;
		cout << endl;
	}
	else
	{
		cout << "The entries keys are not the same." << endl;
		cout << endl;
	}
}

/*Tests the operator overload >
if the keys in first are > than the keys in second than display 
that they are greater than second keys otherwise display that they are less than second's keys*/
void AreKeysGreaterThan(Entry<int, int>* first, Entry<int, int>* second)
{
	if (first->GetKey() > second->GetKey())
	{
		cout << "First's key is greater than third's." << endl;
		cout << endl;
	}
	else if (second->GetKey() > first->GetKey())
	{
		cout << "First's key is less than third's." << endl;
		cout << endl;
	}
	else
	{
		cout << "Both keys are the same." << endl;
		cout << endl;
	}
	
}
int main()
{
	// Test entries //
	HashedEntry<int, int>* first = new HashedEntry<int, int>(0, 15);
	HashedEntry<int, int>* second = new HashedEntry<int, int>(0, 15);

	// test entry for testing operator > overload
	HashedEntry<int, int>* third = new HashedEntry<int, int>(0, 5);


	// Test Setting an entry in hashedEntry //
	cout << "Test setting the items. " << endl;
	SetEntryItem(1, first);
	SetEntryItem(20, second);

	// Test GetKey from HashedEntry //
	cout << "Test getKey()" << endl;
	GetEntryKey(first);
	GetEntryKey(second);
	GetEntryKey(third);

	// Test GetItem from HashedEntry //
	cout << "Test GetItem()" << endl;
	GetEntryItem(first);
	GetEntryItem(second);


	// Test operator== overload //
	cout << "Test == operator" << endl;
	AreEntriesEqual(first, second);

	// Test operator > overload //
	cout << "Test > operator" << endl;
	AreKeysGreaterThan(first, third);

	
	HashedDictionary<string, int>* hashDictionary = new HashedDictionary<string, int>();

	// Test AddEntry //
	hashDictionary->AddEntry("Tone", 65);
	hashDictionary->AddEntry("Note", 25);
	hashDictionary->AddEntry("Land", 45);


	int number;

	// Test getEntry from hashdictionary //
	cout << "Test GetEntry from hashDictionary: " << endl;
	number = hashDictionary->GetEntry("Tone");
	cout << "The entry with the key 'Tone' is: " << number << endl;
	cout << endl;
	number = hashDictionary->GetEntry("Note");
	cout << "The entry with the key 'Note' is: " << number << endl;
	cout << endl;
	number = hashDictionary->GetEntry("Land");
	cout << "The entry with the key 'Land is: " << number << endl;
	cout << endl;

	// Test GetHashIndex //
	cout << "Test GetHashIndex from hashDictionary: " << endl;
	number = hashDictionary->GetHashIndex("Alpine");
	cout << "The hash index for 'Alpine' is: " << number << endl;
	cout << endl;
	system("pause");
	return 0;
}