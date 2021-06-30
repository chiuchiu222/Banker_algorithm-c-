#include<iostream>
#include <fstream>
using namespace std;
void Need(int p, int r, int need[100][100], int maxm[100][100], int allot[100][100])
{
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            need[i][j] = maxm[i][j] - allot[i][j];
}
void Print(int p, int m, int a[][100]) 
{
    for (int i = 0; i < p; i++)
    {
        for (int j = 0 ; j < m; j++) 
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
bool safe(int p, int r, int avail[100], int maxm[100][100], int allot[100][100])
{
    int need[100][100];
    Need(p, r, need, maxm, allot);

    bool finish[100] = { 0 };

    int safeSeq[100];

    int work[100];
    for (int i = 0; i < r; i++)
        work[i] = avail[i];
    int count = 0;
    while (count < p)
    {

        bool found = false;
        for (int c = 0; c < p; c++)
        {
            if (finish[c] == 0)
            {
                int j;
                for (j = 0; j < r; j++)
                    if (need[c][j] > work[j])
                        break;
                if (j == r)
                {
                    for (int k = 0; k < r; k++)
                        work[k] += allot[c][k];

                    safeSeq[count++] = c;

                    finish[c] = 1;

                    found = true;
                }
            }
        }
        if (found == false)
        {
            cout << "He thong o trang thai chua an toan!!" << endl;
            return false;
        }
    }
    cout << "He thong co chuoi an toan la: ";
    for (int i = 0; i < p; i++)
        cout << safeSeq[i] << " ";
    return true;
}
int main()
{
    fstream f;
    f.open("C:/Users/hovie/Documents/Banker algorithm c++/input.txt");
    int p, r;
    if (f.is_open())
    {
        f >> p >> r;
        int allot[100][100];
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < r; j++) {
                f >> allot[i][j];
            }
        }
        int maxm[100][100];
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < r; j++) {
                f >> maxm[i][j];
            }
        }
        int avail[100];
        for (int i = 0; i < r; i++) {
            f >> avail[i];
        }
        cout << "So tien trinh: " << p << endl;
        cout << "So loai tai nguyen: " << r << endl;
        cout << "Allocation: " << endl;
        Print(p, r, allot);
        cout << "Max: " << endl;
        Print(p, r, maxm);
        cout << "Available: " << endl;
        for (int i = 0; i < r; i++) {
            cout << avail[i] << " ";
        }
        cout << endl;
        safe(p, r, avail, maxm, allot);
    }
    else
    {
        cout << "Chua doc duoc input dung.";
    }
    f.close();
    return 0;
}