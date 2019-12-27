#include<iostream>
#include<vector>
using namespace std;
#define dbl pair<int,int>
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
vector<dbl> stack;
bool has(vector<dbl> vec, dbl elem){
    for(auto el = vec.begin(); el != vec.end(); ++el){
        if(el->first==elem.first and el->second==elem.second){
            return true;
        }
    }
    return false;
}
bool solve(int x, int y, int endx, int endy) {
    stack.push_back(dbl(x, y));
    if (x == endx && y == endy) {
        return true;
    }
    if (x < w - 1) {
        if (path[y][x + 1] != '*' && !has(stack, dbl(x + 1, y)))
        {
            if (solve(x + 1, y, endx, endy)) {
                return true;
            }
        }
    }
    if (y < h - 1) {
        if (path[y + 1][x] != '*' && !has(stack, dbl(x, y + 1))) {
            if (solve(x, y + 1, endx, endy)) {
                return true;
            }
        }
    }
    if (x >= 1) {
        if (path[y][x - 1] != '*' && !has(stack, dbl(x - 1, y))) {
            if (solve(x - 1, y, endx, endy)) {
                return true;
            }
        }
    }
    if (y >= 1) {
        if (path[y - 1][x] != '*' && !has(stack, dbl(x, y - 1))) {
            if (solve(x, y - 1, endx, endy)) {
                return true;
            }
        }
    }
    stack.pop_back();
    return false;
}
int main(int argc, char const * argv[]) {
    bool solvable = solve(3, 0, 3, 5);
    if (!solvable) {
        cerr << "The maze can't be solved" << endl;
    } else {
        for(auto el = stack.begin(); el != stack.end(); ++el){
            cout<<el->first<<" "<<el->second<<endl;
        }
    }
    return 0;
}
