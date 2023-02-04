//
// Created by Alvaro Flores-Romero
//      Version: C++17
//

#include <iostream>

// Define the structure of a Node with a structure
struct Node
{
    int data;
    Node* next; // to link next node
};

int numberElements(Node*** pointerToHead){
    Node* iter = **pointerToHead;
    int number_elements{};
    while(iter != NULL) {
        number_elements++;
        iter = iter -> next;
    }
    return number_elements;
}

// Insert Node Beginning
void insertNode(int value, int position, Node** pointerToHead){
    // Get number of elements
    int numElements = numberElements(&pointerToHead);

    // Proceed if the position is valid
    if(position <= numElements){
        // Temp node to Store Values to Add
        Node* newNode =  new Node;
        newNode->data = value;
        newNode->next = NULL; // Initialize NULL

        // Case: Insert at the beginning
        if(position == 0){
            // Create Link
            newNode->next = *pointerToHead;
            // Header Becomes Temp Node
            *pointerToHead = newNode;
        }
        // Case: Insert at any other valid position
        else{
            Node* previousNodeToOldNode =  *pointerToHead;
            // Travel through nodes until the desired position - 1 (previous nod
            for(int i{0}; i < position-1;i++){
                previousNodeToOldNode = previousNodeToOldNode->next;
            }
            // Next node of new node is the oldNode
            newNode->next = previousNodeToOldNode->next;
            previousNodeToOldNode->next = newNode;

        }


    } else {
        printf("Error. Position %d out of bounds. We have %d Nodes.\n", position, numElements);
    }


}

void deleteNode(int position, Node** pointerToHead){

    // Get number of elements
    int numElements = numberElements(&pointerToHead);

    // Proceed if the position is valid
    if(position <= numElements){
        // Get Node before the one we want to Delete
        Node* previousNode =  *pointerToHead;
        for(int i{0}; i < position-1;i++){
            previousNode = previousNode->next;
        }
        // Get Node to Delete
        Node* nodeToDelete =  previousNode->next;

        // Link pervious Node to the node after the one we want to delete
        previousNode->next = nodeToDelete->next;

        // Delete Heap Memory allocation
        delete(nodeToDelete);

    } else{
        printf("Error. Position %d out of bounds. We have %d Nodes.\n", position, numElements);
    }
}


void printAllNodes(Node* head){
    printf("List is: \n");
    while(head != NULL){
        printf("Node Data: %d\n",head->data);
        head = head -> next;
    }
}

int main(){

    // Initialize head
    struct Node* head{NULL};

    // Insert Value (first argument) and position (second argument)
    // Position starts at 0
    insertNode(2,0, &head); // List: 2
    insertNode(3,1, &head); // List: 2,3
    insertNode(4,0, &head); // List: 4, 2, 3
    insertNode(5,1, &head); // List: 4, 5, 2, 3
    insertNode(69,10, &head); // Error - Position Out. No modification. List: 4, 5, 2, 3
    deleteNode(2, &head); // List: 4, 5, 3
    deleteNode(2, &head); // List: 4, 5
    printAllNodes(head);

}