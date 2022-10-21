#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TABLE_SIZE 37

// define struct hash table
typedef struct _HashTable {
    int table[TABLE_SIZE];
    int totalProbing;
    int primaryClusterLen;
} HashTable;

// sub hash function : h'(k)
int subHashFunc(int k) {
    return k % TABLE_SIZE;
}

// linear probing hash function
// h(k, i) = (h'(k) + i) mod m
int hashFunc_1(int k, int i) {
    return (subHashFunc(k) + i) % TABLE_SIZE;
}

// quadratic probing hash function
// h(k, i) = (h'(k) + c1*i + c2*i*i) mod m (c1 = 1, c2 = 3)
int hashFunc_2(int k, int i) {
    int c1 = 1;
    int c2 = 3;

    return (subHashFunc(k) + (c1 * i) + (c2 * i * i)) % TABLE_SIZE;
}

// double hashing hash function
// h(k, i) = (h1(k) + i*h2(k)) mod m
// h1(k) = k mod m, k2(k) = 1 + (k mod (m-1))
int hashFunc_3(int k, int i) {
    int h1 = k % TABLE_SIZE; // result of h1(k)
    int h2 = 1 + (k % (TABLE_SIZE - 1)); // result of h2(k)

    return (h1 + (i * h2)) % TABLE_SIZE;
}

void linearProbing(HashTable * hashTable, int key) {
    int tableIndex;

    for(int i = 0; i < TABLE_SIZE; i++) {
        hashTable->totalProbing += 1;
        tableIndex = hashFunc_1(key, i);

        // if this position is empty : insert key there
        if(hashTable->table[tableIndex] == -1) {
            hashTable->table[tableIndex] = key;
            return;
        }
    }
}

void quadraticProbing(HashTable * hashTable, int key) {
    int tableIndex;

    for(int i = 0; i < TABLE_SIZE; i++) {
        hashTable->totalProbing += 1;
        tableIndex = hashFunc_2(key, i);

        // if this position is empty : insert key there
        if(hashTable->table[tableIndex] == -1) {
            hashTable->table[tableIndex] = key;
            return;
        }
    }
}

void doubleHashing(HashTable * hashTable, int key) {
    int tableIndex;

    for(int i = 0; i < TABLE_SIZE; i++) {
        hashTable->totalProbing += 1;
        tableIndex = hashFunc_3(key, i);

        // if this position is empty : insert key there
        if(hashTable->table[tableIndex] == -1) {
            hashTable->table[tableIndex] = key;
            return;
        }
    }
}

// if hashFuncType == 1 : do linear probing
// if hashFuncType == 2 : do quadratic probing
// if hashFuncType == 3 : do double hashing
void insertKeyToHashTable(int key, HashTable * hashTable, int hashFuncType) {
    if(hashFuncType == 1) {
        linearProbing(hashTable, key);
    }
    else if(hashFuncType == 2) {
        quadraticProbing(hashTable, key);
    }
    else if(hashFuncType == 3) {
        doubleHashing(hashTable, key);
    }
}

// calculate and set the primary cluster length
void setPrimaryClusterLen(HashTable * hashTable) {
    int primaryLen = 0;
    int temp = 0;

    for(int i = 0; i < TABLE_SIZE; i++) {
        // index i의 테이블이 채워져있는 경우
        if(hashTable->table[i] != -1) {
            // 첫번째칸이 채워져있음 : 바로 cluster 시작
            if(i == 0) {
                temp += 1;
            }
            // 전 칸은 비워져있는 경우 : cluster 시작
            else if(i > 0 && hashTable->table[i-1] == -1) {
                temp += 1;
            }
            // 전 칸도 채워져있는 경우 : cluster 길이 + 1
            else if(i > 0 && hashTable->table[i-1] != -1) {
                temp += 1;

                // 마지막 칸인 경우 : primaryLen 계산 하고 적용
                if(i == TABLE_SIZE - 1) {
                    if(temp > primaryLen)
                        primaryLen = temp;
                }
            }
        }
        // index i의 테이블이 채워져있지 않은 경우(-1 채워져있음)
        else {
            // 전 칸은 채워져 있는 경우 : cluster 끝남
            if(i > 0 && hashTable->table[i-1] != -1) {
                // 이번에 계산한 cluster의 길이가 기존에 계산한 cluster 길이보다 길면 교체
                if(temp > primaryLen)
                    primaryLen = temp;

                temp = 0; // temp 0으로 초기화
            }
        }
    }

    hashTable->primaryClusterLen = primaryLen;
}

// initialize hash table
void initHashTable(HashTable * hashTable) {
    hashTable->primaryClusterLen = 0;
    hashTable->totalProbing = 0;

    for(int i = 0; i < TABLE_SIZE; i++)
        hashTable->table[i] = -1;
}

// print hash table and informations
void printHashTable(HashTable * hashTable, int numKeys) {
    setPrimaryClusterLen(hashTable);
    double averageProbes = (double)hashTable->totalProbing / numKeys;

    for(int i = 0; i < TABLE_SIZE; i++) {
        printf("   -----------\n");
        
        if(hashTable->table[i] != -1)
            printf("%2d |   %3d   |\n", i, hashTable->table[i]);
        else
            printf("%2d |         |\n", i);
    }
    printf("   -----------\n\n");
    printf("The average number of probes per insertion up to now: %f\n", averageProbes);
    printf("The primary(largest) cluster length: %d\n", hashTable->primaryClusterLen);
}

int main() {
    HashTable * linearHashTable = (HashTable *)malloc(sizeof(HashTable));
    HashTable * quadraticHashTable = (HashTable *)malloc(sizeof(HashTable)); 
    HashTable * doubleHashTable = (HashTable *)malloc(sizeof(HashTable));

    initHashTable(linearHashTable);
    initHashTable(quadraticHashTable);
    initHashTable(doubleHashTable);

    // generate 30 keys randomly
    int keys[30];
    srand(time(NULL));
    for (int i = 0; i < 30; i++) {
        keys[i] = rand() % 1000;
        for (int j = 0; j < i; j++)	{
            if (keys[i] == keys[j]) {
                    i--;
                    break;
            }
        }
    }

    // insert keys to tables
    for(int i = 0; i < 30; i++) {
        insertKeyToHashTable(keys[i], linearHashTable, 1);
        insertKeyToHashTable(keys[i], quadraticHashTable, 2);
        insertKeyToHashTable(keys[i], doubleHashTable, 3);
    }

    // print tables and informations
    printf("===============HashTable 1(linear probing)===============\n");
    printHashTable(linearHashTable, 30);
    printf("=========================================================\n\n");
    
    printf("==============HashTable 2(quadratic probing)=============\n");
    printHashTable(quadraticHashTable, 30);
    printf("=========================================================\n\n");

    printf("===============HashTable 3(double hashing)===============\n");
    printHashTable(doubleHashTable, 30);
    printf("=========================================================\n");


    free(linearHashTable);
    free(quadraticHashTable);
    free(doubleHashTable);
    return 0;
}