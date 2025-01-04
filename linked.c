#include <stdio.h>
#include <stdlib.h>

// Definition of the doubly linked list node
typedef struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
} Node;

// Function to create a new node
Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

// Function to print the list
void printList(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Function to reverse the list iteratively
Node *reverseListIterative(Node *head) {
  Node *current = head;
  Node *temp = NULL;

  while (current != NULL) {
    // Swap next and prev
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;

    // Move to the next node in the original list
    current = current->prev;
  }

  // Update the head to the new front
  if (temp != NULL) {
    head = temp->prev;
  }
  return head;
}

// Function to reverse the list recursively
Node *reverseListRecursive(Node *head) {
  // Base case: empty list or single node
  if (head == NULL || head->next == NULL) {
    return head;
  }

  // Recursive call
  Node *newHead = reverseListRecursive(head->next);

  // Reverse the links
  head->next->next = head;
  head->prev = head->next;
  head->next = NULL;

  return newHead;
}

// Main function to test the code
int main() {
  // Creating a sample doubly linked list
  Node *head = createNode(1);
  head->next = createNode(2);
  head->next->prev = head;
  head->next->next = createNode(3);
  head->next->next->prev = head->next;
  head->next->next->next = createNode(4);
  head->next->next->next->prev = head->next->next;

  printf("Original list: ");
  printList(head);

  // Reverse iteratively
  head = reverseListIterative(head);
  printf("Reversed list (iterative): ");
  printList(head);

  // Reverse recursively
  head = reverseListRecursive(head);
  printf("Reversed list (recursive): ");
  printList(head);

  return 0;
}