#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

//***************** Cretaing the Structure for the Node************************//
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
//////////////////////////////////////////////////////////////////////////////////

//********************** Create a New List ************************************//
Node *createNewList(int elem)
{

    Node *curr = new Node(elem);
    return curr;
}
/////////////////////////////////////////////////////////////////////////////////

//************************** Inser new Node ***********************************//
Node *insertLast(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        return temp;
    }
    Node *curr;
    curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}
////////////////////////////////////////////////////////////////////////////////

//********** Insert New Node at the beginning of the List *******************//
Node *insertFirst(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        return temp;
    }
    temp->next = head;
    return temp;
}
//////////////////////////////////////////////////////////////////////////////

//****************************** print list *******************************//
void printList(Node *var)
{
    while (var != NULL)
    {

        cout << " " << var->data << " ";

        var = var->next;
    }
    cout << endl;
}
/////////////////////////////////////////////////////////////////////////////

//********************** Length of the List ******************************//
int lenOList(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        Node *temp = head;
        int len = 1;
        while (temp->next != NULL)
        {
            temp = temp->next;
            len++;
        }

        return len;
    }
}
///////////////////////////////////////////////////////////////////////////

//********************* Insert node at any position ///////////////////////
Node *InsertPosition(Node *head, int pos, int x)
{
    Node *temp = new Node(x);

    if (head == NULL)
    {
        return temp;
    }
    else if (pos == 0)
    {
        temp->next = head;
        return temp;
    }
    else if (pos <= lenOList(head))
    {
        Node *curr = head;
        while (--pos)
        {
            curr = curr->next;
        }
        Node *var;
        var = curr->next;
        curr->next = temp;
        temp->next = var;

        return head;
    }

    else
    {
        cout << "input a valid Position" << endl;
        return head;
    }
}
//////////////////////////////////////////////////////////////////////////

//************************ Delete node from the end ********************//
Node *delNode(Node *head)
{
    system("cls");
    if (head == NULL)
    {
        cout << "There is no Node in the List" << endl;
        return NULL;
    }
    else if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    else
    {
        Node *TEMP = head;
        while (TEMP->next->next != NULL)
        {
            TEMP = TEMP->next;
        }

        delete TEMP->next;
        TEMP->next = NULL;
        return head;
    }
}
//////////////////////////////////////////////////////////////////////////

//**********************  Delete Node from the beginning ****************//
Node *delFrombeg(Node *head)
{
    system("cls");

    if (head == NULL)
    {
        cout << "There is no Node in the List" << endl;
        return NULL;
    }
    else
    {
        return head->next;
    }
}
//////////////////////////////////////////////////////////////////////////////

//******************* Delete Node from any position ************************//
Node *delFromPos(Node *head, int pos)
{
    system("cls");

    if (head == NULL)
    {
        cout << "There is no Node in the List" << endl;
        return NULL;
    }
    else if (pos == 0)
    {
        head = delFrombeg(head);
        return head;
    }
    else if (pos < lenOList(head))
    {
        Node *curr = head;
        while (--pos)
        {
            curr = curr->next;
        }
        curr->next = curr->next->next;

        return head;
    }

    else
    {
        cout << "input a valid Position" << endl;
        return head;
    }
}
//////////////////////////////////////////////////////////////////////////////

//******************** Search any Node from the List ***********************//
void search(Node *head, int x)
{
    Node *temp;
    temp = head;
    bool flag = false;
    int index = 0;
    vector<int> v;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            v.push_back(index);

            flag = true;
        }

        temp = temp->next;
        index++;
    }
    if (flag == false)
        cout << x << " is not present in the list ......";
    else
    {
        cout << "The Node " << x << " at index ";
        for (int p : v)
        {
            cout << p << "  ";
        }
    }
    cout << endl;
}
////////////////////////////////////////////////////////////////////////////////

//*********************** Sort the list in Ascending order********************//
Node *sortAscending(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return head;
    }

    Node *temp = head;
    Node *curr = head->next;
    while (temp != NULL)
    {
        while (curr != NULL)
        {
            if (temp->data > curr->data)
            {
                int var = curr->data;
                curr->data = temp->data;
                temp->data = var;
            }
            curr = curr->next;
        }
        temp = temp->next;
        if (temp != NULL)
            curr = temp->next;
    }
    return head;
}
////////////////////////////////////////////////////////////////////////////////

//*********************** Sort the list in Descending order********************//
Node *sortDescending(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return head;
    }

    Node *temp = head;
    Node *curr = head->next;
    while (temp != NULL)
    {
        while (curr != NULL)
        {
            if (temp->data < curr->data)
            {
                int var = curr->data;
                curr->data = temp->data;
                temp->data = var;
            }
            curr = curr->next;
        }
        temp = temp->next;
        if (temp != NULL)
            curr = temp->next;
    }
    return head;
}
////////////////////////////////////////////////////////////////////////////////

//******************** Find the middle Node from the list **********************//
Node *findMid(Node *head)
{
    if (head == NULL)
    {
        cout << "The list is empty" << endl;
        return head;
    }

    if (lenOList(head) == 1)
    {
        cout << "The Middle Node is " << head->data << endl;
        return head;
    }

    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "The Middle Node is " << slow->data << endl;
    return head;
}
///////////////////////////////////////////////////////////////////////////////

//************** Print the nth Node from the End of the List ****************//
Node *nthFromLast(Node *head, int x)
{
    int len = lenOList(head);
    if (len < x || x <= 0)
    {
        cout << " Please , Enter a Position within Length of the List " << endl;
        return head;
    }
    else
    {
        Node *first = head;
        Node *second = head;

        while (x--)
        {
            first = first->next;
        }
        while (first != NULL)
        {
            first = first->next;
            second = second->next;
        }
        cout << "The Node is " << second->data << endl;
        return head;
    }
}
//////////////////////////////////////////////////////////////////////////////

//*************************** Reverse the List *****************************//
Node *reverseList(Node *head)
{
    if (head == NULL)
    {
        cout << "The list is empty" << endl;
        return head;
    }

    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
/////////////////////////////////////////////////////////////////////////////

//************************** Remove the Duplicate Nodes *******************//
Node *removeDuplicates(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return head;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            Node *curr = temp->next;
            temp->next = temp->next->next;
            delete (curr);
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
}

/////////////////////////////////////////////////////////////////////////////

//************** Reverse a Linked list in a group of size k ***************//
Node *reverseInK(Node *head, int k)
{
    Node *curr = head, *next = NULL, *prev = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL)
    {
        Node *rest_head = reverseInK(next, k);
        head->next = rest_head;
    }
    return prev;
}
///////////////////////////////////////////////////////////////////////////

int main()
{
    /* For Fast input , output using cin and cout as scanf and printf */

    cout << "   \t\t\t     \t    || Welcome to the Linked List Solutions ||   " << endl
         << "\t\t\tHere You can add , delete , search , insert any node from the list " << endl
         << "\t\t\t\t\t\tSo Have Fun :)" << endl;

    Node *Head = NULL;
    int x;
    do
    {
        cout << "Select One Option from Below : " << endl
             << "\t"
             << "0. For exit."
             << "\t"
             << "\t"
             << "\t"
             << "\t"
             << "\t"
             << "\t"
             << "\t"
             << "1. Create new List." << endl
             << "\t"
             << "2. Insert new Node."
             << "\t"
             << "\t"
             << "\t"
             << "\t"
             << "\t"
             << "\t"
             << "3. Insert New Node at the beginning of the List." << endl
             << "\t"
             << "4. Insert new Node at any position of the list."
             << "\t"
             << "\t"
             << "\t"
             << "5. Delete Node from the end." << endl
             << "\t"
             << "6. Delete Node from the beginning."
             << "\t"
             << "\t"
             << "\t"
             << "\t"
             << "7. Delete Node from any position." << endl
             << "\t"
             << "8. Clear The List."
             << "\t"
             << "\t"
             << "\t"
             << "\t"
             << "\t"
             << "\t"

             << "9. Search any Node from the List." << endl
             << "\t"
             << "10. Sort the list in Ascending order"
             << "\t"
             << "\t"
             << "\t"
             << "\t"
             << "11. Sort the list in Descending order" << endl
             << "\t"
             << "12. Find the middle Node of the list"
             << "\t"
             << "\t"
             << "\t"
             << "\t"
             << "13. Print the nth Node from the End of the List" << endl
             << "\t"
             << "14. Reverse the List"
             << "\t"
             << "\t"
             << "\t"
             << "\t"
             << "\t"
             << "\t"
             << "15. Remove the Duplicate Nodes" << endl
             << "\t"
             << "16. Reverse a Linked list in a group of size k" << endl;

        cout << ">> ";
        cin >> x;
        cout << endl;
        cout << endl;
        /* Switch case for choosing option */
        switch (x)
        {
            /* For exit*/
        case 0:
        {
            system("cls");

            cout << "Exiting......" << endl
                 << "Final List is " << endl;

            printList(Head);
            break;
        }
            /* Create new List*/
        case 1:
        {
            int elem;
            cout << "Enter the Node data :  ";
            cin >> elem;

            Head = createNewList(elem);
            system("cls");

            printList(Head);
            break;
        }
            /*Insert new Node*/
        case 2:
        {
            int elem;
            cout << "Enter the Node data :  ";
            cin >> elem;
            Head = insertLast(Head, elem);
            system("cls");

            printList(Head);
            break;
        }
            /* Insert New Node at the beginning of the List */
        case 3:
        {
            int elem;
            cout << "Enter the Node data :  ";
            cin >> elem;
            Head = insertFirst(Head, elem);
            system("cls");

            printList(Head);
            break;
        }
            /* Insert new Node at any position of the lsit */

        case 4:
        {
            int pos, elem;
            cout << "Position started from 0tth index" << endl;
            cout << "The List is of length " << lenOList(Head) << endl;
            cout << "Enter the position of the Node in the List  ";
            cin >> pos;
            cout << "Enter the Node data :  ";
            cin >> elem;
            Head = InsertPosition(Head, pos, elem);
            system("cls");

            printList(Head);
            break;
        }

            /* Delete Node from the end */
        case 5:
        {
            Head = delNode(Head);

            printList(Head);
            break;
        }
            /* Delete Node from the beginning */
        case 6:
        {
            Head = delFrombeg(Head);

            printList(Head);
            break;
        }
            /* Delete Node from any position */
        case 7:
        {
            int pos;
            cout << "Position started from 0tth index" << endl;
            cout << "The List is of length " << lenOList(Head) << endl;
            cout << "Enter the position of the Node in the List  ";
            cin >> pos;
            Head = delFromPos(Head, pos);

            printList(Head);
            break;
        }
        /* Clear The List */
        case 8:
        {
            Head = NULL;
            system("cls");
            printList(Head);
            break;
        }

            /* Search any Node from the List */
        case 9:
        {
            if (lenOList(Head) > 0)
            {
                int elem;
                cout << "Enter the Node you want to find  ";
                cin >> elem;
                system("cls");

                search(Head, elem);
            }
            else
            {
                system("cls");

                cout << "The List is empty";
            }
            printList(Head);
            break;
        }
            /* Sort the list in Ascending order */
        case 10:
        {
            system("cls");
            printList(Head);
            Head = sortAscending(Head);
            printList(Head);
            break;
        }
            /* Sort the list in Descending order */
        case 11:
        {
            system("cls");
            printList(Head);
            Head = sortDescending(Head);
            printList(Head);
            break;
        }
            /* Find the middle Node from the list */
        case 12:
        {
            system("cls");
            Head = findMid(Head);
            printList(Head);
            break;
        }
            /* Print the nth Node from the End of the List */
        case 13:
        {
            int len = lenOList(Head);
            if (len == 0)
            {
                system("cls");

                cout << "The list is empty" << endl;
            }
            else
            {
                cout << "The list is of length " << len << endl;
                cout << "Enter the Position started by 1 : ";
                int n;
                cin >> n;
                system("cls");

                Head = nthFromLast(Head, n);
            }

            printList(Head);
            break;
        }
            /* Reverse the List */
        case 14:
        {
            system("cls");
            Head = reverseList(Head);
            printList(Head);
            break;
        }
            /* Remove the Duplicate Nodes */
        case 15:
        {
            system("cls");
            Head = removeDuplicates(Head);
            printList(Head);
            break;
        }
            /* Reverse a Linked list in a group of size k */
        case 16:
        {
            if (Head == NULL)
            {
                system("cls");
                cout << "The lsit is empty " << endl;
            }
            else
            {
                int k;
                cout << "Enter the value of k (>=1): ";
                cin >> k;
                system("cls");
                printList(Head);
                Head = reverseInK(Head, k);
            }

            printList(Head);
            break;
        }
        default:
            system("cls");
            printList(Head);
            cout << "Please Enter a valid option" << endl;

            break;
        }

    } while (x);

    return 0;
}
