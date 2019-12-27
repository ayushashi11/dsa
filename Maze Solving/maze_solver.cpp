#include <iostream>
#include <iomanip>
#include <vector>
#define dbl pair<int, int>
#define println(x) cout<<(x)<<endl
using namespace std;
struct Node {
    dbl data;
    Node * addr = NULL;
    Node() {}
    Node(dbl dat) {
        this -> data = dat;
    }
    std::ostream operator << (std::ostream stream) {
        stream << (this -> data).first << ' ' << (this -> data).second;
    }
};
struct LList {
    Node * first = NULL;
    LList() {}
    void prepend(Node * node) {
        if (this -> first == NULL) {
            this -> first = node;
        } else {
            node -> addr = this -> first;
            this -> first = node;
        }
    }
    bool has(dbl dat) {
        Node * curr = this -> first;
        while (curr != NULL) {
            if (curr -> data == dat) {
                return true;
            }
            curr = curr -> addr;
        }
        return false;
    }
    void prepend(dbl dat) {
        Node * node = new Node(dat);
        this -> prepend(node);
    }
    Node * pop() {
        Node * node = this -> first;
        this -> first = this -> first -> addr;
        return node;
    }
    void print() {
        Node * node = this -> first;
        cout << "[\n";
        while (node != NULL) {
            cout << setw(8) << (node -> data.first) << ' ' << (node -> data.second) << '\n';
            node = node -> addr;
        }
        cout << "]\n";
    }
};
const int h = 6,
    w = 6;
/*this is the maze
s is start
f is finish(end)
*s are walls
rest is free space*/
char path[h][w] = {
                    {' ',' ',' ',' ','*','*'}, /*start at (3,0) or path[0][3]*/
                    {' ','*','*','*','*','*'},
                    {' ',' ','*',' ','*','*'},
                    {'*',' ',' ',' ',' ','*'},
                    {'*','*',' ','*',' ',' '},
                    {'*','*',' ',' ',' ','*'}  /*finish at (3,5) or path[5][3] */
                };
LList * stack = new LList();
bool solve(int x, int y, int endx, int endy) {
    stack -> prepend(dbl(x, y));
    if (x == endx && y == endy) {
        return true;
    }
    if (x < w - 1) {
        if (path[y][x + 1] != '*' && !stack -> has(dbl(x + 1, y)))
        {
            if (solve(x + 1, y, endx, endy)) {
                return true;
            }
        }
    }
    if (y < h - 1) {
        if (path[y + 1][x] != '*' && !stack -> has(dbl(x, y + 1))) {
            if (solve(x, y + 1, endx, endy)) {
                return true;
            }
        }
    }
    if (x >= 1) {
        if (path[y][x - 1] != '*' && !stack -> has(dbl(x - 1, y))) {
            if (solve(x - 1, y, endx, endy)) {
                return true;
            }
        }
    }
    if (y >= 1) {
        if (path[y - 1][x] != '*' && !stack -> has(dbl(x, y - 1))) {
            if (solve(x, y - 1, endx, endy)) {
                return true;
            }
        }
    }
    stack -> pop();
    return false;
}
int main(int argc, char const * argv[]) {
    println("maze solver");
    bool solvable = solve(3, 0, 3, 5);
    if (!solvable) {
        cerr << "The maze can't be solved" << endl;
    } else {
        while( !(stack->first == NULL)){
            dbl p=stack->pop()->data;
            cout<<p.first<<" "<<p.second<<endl;
        }
    }
    return 0;
}
