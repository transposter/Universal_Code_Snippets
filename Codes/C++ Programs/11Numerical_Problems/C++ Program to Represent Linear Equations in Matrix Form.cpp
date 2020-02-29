#include<iostream>
#include<conio.h>

using namespace std;

int main(void)
{
    char var[] = { 'x', 'y', 'z', 'w' };
    cout << "Enter the number of variables in the equations: ";
    int n;
    cin >> n;
    cout << "\nEnter the coefficients of each variable for each equations";
    cout << "\nax + by + cz + ... = d";
    int mat[n][n];
    int constants[n][1];
    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                {
                    cin >> mat[i][j];
                }
            cin >> constants[i][0];
        }
    cout << "Matrix representation is: ";
    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                {
                    cout << " " << mat[i][j];
                }
            cout << "  " << var[i];
            cout << "  =  " << constants[i][0];
            cout << "\n";
        }
    return 0;
}

/*
Enter the number of variables in the equations: 3

Enter the coefficients of each variable for each equations
ax + by + cz + ... = d
1 2 3 4
1 2 6 8
2 3 9 8
Matrix representation is:
 1 2 3  x  =  4
 1 2 6  y  =  8
 2 3 9  z  =  8