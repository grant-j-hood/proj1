// Created by Frank M. Carrano and Timothy M. Henry.
// Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
// Implementation file for the class ArrayBag.

#include "ArrayBag.h"
#include <cstddef>

template<class ItemType>
ArrayBag<ItemType>::ArrayBag() :
    itemCount(0),
    maxItems(DEFAULT_CAPACITY)
{
}

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(const ItemType arr[], int size) {
    itemCount(0);
    
    for (int i = 0; i < 6; i++) {
        items[i] = arr[i];
    }
}

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
    return itemCount;
}

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
    bool hasRoomToAdd = (itemCount < maxItems);
    if (hasRoomToAdd)
    {
        items[itemCount] = newEntry;
        itemCount++;
    }

    return hasRoomToAdd;
}

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
    int locatedIndex = getIndexOf(anEntry);
    bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
    if (canRemoveItem)
    {
        itemCount--;
        items[locatedIndex] = items[itemCount];
    }

    return canRemoveItem;
}

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
    itemCount = 0;
}

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
    int frequency = 0;
    int curIndex = 0;       // Current array index
    while (curIndex < itemCount)
    {
        if (items[curIndex] == anEntry)
        {
            frequency++;
        }

        curIndex++; // Increment to next entry
    }

    return frequency;
}

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
    return getIndexOf(anEntry) > -1;
}

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
    std::vector<ItemType> bagContents;
    for (int i = 0; i < itemCount; i++)
        bagContents.push_back(items[i]);

    return bagContents;
}

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
    bool found = false;
    int result = -1;
    int searchIndex = 0;

    // If the bag is empty, itemCount is zero, so loop is skipped
    while (!found && (searchIndex < itemCount))
    {
        if (items[searchIndex] == target)
        {
            found = true;
            result = searchIndex;
        }
        else
        {
            searchIndex++;
        }
    }

    return result;
}

template<class ItemType>
bool ArrayBag<ItemType>::flatten()
{
    ArrayBag<ItemType> tempBag;

    bool changed{ false };

    for (int i = 0; i < itemCount; i++) {
        ItemType check = items[i];

        if (!tempBag.contains(check)) {
            tempBag.add(check);
        }
        if (tempBag.contains(check)) {
            changed = true;
        }
    }


    *this = tempBag;

    return changed;
}
template<class ItemType>
bool ArrayBag<ItemType>::reduce()
{
    if (isEmpty()) {
        return false; // Bag will only NOT change if it is empty
    }

    int minFrequency = getFrequencyOf(items[0]); //initialize smallest freq to the first item
    ItemType iRemove = items[0]; //index of item with the minimum frequency 

    // Find the item with the smallest frequency
    
    // Start of ChatGPT - "create a for loop that checks if the current items frequency is less then the minimum, if it is swap
    for (int i = 0; i < itemCount; i++) {
        ItemType check = items[i];
        int currFrequency = getFrequencyOf(check);

        if (currFrequency < minFrequency) {
            minFrequency = currentFrequency;
            iRemove = check;
        }
    }
    //END Of ChatGPT Prompt, modified to use ItemType and relevant identifiers

    // Remove all occurrences of the item with the smallest frequency
    while (contains(iRemove)) { //iterates through till all instances of the min are gone
        remove(iRemove);
    }

    //removes whichever min was found last
    return true; // Items were removed
}

template<class ItemType>
bool ArrayBag<ItemType>::replace(const ItemType& anEntry, const ItemType& newEntry)
{
    bool containsEntry = false;
    for (int i = 0; i < itemCount; i++) {
        if (items[i] == anEntry) {
            items[i] = newEntry;
            containsEntry = true;
        }
    }

 
    return containsEntry;
}



template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::bagUnion(const ArrayBag<ItemType>& bag2) const
{
    ArrayBag<ItemType> baggageOfTheUnion;

    for (int i = 0; i < itemCount; i++) {
        baggageOfTheUnion.add(items[i]);
        baggageOfTheUnion.add(bag2.items[i]);

    }

    return baggageOfTheUnion

}