// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* pNext;
    
public:
    Node* pushFront(int dataNode)
    {
        Node* newNode = new Node;
        newNode->data = dataNode;
        newNode->pNext = this;
        
        return newNode;
    }
};


void createList(Node* &head, int amount)
{
    cout << endl << "Enter " << amount << "  data: ";
    int tempData;

    for (int i = 0; i < amount; i++)
    {

        cin >> tempData;
        if (head == nullptr)
        {
            head = new Node;
            head->data = tempData;
            head->pNext = nullptr;
        }
        else
        {
            head = head->pushFront(tempData);
        }
            
    }
}

// функция printList - выводит список
void printList(Node* &head)
{
    cout << endl << "List: ";
    if (head != nullptr)
    {
        Node* currentNode = head;
        while (currentNode)
        {
            cout << currentNode->data << " ";
            currentNode = currentNode->pNext;
        }
    }
}

Node* getLast(Node* &head)
{
    Node* last = head;
    while (last->pNext)
    {
        last = last->pNext;
    }
    return last;
}

Node* getNode(Node* &head, int pos)
{
    if (head == nullptr)
    {
        cout << endl << "List is empty";
        return nullptr;
    }

    if (pos <= 0)
    {
        cout << endl << "Position that you submit < or == 0";
        return nullptr;
    }

    Node* currentNode = head;
    for (int i = 0; i < pos; ++i)
    {
        if (currentNode->pNext)
            currentNode = currentNode->pNext;
        else
        {
            cout << endl << "End of list";
            return nullptr;
        }
    }

    return currentNode;
}

// Функция swap - переписывает в начало списка его часть, начиная с заданной позиции
void swap(Node* &head, int pos)
{

    if (!getNode(head, pos))
        return;

    Node* lastNode = getLast(head);
    Node* posNode = getNode(head, pos);

    lastNode->pNext = head;
    head = posNode;
    posNode = nullptr;
   
    
}

Node* testData()
{
    Node* headTest = new Node;
    headTest->data = 5;
    headTest->pNext = nullptr;

    headTest = headTest->pushFront(4);
    headTest = headTest->pushFront(2);
    headTest = headTest->pushFront(2);
    headTest = headTest->pushFront(1);

    return headTest;
}

bool swapTest()
{
    cout << "Test ! " << endl;
    Node* headTest = testData();
    printList(headTest);
    swap(headTest, 2);

    printList(headTest);
    /*if (getNode(headTest, 1)->data == 4)
    {
        cout << endl << "Test success! " << endl;
        return true;
    }
    else
    {
        cout << endl << "Test fail! " << endl;
        return false;
    }*/
    return true;
}



int main()
{
   if (!swapTest())
        return 0;

    Node* headList = nullptr;
    int amount;

    cout << "Enter number of nodes: " << endl;
    cin >> amount;

    createList(headList, amount);

    printList(headList);
    swap(headList, 2);
    printList(headList);

    return 0;
}
