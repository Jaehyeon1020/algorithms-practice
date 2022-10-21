#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int hashFunc_1(int k);
int hashFunc_2(int k);
int hashFunc_3(int k);

// linked list
typedef struct node {
    int data;
    struct node * next;
} Node;

// insert new Node to linked list
void insertNode(Node * head, int newData) {
    Node * currentNode = head;

    while(currentNode->next != NULL) {
        currentNode = currentNode->next;
    }

    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = newData;

    currentNode->next = newNode;
}

// hash function a
int hashFunc_1(int k) {
    return k % 5;
}

// hash function b
int hashFunc_2(int k) {
    return k % 7;
}

// hash function c
int hashFunc_3(int k) {
    return k % 13;
}

// initialize hash table
void initHashTable(Node ** hashTable, int tableSize) {    
    for(int i = 0; i < tableSize; i++) {
        hashTable[i] = (Node *)malloc(sizeof(Node)); // making head node
        hashTable[i]->next = NULL;
    }
}

// functionType 1 : call hashFunc_1
// functionType 2 : call hashFunc_2
// functionType 3 : call hashFunc_3
void insertToHashTable(int key, Node ** hashTable, int functionType) {
    if(functionType == 1) {
        insertNode(hashTable[hashFunc_1(key)], key);
    }
    else if(functionType == 2) {
        insertNode(hashTable[hashFunc_2(key)], key);
    }
    else {
        insertNode(hashTable[hashFunc_3(key)], key);
    }
}

void printHashTable(Node ** hashTable, int tableSize) {
    int shortest;
    int longest;
    double average;
    int currentChainLength = 0;
    int sumChainLength = 0;
    Node * currentNode;

    for (int i = 0; i < tableSize; i++) {
        currentNode = hashTable[i];
        
        printf("   ----------\n");
        printf("%2d |        |", i);
        while(currentNode->next != NULL) {
            currentNode = currentNode->next;
            currentChainLength++;
            
            printf(" -> %d", currentNode->data);
        }
        printf("\n");

        if(i == 0) {
            shortest = currentChainLength;
            longest = currentChainLength;
        }

        if(currentChainLength < shortest)
            shortest = currentChainLength;
        if(currentChainLength > longest)
            longest = currentChainLength;
        
        sumChainLength += currentChainLength;
        currentChainLength = 0;
    }

    average = (double)sumChainLength / (double)tableSize;

    printf("   ----------\n\n");
    printf("The shortest length of the chains: %d\n", shortest);
    printf("The longest length of the chains: %d\n", longest);
    printf("Average length of the chains: %lf\n", average);
}

int main() {
    Node * hashTable_1[5];
    Node * hashTable_2[7];
    Node * hashTable_3[13];

    initHashTable(hashTable_1, 5);
    initHashTable(hashTable_2, 7);
    initHashTable(hashTable_3, 13);

    int keys[50];
    srand(time(NULL));

    for (int i = 0; i < 50; i++) {
		keys[i] = rand() % 1000;
		for (int j = 0; j < i; j++)
		{
			if (keys[i] == keys[j])
			{
				i--;
				break;
			}
		}
	}

    // insert 50 keys in table
    for (int i = 0; i < 50; i++) {
        insertToHashTable(keys[i], hashTable_1, 1);
        insertToHashTable(keys[i], hashTable_2, 2);
        insertToHashTable(keys[i], hashTable_3, 3);
    }

    // print information about each tables
    printf("===============Hash table 1===============\n");
    printHashTable(hashTable_1, 5);
    printf("==========================================\n\n");

    printf("===============Hash table 2===============\n");
    printHashTable(hashTable_2, 7);
    printf("==========================================\n\n");

    printf("===============Hash table 3===============\n");
    printHashTable(hashTable_3, 13);
    printf("==========================================\n\n");

    return 0;
}