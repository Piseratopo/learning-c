#include <stdio.h>
#include <stdlib.h>

typedef int LLIST_DATA;

typedef struct s_list_elem {
    LLIST_DATA data;
    struct s_list_elem *next;
} LIST_ELEM;

typedef LIST_ELEM *LLIST;

// Llist initialization functions

typedef void (*LLCALLBACK)(LLIST_DATA, void*);

void llForEach(LLIST l, LLCALLBACK func, void* user) {
    for (; l; l = l->next) {
        func(l->data, user);
    }
}

LLIST llAdd(LLIST l, LLIST_DATA data) {
    LIST_ELEM* newElem = (LIST_ELEM*)malloc(sizeof(LIST_ELEM));
    if (!newElem) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    newElem->data = data;
    newElem->next = l;
    return newElem;
}

void llFree(LLIST l) {
    LIST_ELEM* current = l;
    while (current != NULL) {
        LIST_ELEM* next = current->next;
        free(current);
        current = next;
    }
}

void llPrint(LLIST l) {
    printf("List contents: ");
    for (LIST_ELEM* c = l; c != NULL; c = c->next) {
        printf("%d -> ", c->data);
    }
    printf("NULL\n");
}

// Convert from llist to array

int* llConvert(LLIST l, int* count) {
    int size = 0;
    for (LIST_ELEM* c = l; c != NULL; c = c->next) {
        size++;
    }

    *count = size;
    if (size == 0) {
        return NULL;
    }

    int* arr = (int*)malloc(sizeof(int) * size);
    if (!arr) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    for (LIST_ELEM* c = l; c != NULL; c = c->next) {
        arr[i++] = c->data;
    }

    return arr;
}

// Calculate mean

float llMeanIterative(LLIST l) {
    if (!l) return 0.0f;
    int sum = 0;
    int count = 0;
    for (LIST_ELEM* current = l; current != NULL; current = current->next) {
        sum += current->data;
        count++;
    }
    return (count > 0) ? (float)sum / count : 0.0f;
}

typedef struct {
    int sum;
    int count;
} MeanData;

void sumAndCountCallback(LLIST_DATA data, void* user) {
    MeanData* meanData = (MeanData*)user;
    meanData->sum += data;
    meanData->count++;
}

float llMeanForEach(LLIST l) {
    if (!l) return 0.0f;
    MeanData data = {0, 0};
    llForEach(l, sumAndCountCallback, &data);
    return (data.count > 0) ? (float)data.sum / data.count : 0.0f;
}

LIST_ELEM* llFind(LLIST l, LLIST_DATA data) {
    for (LIST_ELEM* c = l; c != NULL; c = c->next) {
        if (c->data == data) {
            return c;
        }
    }
    return NULL;
}

LLIST llListInsertAfter(LLIST l1, LLIST l2, LIST_ELEM* p) {
    if (l2 == NULL || p == NULL) {
        return l1;
    }
    LIST_ELEM* p_next = p->next;
    p->next = l2;
    LIST_ELEM* l2_last = l2;
    while (l2_last->next != NULL) {
        l2_last = l2_last->next;
    }
    l2_last->next = p_next;
    return l1;
}

int main() {
    printf("--- Phase 1: Mean Calculation ---\n");
    LLIST list1 = NULL;
    list1 = llAdd(list1, 15);
    list1 = llAdd(list1, 10);
    list1 = llAdd(list1, 5);
    list1 = llAdd(list1, 20);
    llPrint(list1);
    printf("Mean (Iterative): %.2f\n", llMeanIterative(list1));
    printf("Mean (ForEach):   %.2f\n", llMeanForEach(list1));

    printf("\n--- Phase 2: Array Conversion ---\n");
    int count = 0;
    int* arr = llConvert(list1, &count);
    if (arr) {
        printf("Converted array: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        free(arr);
    }

    printf("\n--- Phase 3: List Insertion ---\n");
    LLIST list2 = NULL;
    list2 = llAdd(list2, 98);
    list2 = llAdd(list2, 99);
    printf("Second list:\n");
    llPrint(list2);

    printf("\nInserting second list after element '10' in the first list:\n");
    LIST_ELEM* p = llFind(list1, 10);
    if (p != NULL) {
        list1 = llListInsertAfter(list1, list2, p);
        llPrint(list1);
    } else {
        printf("Element not found!\n");
        llFree(list2);
    }

    // Free the combined list (list1 now contains list2)
    llFree(list1);

    return 0;
}
