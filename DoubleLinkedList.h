/*
	This header file contains the DoubleLinkedList class, which contains the Node struct as well.
	The doubly linked list is intended to be a dynamic list that can have elements easily inserted
	or deleted.
*/

#pragma region Preprocessor Directives
// This file will only be included once.
#pragma once
// Allows streaming to and from the console.
#include <iostream>
#pragma endregion Preprocessor Directives

// Define the Node struct, and make it generic.
template <typename T>
struct Node
{
	// The element for this node (ie, what this list is meant to hold).
	T value;
	// A pointer to the previous Node in the double linked list.
	Node* previous = nullptr;
	// A pointer to the next Node in the doubly linked list.
	Node* next = nullptr;
	/*
		Both pointers are initialized as nullptr, and if appropriate, set to a value
		as part of the constructor.
	*/

	// Constructor for this struct.
	Node(T val, Node* prev = nullptr, Node* nxt = nullptr)
	{
		value = val;
		previous = prev;
		next = nxt;
	}

	// Destructor for this struct.
	~Node()
	{
		// Intentionally left blank.
	}
};

// Define the DoubleLinkedList class, and make it generic.
template <typename T>
class DoubleLinkedList
{
	// Declare members.
	// These members will be private.
private:
	// The current size of the list.
	int m_Size = 0;
	// A pointer to the first node in the list.
	Node<T>* m_First = nullptr;
	// A pointer to the last node in the list.
	Node<T>* m_Last = nullptr;

	//These members will be public.
public:

	// Constructor for this class taking a single item as a parameter.
	DoubleLinkedList()
	{
		// Intentionally left blank.
	}

	// Prints the list to the console, one entry per line.
	void PrintList()
	{
		// If the list is empty,
		if (m_Size == 0)
		{
			// then tell the user.
			std::cout << "\n   The list is currently empty.\n\n";
		}
		// Else, the list is not empty.
		else
		{
			// Print this to the user.
			std::cout << "\n   Printing the list. It has " << m_Size << " entries.\n";

			// Cycle through the list.
			Node<T>* currentPtr = m_First;
			for (int i = 0; i < m_Size; i++)
			{
				// If the pointer is valid,
				if (currentPtr != nullptr)
				{
					// then print the value of this node to the user.
					std::cout << "     " << currentPtr->value;
					std::cout << "\n";
					// Get the next node on the list.
					currentPtr = currentPtr->next;
				}
			}
			// Once the loop is finishes, tell the user.
			std::cout << "   Done printing the list.\n\n";
		}
	}

	// Finds the first node whose value equals the value provided.
	Node<T>* Find(T val)
	{
		// Create a pointer to the first (might be nullptr if size = 0).
		Node<T>* currentPtr = m_First;

		// Iterate through the list (if empty, will not iterate).
		for (int i = 0; i < m_Size; i++)
		{
			// If the value matches,
			if (currentPtr->value == val)
			{
				// then return that pointer.
				return currentPtr;
			}
			// Else, it did not match. Go to the next in the list.
			else
			{
				currentPtr = currentPtr->next;
			}
		}
		// Once for loop finishes, we know that the value was not found. Return nullptr.
		return nullptr;
	}

	// Insert the item, either at the specified location or at the end if not specified.
	void Insert(T newItem, int index = m_Size)
	{
		// If this is the first item going into the list,
		if (m_Size == 0)
		{
			// then create the new Node as the first and only element.
			// The node's .previous and .next will be left as null pointers.
			Node<T>* newNode = new Node<T>(newItem);
			m_First = newNode;
			m_Last = newNode;
		}
		// Else, there was already at least one element in the list.
		else
		{
			// Define references to hold the elements that will be before & after the newItem.
			Node<T>* before = nullptr;
			Node<T>* after = nullptr;
			// Create the new Node.
			Node<T>* newNode = new Node<T>(newItem);

			// Find the node at the requested index, which will be the new after, if successful.
			after = FindKth(index);
			// If a node was found there,
			if (after != nullptr)
			{
				// then place the node here.
				before = after->previous;
				// before may still be nullptr if index was 0. This is fine.

				// Set the newNode's previous/next accordingly.
				newNode->previous = before;
				newNode->next = after;

				// Point the previous and next to the newNode where appropriate.
				after->previous = newNode;
				if (before != nullptr)
				{
					before->next = newNode;
				}
				// Else, before is nullptr, meaning this newNode is the new first node in the list.
				else
				{
					m_First = newNode;
				}
			}
			// Else, no node was found there (provided index was too high).
			else
			{
				// Default to placing the new node at the end.
				before = m_Last;
				before->next = newNode;
				newNode->previous = before;
				m_Last = newNode;
			}
		}

		// Increment the count.
		m_Size++;
	}

	// Deletes the node provided, connecting its previous and next nodes as appropriate.
	void Delete(Node<T>* delNode)
	{
		// Save references to the nodes before and after this node we are deleting.
	// These might be nullptr.
		Node<T>* before = delNode->previous;
		Node<T>* after = delNode->next;

		// If before is valid,
		if (before != nullptr)
		{
			// then set up that node's next to skip the node being deleted.
			before->next = after;
		}

		// If after is valid,
		if (after != nullptr)
		{
			// then set up that node's next to skip the node being deleted.
			after->previous = before;
		}

		// Delete the delNode, then set the dangling pointer variable to NULL just to be safe.
		delete delNode;
		delNode = NULL;
		// Decrement the size counter.
		m_Size--;
	}

	// Finds and returns a pointer to the k'th node in the list (0 for first, 1 for second, etc.).
	Node<T>* FindKth(int index)
	{
		// Ensure that index is at least 0.
		index = std::max(index, 0);

		// Set up a pointer that will change every time we go through a loop.
		Node<T>* currentPtr = m_First;

		// Loop until i is >= either index or m_Size, whichever is smaller.
		for (int i = 0; i < (std::min(index, m_Size)); i++)
		{
			currentPtr = currentPtr->next;
		}

		// Return the currentPtr, which might be nullptr is the provided index was too high.
		return currentPtr;
	}

	// Returns the lowest value held by all nodes in the list. NULL if no valid nodes.
	T Minimum()
	{
		// If the list is empty,
		if (m_Size == 0)
		{
			// then return NULL.
			return NULL;
		}
		// Else, method will continue.

		// Create pointer to the first to cycle through with and a var to hold current min.
		Node<T>* currentPtr = m_First;
		T min = currentPtr->value;

		// Cycle through the linked list, starting with the second element.
		currentPtr = currentPtr->next;
		for (int i = 1; i < m_Size; i++)
		{
			// If the current pointer is valid,
			if (currentPtr != nullptr)
			{
				// then set min to the lower between itself and this pointer's value.
				min = std::min(min, currentPtr->value);
				// Go to the next element in the list.
				currentPtr = currentPtr->next;
			}
		}
		// Once loop finishes, return min.
		return min;
	}

	// Returns the highest value held by all nodes in the list. NULL if no valid nodes.
	T Maximum()
	{
		// If the list is empty,
		if (m_Size == 0)
		{
			// then return NULL.
			return NULL;
		}
		// Else, method will continue.

		// Create pointer to the first to cycle through with and a var to hold current max.
		Node<T>* currentPtr = m_First;
		T max = currentPtr->value;

		// Cycle through the linked list, starting with the second element.
		currentPtr = currentPtr->next;
		for (int i = 1; i < m_Size; i++)
		{
			// If the current pointer is valid,
			if (currentPtr != nullptr)
			{
				// then set max to the higher between itself and this pointer's value.
				max = std::max(max, currentPtr->value);
				// Go to the next element in the list.
				currentPtr = currentPtr->next;
			}
		}
		// Once loop finishes, return max.
		return max;
	}

	// Returns the m_Size member.
	int GetSize()
	{
		return m_Size;
	}
};

