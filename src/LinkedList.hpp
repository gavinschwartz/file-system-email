#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <fstream>

using namespace std;

template <typename Data>
class LinkedListNode
{
public:
    Data data;
    LinkedListNode<Data> *next;

    LinkedListNode()
    {
        next = nullptr;
    }
};

template <typename Data>
class LinkedList
{

public:
    LinkedListNode<Data> *head;
    LinkedListNode<Data> *tail;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    int getLength()
    {
        LinkedListNode<Data> *currentNode = head;
        int count = 0;
        while (currentNode != nullptr) // Traverse the list until the end
        {
            count++;                         // Increment count for each node
            currentNode = currentNode->next; // Move to the next node
        }
        return count; // Return the total count of nodes
    }

    void add(Data newData)
    {
        LinkedListNode<Data> *newNode = new LinkedListNode<Data>; // Create a new node
        newNode->data = newData;                                  // Set the post in the new node
        if (tail != nullptr)
        {
            tail->next = newNode; // Link the current tail to the new node
        }
        tail = newNode; // Update the tail to the new node

        if (head == nullptr) // If the list was empty
        {
            head = newNode; // Set the head to the new node
        }
    }

    void remove(int index)
    {
        if (index < 0 || index >= getLength()) // Check if index is valid
        {
            cout << "Invalid index!" << endl
                 << endl; // Print error message if invalid
            return;       // Exit the function
        }
        LinkedListNode<Data> *nodeToDelete;
        LinkedListNode<Data> *previousNode;

        if (index == 0)
        {
            previousNode = nullptr;
            nodeToDelete = head;
            head = nodeToDelete->next; // Update the head pointer
        }
        else
        {
            previousNode = head;                // Start searching with the head of the list
            for (int i = 0; i < index - 1; i++) // Traverse to the node before the one to delete
            {
                previousNode = previousNode->next; // Move to the next node
            }
            nodeToDelete = previousNode->next;       // The node to delete
            previousNode->next = nodeToDelete->next; // Link previous node to the node after the one to delete
        }

        if (tail == nodeToDelete) // If the tail is the node to delete
        {
            tail = previousNode; // Update the tail
        }

        delete nodeToDelete; // Delete the node
        cout << "Successfully deleted index number " << index << "." << endl
             << endl;
    }

    void print()
    {
        LinkedListNode<Data> *currentNode = head; // Start with the head of the list
        int printIndex = 0;
        while (currentNode != nullptr) // Traverse the list until the end
        {
            Data currentData = currentNode->data;
            cout << printIndex << ": " << endl;
            cout << currentData.toString() << endl; // Get the current post
            currentNode = currentNode->next;
            printIndex++;
        }
    }

    void savetoFile(fstream &outputFile, int skip)
    {
        LinkedListNode<Data> *currentNode = head; // Start with the head of the list
        for (int i = 0; i < skip; i++)
        {
            currentNode = currentNode->next;
        }

        outputFile << (getLength() - skip) << endl; // Write the number of posts

        while (currentNode != nullptr) // Traverse the list until the end
        {
            Data currentData = currentNode->data; // Get the current post

            currentData.saveToFile(outputFile);
            currentNode = currentNode->next;
        }

        outputFile.close(); // Close the file
        cout << "Successfully saved!" << endl;
    }
};

#endif