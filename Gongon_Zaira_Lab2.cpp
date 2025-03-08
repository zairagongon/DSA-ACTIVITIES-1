#include <iostream>

using namespace std;

typedef struct Node{
    string songName;
    Node *link;
}Node;

Node *createNode(string data){
    Node *newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;
    
    return newNode;
}

void traverse(Node *head){
    Node *temp = new Node;
    temp = head;
    cout << endl;
    
    cout << "My Playlist" << endl;
    while(temp != NULL){
        cout << temp->songName << "->" << endl;
        if(temp->link == NULL){
            cout << "NULL" << endl;
        }
        
        temp = temp->link;
    }
}

Node *insertAtEnd(string data, Node *head){
    if(head == NULL){
        Node *newNode = createNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end" << endl;
        return head;
    }
    Node *temp = new Node;
    temp = head;
    
    while(temp->link != NULL){
        temp = temp->link;
    }
    
    Node *newNode = createNode(data);
    temp->link = newNode;
    
    cout << "A new node has been inserted at the end" << endl;
    return head;
}

Node *insertAtBeginning(string data, Node *head){
    Node *newNode = createNode(data);
    newNode->link = head;
    
    head = newNode;
    
    cout << "A new node has been inserted at the beginning" << endl;
    
    return head;
}

string insertAfter(string after, string data, Node *head){
    Node *temp = new Node;
    temp = head;
    
    while(temp->songName.compare(after) != 0){
        if(temp == NULL){
            return "No such song exist, please try again later.";
        }
        
        temp = temp->link;
    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;
    
    return "An node has been added after " + after + "\n";
}

string deleteAtEnd(Node *head){
    if(head == NULL){
        return "The linked list is empty \n";
    }
    
    if(head->link == NULL){
        delete head;
        return "The head ahs been deleted \n";
    }
    
    Node *temp = new Node;
    temp = head;
    
    while(temp->link->link != NULL){
        temp = temp->link;
    }
    
    temp->link = NULL;
    
    return "A new node has been deleted at the end \n";
}

Node *deleteFromBeginning(Node *head){
    if(head == NULL){
        cout << "The linked list is empty" << endl;
        return NULL;
    }
    
    if(head->link == NULL){
        delete head;
    }
    
    head = head->link;
    
    cout << "A node has been delete from the beginnning" << endl;
    
    return head;
}

Node *deleteFromGivenNode(string givenNode, Node *head){
    if(head == NULL){
        cout << "The linked list is empty." << endl;
        return NULL;
    }
    
    if(head->songName.compare(givenNode) == 0){
        head = deleteFromBeginning(head);
        cout << "The Node" + givenNode + "has been deleted." << endl;
        return head;
    }
    
    Node *temp = new Node;
    Node *next = new Node;
    temp = head;
    next = temp->link;
    
    while(next->songName.compare(givenNode) != 0){
        if(temp == NULL){
            cout << "No such node exist." << endl;
            return head;
        }
        next = next->link;
        temp = temp->link;
    }
    
    temp->link = next->link;
    cout << "The Node " + givenNode + " has been deleted." << endl;
    return head;
    
}

int main(){

    Node *head = createNode("Sanctuary by Joji");
    traverse(head);
    head = insertAtEnd("Sunday Morning by Maroon 5", head);
    traverse(head);
    head = insertAtEnd("Sol at Luna by Geiko", head);
    traverse(head);
    head = insertAtBeginning("huling uyayi ko, sinta by Ian Quiruz", head);
    traverse(head);
    head = insertAtBeginning("Hayaan by Cup of Joe", head);
    traverse(head);
    cout << insertAfter("Sunday Morning by Maroon 5", "Heaven Knows by Orange and Lemon", head);
    traverse(head);
    head = insertAtEnd("Just the way you are by Bruno Mars", head);
    traverse(head);
    cout << insertAfter("Sanctuary by Joji", "Sol at Luna by Geiko", head);
    traverse(head);
    head = insertAtEnd("Little bit more by Suriel Hess", head);
    traverse(head);
    head = deleteFromBeginning(head);
    traverse(head);
    cout << deleteAtEnd(head);
    traverse(head);
    head = deleteFromGivenNode("Sunday Morning by Maroon 5", head);
    traverse(head);


    return 0;
}