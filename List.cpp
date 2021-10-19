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



void createList(Node*& head, int amount)
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
void printList(Node*& head)
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

Node* getLast(Node*& head)
{
    Node* last = head;
    while (last->pNext)
    {
        last = last->pNext;
    }
    return last;
}

Node* getNode(Node*& head, int pos)
{
    if (head == nullptr)
    {
        cout << endl << "List is empty";
        return nullptr;
    }

    if (pos < 0)
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
void swap(Node*& head, int pos)
{

    if (!getNode(head, pos))
        return;

    Node* lastNode = getLast(head);
    Node* posNode = getNode(head, pos);
    Node* posNode1 = getNode(head, pos - 1);

    lastNode->pNext = head;
    posNode1->pNext = nullptr;
    head = posNode;

}


void reverseList(Node*& head)
{
    //запоминаем предыдущий и текущий элемент

    //массив 3 2 1
    //ожидаемій 1 2 3

    Node* prev = nullptr;//предыдущий элемент
    Node* current = head;//текущий элемент (3)
    Node* next = head->pNext;//следующий элемент (2)
    while (current != nullptr)//текущий - 1 
    {
        head = current;
        //запоминаем следующий элемент
        next = current->pNext;
        //текущий элемент должен указывать на предыдущий
        current->pNext = prev;
        //предыдущий элемент становится текущим
        prev = current;
        current = next;

    }



}



int* expectedData()
{
    int listExpected[6];

    listExpected[0] = 3;
    listExpected[1] = 4;
    listExpected[2] = 5;
    listExpected[3] = 6;
    listExpected[4] = 1;
    listExpected[5] = 2;

    return listExpected;
}

Node* testData()
{
    Node* headTest = new Node;
    headTest->data = 6;
    headTest->pNext = nullptr;

    headTest = headTest->pushFront(5);
    headTest = headTest->pushFront(4);
    headTest = headTest->pushFront(3);
    headTest = headTest->pushFront(2);
    headTest = headTest->pushFront(1);

    return headTest;
}

bool swapTest()
{
    Node* headTest = testData();
    swap(headTest, 2);

    bool testResult = true;
    for (int i = 0; i < 6; i++)
    {
        if (getNode(headTest, i)->data != expectedData()[i])
            testResult = false;
    }


    if (testResult)
    {
        cout << endl << "Test success! " << endl;
    }
    else
    {
        cout << endl << "Test fail! " << endl;
        for (int i = 0; i < 6; i++)
        {
            cout << endl << "Data: " << getNode(headTest, i)->data << "\t Expected data: " << expectedData()[i] << endl;

        }

    }
    return testResult;
}

void removeList(Node*& head)
{
    while (head)
    {
        Node* temp = head;
        head = head->pNext;
        delete temp;
    }
    cout << "List removed" << endl;
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
    //swap(headList, 2);
    //printList(headList);

    //removeList(headList);

    reverseList(headList);
    printList(headList);
    return 0;
}
