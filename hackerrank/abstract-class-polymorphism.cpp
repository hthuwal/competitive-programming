// https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val) : prev(p), next(n), key(k), value(val){};
    Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache {
   protected:
    map<int, Node*> mp;              // map the key to the node in the linked list
    int cp;                          // capacity
    Node* tail;                      // double linked list tail pointer
    Node* head;                      // double linked list head pointer
    virtual void set(int, int) = 0;  // set function
    virtual int get(int) = 0;        // get function
};

class LRUCache : public Cache {
   private:
    int numEntries;

    Node* getNode(int key) {
        if (mp.find(key) == mp.end()) {
            return NULL;
        }

        Node* target = mp[key];
        if (target == tail) {
            return target;
        }

        if (target == head) {
            head = target->next;
            head->prev = NULL;
            tail->next = target;
            target->prev = tail;
            target->next = NULL;
            tail = target;
            return target;
        }

        target->prev->next = target->next;
        target->next->prev = target->prev;
        tail->next = target;
        target->prev = tail;
        target->next = NULL;
        tail = target;
        return target;
    }

   public:
    void Print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->key << ":" << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    LRUCache(int capacity) {
        this->cp = capacity;
        tail = NULL;
        head = NULL;
        numEntries = 0;
    }

    void set(int key, int value) {
        Node* node = getNode(key);
        if (node != NULL) {
            node->value = value;
            return;
        }

        node = new Node(key, value);
        if (head == NULL) {
            tail = node;
            head = node;
            mp[key] = node;
            numEntries++;
            return;
        }

        node->prev = tail;
        tail->next = node;
        tail = node;
        mp[key] = node;
        numEntries++;

        if (numEntries > cp) {
            Node* old_head = head;
            head = head->next;
            head->prev = NULL;
            mp.erase(old_head->key);
            delete old_head;
            numEntries--;
        }
        return;
    }

    int get(int key) {
        Node* target = getNode(key);
        if (target == NULL) {
            return -1;
        }
        return target->value;
    }
};

int main() {
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        } else if (command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}
