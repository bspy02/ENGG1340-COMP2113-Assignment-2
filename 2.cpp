#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

const int X = 0;
const int Y = 1;

const int MAXGEOM = 20;

struct AABB {
  double min[2];  // min[0] = xmin, min[1] = ymin
  double max[2];  // max[0] = xmax, max[1] = ymax

  // functions

  // Read a point set from user input and calculates AABB
  void ReadPointSet() {
    int n;
    double x, y;

    cin >> n;
    min[X] = min[Y] = numeric_limits<double>::max();
    max[X] = max[Y] = numeric_limits<double>::lowest();
    for (int i = 0; i < n; ++i) {
      cin >> x >> y;
      if (x < min[X]) {min[X] = x;}
      if (x > max[X]) {max[X] = x;}
      if (y < min[Y]) {min[Y] = y;}
      if (y > max[Y]) {max[Y] = y;}
    }
  }

  // Read a rectangle from user input and calculates AABB
  void ReadRectangle() {
    // --- YOUR CODE HERE (Task 1) ---    
    double x, y, w, h;

    min[X] = min[Y] = numeric_limits<double>::max();
    max[X] = max[Y] = numeric_limits<double>::lowest();
    cin >> x >> y >> w >> h;
    if (x - w/2 < min[X]) min[X] = x - w/2;
    if (x + w/2 > max[X]) max[X] = x + w/2;
    if (y - h/2 < min[Y]) min[Y] = y - h/2;
    if (y + h/2 > max[Y]) max[Y] = y + h/2;
  }

  // Read a circle from user input and calculates AABB
  void ReadCircle() {
    // --- YOUR CODE HERE (Task 1) ---
    double x, y, r;
    min[X] = min[Y] = numeric_limits<double>::max();
    max[X] = max[Y] = numeric_limits<double>::lowest();
    cin >> x >> y >> r;
    if (x - r < min[X]) min[X] = x - r;
    if (x + r > max[X]) max[X] = x + r;
    if (y - r < min[Y]) min[Y] = y - r;
    if (y + r > max[Y]) max[Y] = y + r;
  }

};

// return true if two AABBs overlaps
//        false otherwise

bool IsOverlap(AABB p, AABB q)
{
    if ((p.min[0] >= q.max[0])||(q.min[0] >= p.max[0] ))
    {
        return false;
    }
    if ((p.min[1] >= q.max[1])||(q.min[1] >= p.max[1] ))
    {
        return false;
    }
    return true;
}


int main()
{
  char type;

  AABB boxes[MAXGEOM];

  AABB res; // input AAAB and result AABB
  // initialize bounds of result AABB
  res.min[X] = res.min[Y] = numeric_limits<double>::max();
  res.max[X] = res.max[Y] = numeric_limits<double>::lowest();

  // read geometry type and dispatch to the corresponding
  // AABB read geomety functions to read from user input handle
  // and compute AABB
  // store all AABBs in the array "boxes"
  int numBoxes = 0;

  cin >> type;
  while (type != '#') {
    switch (type) {
      case 'R':
        boxes[numBoxes++].ReadRectangle();
        break;
      case 'C':
        boxes[numBoxes++].ReadCircle();
        break;
      case 'P':
        boxes[numBoxes++].ReadPointSet();
        break;
      default:
        break;
    }
    cin >> type;
  }

  // display AABBs for input geometries by going through the array "boxes"
  for (int i = 0; i < numBoxes; i++) {
    // --- YOUR CODE HERE (Task 2) ---
    AABB box = boxes[i];

    cout << "AABB " << setfill('0') << setw(2) << i << ": ";
    cout << box.min[0]  <<" "<< box.max[0] <<" "<< box.min[1]<<" "<< box.max[1]<<endl;

  }

  cout << "Isolated AABBs:\n";

  // for each AABB, if it does not overlap with any other AABBs, display its ID
  // --- YOUR CODE HERE (Task 4) ---
  for (int i = 0; i < numBoxes; i++)
  {
      int sth = 0;

      for (int j = 0; j < numBoxes; j++)
      {
          if(i==j) continue;
          else if(sth > 0) break;
          sth += IsOverlap(boxes[j], boxes[i]);
      } 
      if(sth == 0)
      {
          cout << setfill('0') << setw(2);
          cout << i << endl;
      }
  }
  return 0;
}