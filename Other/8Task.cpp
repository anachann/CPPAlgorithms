#include <iostream>
#include <list>

using namespace std;

template <typename T>
struct Node 
{
    T data;
    Node* next;
};
template <typename T>
Node<T>* arrayToList(const T arr[], size_t size)
{
    if (size == 0) return nullptr;

    Node<T>* head = new Node<T>{arr[0], nullptr};
    Node<T>* current = head;

    for (size_t i = 1; i < size; ++i) {
        current->next = new Node<T>{arr[i], nullptr};
        current = current->next;
    }

    return head; 
}

template <typename T, typename Pred>
void removeBad(Node<T>*& head, Pred p)
{
    while (head != nullptr && p(head->data)) 
    {
        Node<T>* temp = head;
        head = head->next;
        cout << "DEL " << temp->data << " ";
        delete temp;
    }

    Node<T>* current = head;
    while (current != nullptr && current->next != nullptr) 
    {
        if (p(current->next->data)) 
        {
            Node<T>* temp = current->next;
            current->next = current->next->next;
            cout << "DEL " << temp->data << " ";
            delete temp;
        } 
        else 
        {
            current = current->next;
        }
    }
    cout << endl;
}

template <typename T>
void showList(const Node<T>* head)
{
    if(head == nullptr) cout << "Empty list" << endl;
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

template <typename T>
void deleteList(Node<T>*& head)
{
    {
    while (head != nullptr) 
    {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}
}

int main() 
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    size_t size = std::size(arr);
    Node<int>* head = arrayToList(arr,size);
    showList(head);
    removeBad(head, [](int n) {return n%2 != 0;});
    showList(head);
    removeBad(head, [](int n) {return n < 5;});
    showList(head);
    removeBad(head, [](int n) {return n > 9;});
    showList(head);
    deleteList(head);
    showList(head);
}