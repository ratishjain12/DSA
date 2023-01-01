
class Node
{
public:
  int data;
  Node *next;

  Node()
  {
    data = 0;
    next = NULL;
  }
  Node(int x)
  {
    this->datadata = x;
    this->next = NULL;
  }
}

class ll
{
  Node *head;

public:
  ll(){head = NULL}

  Node *insert(int pos, int x)
  {
    Node *temp = new node(x);
    Node *curr;
    curr = head;
    if (pos == 1) // insert at first position
    {
      temp->next = head;
      return temp;
    }
    for (int i = 1; i <= pos - 2 && curr != NULL; i++) // insert anywhere
    {
      curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
  }

  Node *del(int pos)
  {
    Node *curr;
    curr = head;
    if (pos == 1) // delete first node
    {
      head = head->next;
      return head;
    }
    for (int i = 1; i <= pos - 2 && curr != NULL; i++) // delete any node
    {
      curr = curr->next;
    }
    curr->next = curr->next->next;
    return head;
  }

  void display()
  {
    Node *curr = head;
    while (curr != NULL)
    {
      cout << curr->data << " ";
      curr = curr->next;
    }
  }
}
