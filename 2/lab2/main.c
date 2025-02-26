#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char key;
    struct Node *next;
} Node;

Node* createNode(char key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, char key) {
    Node* newNode = createNode(key);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head) {
    while (head) {
        printf("%c ", head->key);
        head = head->next;
    }
    printf("\n");
}

void insertionSort(Node** head) {
    if (*head == NULL || (*head)->next == NULL) return;

    Node* sorted = NULL;
    Node* current = *head;

    while (current) {
        Node* next = current->next;
        if (sorted == NULL || sorted->key >= current->key) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->key < current->key) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *head = sorted;
}

void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    Node* head = NULL;
    printf("Enter %d letters: ", n);
    for (int i = 0; i < n; i++) {
        char key;
        scanf(" %c", &key);
        if (!isalpha(key)) {
            printf("Invalid input. Only letters allowed.\n");
            i--;
            continue;
        }
        append(&head, key);
    }

    printf("Original list: ");
    printList(head);

    insertionSort(&head);

    printf("Sorted list: ");
    printList(head);

    freeList(head);
    return 0;
}
