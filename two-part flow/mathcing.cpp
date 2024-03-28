#include <iostream>
#include <string.h>
using namespace std;

#define M 100
#define N 100

bool bpm(bool bpGraph[M][N], int u, bool seen[], int matchR[], int matching[],int n,int m)
{
    for (int v = 0; v < m; v++)
    {
        if (bpGraph[u][v] && !seen[v])
        {
            seen[v] = true;

            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR, matching,n,m))
            {
                matchR[v] = u;
                matching[u] = v; 
                return true;
            }
        }
    }
    return false;
}

int maxBPM(bool bpGraph[M][N], int matching[],int n,int m)
{
    int matchR[N];
    memset(matchR, -1, sizeof(matchR));

    int result = 0;
    for (int u = 0; u < n; u++)
    {
        bool seen[N];
        memset(seen, 0, sizeof(seen));

        if (bpm(bpGraph, u, seen, matchR, matching,n,m))
            result++;
    }
    return result;
}

int main()
{
	int n, m;
    cin >> n;
    cin >> m;
    bool bpGraph[M][N] = {0};

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
        	bool u;
       	 	cin>>u;
       	 	bpGraph[i][j] = u;
  	  }
	}


    int matching[M];
    memset(matching, -1, sizeof(matching));

    int totalMatches = maxBPM(bpGraph, matching,n,m);

    for (int i = 0; i < n; i++)
    {
        if (matching[i] != -1)
        {
            cout <<matching[i] + 1 << " ";
        }
        else
        {
            cout << -1 << " ";
        }
    }

    return 0;
}


