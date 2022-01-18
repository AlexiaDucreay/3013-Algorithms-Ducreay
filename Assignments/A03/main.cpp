/*****************************************************************************
*                    
*  Author:           alexia Ducreay
*  Email:            princesssalexia5@gmail.com
*  Label:            A03
*  Title:            Linked List Class
*  Course:           CMPS 3013
*  Semester:         Spring 2022
* 
*  Description:
*        This program implements a class that allows a linked list to be used just like 
*        an array. It overloads the "[]" (square brackets) to simulate accessing seperate 
*        array elements, but really it traverses the list to find the specified node using
*        an index value. It also overloads the "+" and "-" signs allowing a user to "add"
*        or "push" items onto the end of the list, as well as "pop" items off the end of our 
*        array.
*        
*       
*  Files:            
*       main.cpp    : driver program 
*       
*****************************************************************************/
#include <iostream>

using namespace std;

int A[100];

                          
struct Node {                    // creates a variable with the type struct node, named node
    int x;
    Node *next;
    Node() {
        x = -1;
        next = NULL;
    }
    Node(int n) {
        x = n;
        next = NULL;
    }
};
/**
 * List
 * 
 * Description:
 *      This class implements a compressions algorithm called Huffman Coding.
 *      Huffman coding assigns codes to characters such that the length of the 
 *      code depends on the relative frequency or weight of the corresponding 
 *      character. Huffman codes are of variable-length, and prefix-free
 * 
 * Public Methods:
 *                                                       
 *      List()
 *      void                Push(int val)
 *      void                Insert(int val)
 *      void                PrintTail()
 *      int                 Pop()
 *      List                operator+(const List &Rhs)
 *      int                 operator[](int index)
 * 
 * Private Methods:
 *     Node                 *Head
 *     Node                 *Tail
 *     int                  Size
 * 
 * Usage: 
 * 
 *      Huffman H(filename):                        // Create Instance of Huffman
 *                                                  // and build freq table. 
 *      H.GetCodes();                               // get map <char,string> of codes
 * 
 *                                                  // or
 *      
 *      Huffman H;                                  // do seperately
 *      H.BuildFrequencyTable(filename);            // or use to re-build another file
 *      H.LookupCode('s')                           // get code for 's' 
 *      
 */
class List {
private:
    Node *Head;
    Node *Tail;
    int Size;

public:
    List() {
        Head = Tail = NULL;
        Size = 0;
    }

    void Push(int val) {
        
        Node *Temp = new Node(val);      // allocate new memory and init node
        if (!Head && !Tail) {
            Head = Tail = Temp;
        } else {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

    void Insert(int val) {
        
        Node *Temp = new Node(val);     // allocate new memory and init node
       

        Temp->next = Head;              //insert from the from of the list
        Head = Temp;
        if (!Tail) {
            Tail = Head;
        }
        Size++;
    }

    void PrintTail() {
        cout << Tail->x << endl;
    }

    string Print() {
        Node *Temp = Head;
        string list;

        while (Temp != NULL) {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    
    int Pop() {                        // not implemented
        Size--;
        return 0; //
    }

    List operator+(const List &Rhs) {
        
        List NewList;                 // Create a new list that will contain both when done        
        Node *Temp = Head;            // Get a reference to beginning of local list    

        while (Temp != NULL) {        // Loop through local list and Push values onto new list
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        Temp = Rhs.Head;              // Get a reference to head of Rhs

        while (Temp != NULL) {        // Loop through local list and Push values onto new list
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        
        return NewList;              // Return new concatenated version of lists 
    }

     /**
     * Public : operator[]
     * 
     * Description:
     *      Implementation of [] operator.  This function returns an
     *       int value as if the list were an array.
     * 
     * Params:
     *      
     *      [int]     :  index
     * 
     * Returns:
     *      [type] int   : Temp->x.
     */

    
    int operator[](int index) {
        Node *Temp = Head;

        if (index >= Size) {
            cout << "Index out of bounds, exiting";
            exit(0);
        } else {

            for (int i = 0; i < index; i++) {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    friend ostream &operator<<(ostream &os, List L) {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv) {
    List L1;
    List L2;

    for (int i = 0; i < 25; i++) {
        L1.Push(i);
    }

    for (int i = 50; i < 100; i++) {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    List L3 = L1 + L2;
    cout << L3 << endl;

    cout << L3[5] << endl;
    return 0;
}
