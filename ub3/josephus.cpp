#include <assert.h>
#include <stdio.h>

struct Node {
    int data;
    Node *next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

class CyclicLinkedList {
    Node *start;

   public:
    //Create a cyclic linked list with 'count' nodes
    //Node data are 1-based the index of the node from start
    CyclicLinkedList(int count) {
        assert(count >= 1);
        start = new Node(1);
        Node *n = start;
        for (int i = 2; i <= count; ++i) {
            Node *m = new Node(i);
            n->next = m;
            n = m;
        }
        // letzte element auf start setzen 
        n->next = start;
    }

    ~CyclicLinkedList() {
        if (start == NULL)
            return;
        Node *h = start;
        do {
            Node *n = h;
            h = h->next;
            delete n;
        } while (h != start);
    }

    //Simuliert und loest das Problem des Josephus.
    //Input:
    // k: Jedes k-te Element wird zyklisch geloescht
    // debug: Bei true wird jede Loeschoperation ausgegeben
    //Output:
    // Der Index (1-based) des ueberlebenden Elements
    int josephus(int k) {
        assert(k >= 2);
        Node *h = start;
        while (h->next != h) {  //solange noch ein anderes Element da ist
            //Loesche das k-te Element nach h (h ist das 1.)
            //1. Gehe k-2 Schritte weiter
            for (int i = 0; i < k - 2; ++i)
                h = h->next;
            //2. Loesche das naechste Element
            Node *n = h->next;
            h->next = n->next;
            printf("Entferne Element %d\n", n->data);
            delete n;
            //und gehe eins weiter
            h = h->next;
        }
        start = h;
        return h->data;
    }

    void print() {
        printf("CyclicLinkedList:");
        if (start == NULL)
            return;
        Node *h = start;
        do {
            printf(" %d", h->data);
            h = h->next;
        } while (h != start);
        printf("\n");
    }
};

void josephus(int n, int k, bool debug = false) {
    CyclicLinkedList l(n);
    if (debug) l.print();
    int result = l.josephus(k);
    if (debug) printf("Letztes Element: %d\n", result);
}

int main() {
    // Test1
    int n = 15;
    int k = 5;
    josephus(n, k, true);

    // Test2
    printf("\nSimulate!\n");
    for (int k2 = 2; k2 <= k; ++k2) {
        printf("k=%d\n", k2);
        for (int n2 = 1; n2 <= n; ++n2) {
            josephus(n2, k2, true);
        }
    }

    return 0;
}