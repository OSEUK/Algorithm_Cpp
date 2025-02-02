// SWEA D3 1230 암호문3

#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    Node* next;
}

constexpr size_t MAX_NODE = 4000;

int node_count = 0;
Node node_pool[MAX_NODE];

Node* new_node(int data){
    node_pool[node_count].data = data;
    node_pool[node_count].next = nullptr;
    
    return &node_pool[node_count++];
}

class LinkedList:
    Node head;
private:
    void insert(Node* node, int data){
        Node* newNode = new_node(data);

        newNode->next = node->next;
        node->next = newNode;
    }
public:
    LinkedList() {
        head.next = nullptr;
        node_count = 0;
    }

    void insert(int n, int data){
        Node* newNode = new_node(data);
        
        
    }
    
    
    

int main(void){

}