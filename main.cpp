#include <iostream>
using namespace std;


int main() {
    int dim;
    cin >> dim;
    int m[dim][dim];
    for (int i = 0; i<dim;i++)
    {
        for (int j = 0; j<dim;j++)
        {
            cin >> m[i][j];
        }
    }
    for (int i = 1; i<dim-1;i++)
    {
        for (int j = 1; j<dim-1;j++)
        {
            cout << m[dim-1-j][i] << " ";
        }
        cout <<endl;
    }
}