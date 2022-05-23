// LP 2 : A Star Algorithm

#include <bits/stdc++.h>
using namespace std;

#define n 3

class state 
{
    public:
    int board [n][n], g, f;
    state * prev;
    state()
    {    
        g =0;
        f=0;
        prev=NULL;
    }

    static int heuristic (state current, state final)
    {
        int h = 0;
        for (int i = 0; i<n; i++)
            for (int j=0; j<n; j++)
                if (current.board[i][j]!=final.board[i][j])
                    h++;
        return h;
    }

    bool operator == (state a) 
    {    
        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (this->board[i][j] != a.board[i][j])
                return false;
        return true;
    }

    void print () 
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        cout << "\n g = " << g << " and f = " << f << endl;
    }
};

vector <state> output;
bool lowerF (state a, state b) {
  return a.f < b.f;
}

bool isinset (state a, vector <state> b) {
  for (int i = 0; i < b.size(); i++)
    if (a == b[i])
      return true;
  return false;
}

void addNeighbor (state current, state goal, int newi, int newj, int posi, int posj, vector <state>& openset, vector <state> closedset) {
  state newstate = current;
  swap (newstate.board[newi][newj], newstate.board[posi][posj]);
  if (!isinset(newstate, closedset) && !isinset(newstate, openset)) {
      newstate.g = current.g + 1;
      newstate.f = newstate.g + state :: heuristic(newstate, goal);
      state* temp = new state();
      *temp = current;
      newstate.prev = temp;
      openset.push_back(newstate);
  }
}
bool reconstruct_path(state current, vector<state> &prev) {
    state *temp = &current;
    while(temp != NULL) {
        prev.push_back(*temp);
        temp = temp->prev;
    }
    return true;
}


void neighbors (state current, state goal, vector <state>& openset, vector <state>& closedset) {
  int i, j, posi ,posj;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (current.board[i][j] == 0) {
        posi = i;
        posj = j;
        break;
      }
  i = posi, j = posj;
  if (i - 1 >= 0)
    addNeighbor(current, goal, i - 1, j, posi, posj, openset, closedset);
  if (i + 1 < n)
    addNeighbor(current, goal, i + 1, j, posi, posj, openset, closedset);
  if (j + 1 < n)
    addNeighbor(current, goal, i, j + 1, posi, posj, openset, closedset);
  if (j - 1 >= 0)
    addNeighbor(current, goal, i, j - 1, posi, posj, openset, closedset);
}

bool astar (state start, state goal) {
  vector <state> openset;
  vector <state> closedset;
  state current;
  start.g = 0;
  start.f = start.g + state :: heuristic(start, goal);
  openset.push_back(start);
  while (!openset.empty()) {
    sort(openset.begin(), openset.end(), lowerF);
    current = openset[0];
    if (current == goal)
      return reconstruct_path(current, output);
    openset.erase(openset.begin());
    closedset.push_back(current);
    neighbors(current, goal, openset, closedset);
  }
  return false;
}
int main ()
{
    state start, goal;

    cout << "\n Enter Start Matrix : \n ";
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> start.board[i][j];
    cout << "\n Enter Goal Matrix : \n ";
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> goal.board[i][j];

     if (astar(start, goal) == true) {
    for (int i = output.size() - 1; i >= 0; i--)
      output[i].print();
    cout << "Success" << endl;
  }
  else cout << "Failed" << endl;
  return 0;

}
