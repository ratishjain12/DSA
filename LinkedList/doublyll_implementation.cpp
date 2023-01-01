class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        prev = NULL;
        next = NULL;
        data = 0;
    }
    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
}

class dll
{
    Node *head;

public:
    dll() { head = NULL }

    void insertFront(int x)
    {
        Node *newNode = new Node(x);
        NewNode->next = head;
        newNode->prev = NULL;
        if (head != NULL)
        {
            head->prev = newNode;
        }
        head = newNode;
    }

    void insertAfter(Node *prevNode, int x)
    {
        if (prevNode == NULL)
        {
            cout << "previous cant be null";
            return;
        }
        Node *newNode = new Node(x);
        newNode->prev = prevNode;
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        if (newNode->next != NULL)
        {
            newNode->next->prev = newNode;
        }
    }
    void insertEnd(int x)
    {
        Node *newNode = new Node(x);
        newNode->next = NULL;
        Node *last = head;
        if (head == NULL)
        {
            newNode->prev = NULL;
            head = newNode;
            return;
        }
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
    }
    void deleteNode(Node *delNode)
    {
        if (head == NULL || delNode == NULL)
        {
            return;
        }
        if (head == delNode)
        { // del first node;
            head = delNode->next;
        }
        if (delNode->next != NULL)
        {
            delNode->next->prev = delNode->prev;
        }
        if (delNode->prev != NULL)
        {
            delNode->prev->next = delNode->next;
        }
        delete delNode;
    }

    void display(Node *node)
    { // displays a list after a given node
        Node *last;

        // forward direction
        while (node != NULL)
        {
            cout << node->data << "<==>";
            last = node;
            node = node->next;
        }
        // backward direction
        while (last != NULL)
        {
            cout << last->data << "<==>";
            last = last->prev;
        }
    }
}