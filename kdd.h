#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <map>
#include <set>
#include <ctime>

#include "Snap.h"

using namespace std;
using namespace TSnap;

#define SIZE 32

struct node {
	int id;
	int next;
	bitset<SIZE> in;
	bitset<SIZE> out;
};

void run (const char inputfile[], const char outputfile[], const int & K = 8, const float & RF = 0.9, const float & DT = 0.25);

void genMP (vector<node> & MP, PNGraph & Graph, const int & K, const float & RF, const float & DT);

void saveMP (const vector<node> & v, const char outputfile[]);

void loadMP (vector<node> & v, const char inputfile[]);

void statistic (const char outputfile[], const int & vSize, const int totalBits, const int & edges, const int & K, const float & RF, const float & DT);

void queryNeigh (vector<node> & v, const int & key);

// helping functions
void updatePos (const int & id, node & n, vector<node> & MP,  map<int, int> & pos);

void updateX (const int k, vector<node> & MP, PNGraph & Graph, set<int> & X, map<int, int> & neighbor);

void updateMP (vector<node> & MP, const int & sizeX, const node & n, PNGraph & Graph, set<int> & inNode, set<int> & outNode);

void appendNode (vector<node> & MP, const int & id, PNGraph & Graph, 
	set<int> & X, const int & k, map<int, int> & pos, map<int, int> & neighbor);

void addNeigh (const TNGraph::TNodeI & idIter, set<int> & X, map<int, int> & neighbor, set<int> & inNode, set<int> & outNode);

int getMostNeighNode (map<int, int> & neighbor);

bool cmp (const pair<int, int> & x, const pair<int, int> & y);
