// design the class in the most optimal way
class Node
{
public:
    int key, val;
    Node *next;
    Node *prev;

    Node(int _key, int _val)
    {
        key = _key;
        val = _val;
    }
};
class LRUCache
{
public:
    Node *head = new Node(-1, -1); // DUMMY VALUE ASSIGNED
    Node *tail = new Node(-1, -1);

    int capacity;
    unordered_map<int, Node *> m;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // T.C :- O(1) [ONLY LINK CHANGED]
    void addNode(Node *newnode) // adds node to head->next
    {
        Node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    // T.C :- O(1) [ONLY LINK CHANGED]
    void deleteNode(Node *delNode)
    {
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    // T.C :- O(1)
    int GET(int key)
    {
        if (m.find(key) != m.end())
        {
            Node *curr = m[key];
            int value = curr->val;

            // 1. DELETE FROM CACHE
            deleteNode(curr);

            // 2. INSERT IN CACHE RIGHT AFTER HEAD
            addNode(curr);

            // 3. UPDATE CURRENT ADDRESS [ head->next ] OF KEY IN HASH-MAP
            m[key] = head->next;

            return value;
        }
        return -1; // WHEN KEY NOT PRESENT
    }

    // T.C :- O(1)
    void SET(int key, int value)
    {
        // IF ALREADY EXIST IN CACHE :- DELETE AND INSERT AS MOST RECENTLY USED [WITH NEW ADDRESS]
        if (m.find(key) != m.end())
        {
            Node *existingNode = m[key];
            m.erase(key); // erase from hash-map previous address of node
            deleteNode(existingNode);
        }

        // IF CACHE CAPACITY IS FULL DELETENODE
        if (m.size() == capacity)
        {
            // DELETE LEAST RECENTLY USED WHICH EXIST BEFORE TAIL I.E PREVIOUS NODE TO TAIL
            m.erase(tail->prev->key); // erase from hash-map previous address of node
            deleteNode(tail->prev);
        }

        // NOW INSERT IN CACHE RIGHT AFTER HEAD
        addNode(new Node(key, value));

        // UPDATE CURRENT ADDRESS [ head->next ] OF KEY IN HASH-MAP
        m[key] = head->next;
    }
};