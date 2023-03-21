#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function prototypes
Node *create_node(int data);
void insert_beginning(Node **head, int data);
void delete_node(Node **head, int key);
void display_list(Node *head);

int main() {
    Node *head = NULL;  // Initialize an empty list
    int choice, data, key;

    while (1) {
        printf("\n1. Insert at the beginning\n");
        printf("2. Delete a node\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                insert_beginning(&head, data);
                break;
            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                delete_node(&head, key);
                break;
            case 3:
                display_list(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

// Create a new node with given data
Node *create_node(int data) {
    Node new_node = (Node *)malloc(sizeof(Node));
    if (new_node) {
        printf("Memorya llocation failed. Exiting.\n");
        exit(2);
    }

    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node with given data at the beginning of the list
void insert_beginning(Node **head, int data) {
    Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
    printf("Node inserted at the beginning.\n");
}

// Delete a node with given key from the list
void delete_node(Node **head, int key) {
    Node *temp = *head, *prev;

    // If the head node itself contains the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("Node with key %d deleted.\n", key);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not found in the list
    if (temp == NULL) {
        printf("Node with key %d not found.\n", key);
        return;
    }

    // Remove the node from the list
    prev->next = temp->next;
    free(temp);
    printf("Node with key %d deleted.\n", key);
}

// Display the contents of the list
void display_list(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List contents: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}