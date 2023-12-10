#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

const int MAXN = 100005; // Maximum size for arrays

vector<int> edge[MAXN]; // Vector of edges
vector<int> cost[MAXN]; // Vector of costs
int dis[MAXN]; // Array for distances
int n; // Size of the arrays

void reset()
{
    for(int i=0; i<n+10; i++)
    {
        edge[i].clear(); // Clear the edge vector at index i
        cost[i].clear(); // Clear the cost vector at index i
        dis[i] = INF; // Initialize the distance array with INF
    }
}

int main()
{
    // Your main function code here
    return 0;
}
