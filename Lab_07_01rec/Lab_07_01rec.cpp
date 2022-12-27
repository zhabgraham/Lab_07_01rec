#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Generate(int** b, const int rowcount, const int colcount, const int low, const int high, int i, int j)
{
    b[i][j] = low + rand() % (high - low + 1);
    if (j < colcount - 1)
        Generate(b, rowcount, colcount, low, high, i, j + 1);
    else
        if (i < rowcount - 1)
            Generate(b, rowcount, colcount, low, high, i + 1, 0);
}

void print(int** b, const int rowcount, const int colcount, int i, int j)
{
    cout << b[i][j] << "\t";
    if (j < colcount - 1)
        print(b, rowcount, colcount, i, j + 1);
    else
    {
        cout << "\n";
        if (i < rowcount - 1)
            print(b, rowcount, colcount, i + 1, 0);
        else
            cout << "\n";
    }
}

void Change(int** b, const int firstrow, const int secondrow, const int colcount, int j)
{
    int tmp;
    tmp = b[firstrow][j];
    b[firstrow][j] = b[secondrow][j];
    b[secondrow][j] = tmp;

    if (j < colcount - 1)
        Change(b, firstrow, secondrow, colcount, j + 1);
}

void Sort(int** b, const int rowcount, const int colcount, int i0, int i1)
{
    if ((b[i1][0] >= b[i1 + 1][0])
        ||
        (b[i1][0] == b[i1 + 1][0] &&
            b[i1][1] <= b[i1 + 1][1])
        ||
        (b[i1][0] == b[i1 + 1][0] &&
            b[i1][1] == b[i1 + 1][1] &&
            b[i1][3] >= b[i1 + 1][3]))
        Change(b, i1, i1 + 1, colcount, 0);
    if (i1 < rowcount - i0 - 1 - 1)
        Sort(b, rowcount, colcount, i0, i1 + 1);
    else
        if (i0 < rowcount - 1 - 1)
            Sort(b, rowcount, colcount, i0 + 1, 0);
}

void Calc(int** b, const int rowcount, const int colcount, int& S, int& k, int i, int j)
{
    if (b[i][j] % 2 == 0 || !(b[i][j] % 8 == 0))
    {
        S += b[i][j];
        k++;
        b[i][j] = 0;
    }
    if (j < colcount - 1)
        Calc(b, rowcount, colcount, S, k, i, j + 1);
    else
        if (i < rowcount - 1)
            Calc(b, rowcount, colcount, S, k, i + 1, 0);
            
}

int main()
{
    srand((unsigned)time(NULL));
    const int low = 8;
    const int high = 73;
    const int rowcount = 7;
    const int colcount = 6;

    int S = 0;
    int k = 0;

    int i;
    int j;
    int i0;
    int i1;

    int** b = new int* [rowcount];
    for (int i = 0; i < rowcount; i++)
        b[i] = new int[colcount];

    Generate(b, rowcount, colcount, low, high, 0, 0);
    print(b, rowcount, colcount, 0, 0);
    Sort(b, rowcount, colcount, 0, 0);
    print(b, rowcount, colcount, 0, 0);


    Calc(b, rowcount, colcount, S, k, 0, 0);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    print(b, rowcount, colcount, 0, 0);

    for (int i = 0; i < rowcount; i++)
        delete[] b[i];
    delete[] b;
    system("pause");
    return 0;
}