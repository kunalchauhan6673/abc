#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int col;
    int val;
    Node *next;
};

class SparseMatrix
{
public:
    int rows, cols;
    Node **A; // Array of linked lists

    SparseMatrix(int r, int c)
    {
        rows = r;
        cols = c;

        A = new Node*[rows];

        for(int i = 0; i < rows; i++)
            A[i] = nullptr;
    }

    void create()
    {
        int n;
        cout << "Enter number of non-zero elements: ";
        cin >> n;

        cout << "Enter row column value:\n";

        for(int i = 0; i < n; i++)
        {
            int row, col, val;
            cin >> row >> col >> val;

            Node *t = new Node;
            t->col = col;
            t->val = val;
            t->next = nullptr;

            if(A[row] == nullptr)
            {
                A[row] = t;
            }
            else
            {
                Node *p = A[row];

                while(p->next != nullptr)
                    p = p->next;

                p->next = t;
            }
        }
    }

    void display()
    {
        for(int i = 0; i < rows; i++)
        {
            Node *p = A[i];

            for(int j = 0; j < cols; j++)
            {
                if(p && p->col == j)
                {
                    cout << p->val << " ";
                    p = p->next;
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    SparseMatrix sm(5, 6);

    sm.create();

    cout << "\nMatrix:\n";
    sm.display();

    return 0;
}
