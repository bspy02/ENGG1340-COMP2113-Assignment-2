#include <iostream>

const int MAXDIM = 10;

//----------------------DO NOT CHANGE ANYTHING ABOVE THIS LINE------------------

//   Write your function definitions here
using namespace std;
void read_matrix(int (&matrix)[MAXDIM][MAXDIM], int &dim)
{
    cin >> dim;
    for (int i = 0; i<dim;i++)
    {
        for (int j = 0; j<dim;j++)
        {
            cin >> matrix[i][j];
        }
    }
}
void display_inner_cw_rotated(int matrix[MAXDIM][MAXDIM], int dim){
    for (int i = 1; i<dim-1;i++)
    {
        for (int j = 1; j<dim-1;j++)
        {
            cout << matrix[dim-1-j][i] << " ";
        }
        cout <<endl;
    }
}
//----------------------DO NOT CHANGE ANYTHING BELOW THIS LINE------------------

int main()
{
  int matrix[MAXDIM][MAXDIM]{};
  int dim = 0;

  read_matrix(matrix, dim);
  display_inner_cw_rotated(matrix, dim);

  return 0;
}