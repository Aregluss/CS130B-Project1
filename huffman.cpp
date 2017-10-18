#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater
#include <iostream>

using namespace std;


struct huffNode {
        int asciiVal;
        int freq;
        huffNode *left;
        huffNode *right;

        huffNode() : asciiVal(-1), freq(0), left(NULL), right(NULL)
        {
        }

        huffNode(int value, int count)
        {
            asciiVal = value;
            freq = count;
            left = NULL;
            right = NULL;
        }

        huffNode(huffNode *childL, huffNode *childR)
        {
            asciiVal = -1;
            freq = childR->freq + childL ->freq;
            left = childL;
            right = childR;
        }

};

class Minimum
{
public:
    bool operator() (huffNode *one, huffNode *two)
    {

        return (one->freq > two->freq);
    }
};


void inOrderT(huffNode *start, string path)
{
        if(start == NULL)
            return;
        if(start->asciiVal >= 0)
            cout << start->asciiVal << '\t' << path << "\n";
        inOrderT(start->left, path + "0");
        inOrderT(start->right, path + "1");
}

int main ()
{
    priority_queue<huffNode*, vector<huffNode*>, Minimum> pq;

    int value, freq;

    while(cin >> value)
    {

        cin >> freq;
        huffNode *h1 = new huffNode(value, freq);
        pq.push(h1);
    }
 

    while (pq.size() > 1)
    {
        huffNode *pt1 = pq.top();
        pq.pop();
        huffNode *pt2 = pq.top();
        pq.pop();

        huffNode *combo = new huffNode(pt1, pt2);
        pq.push(combo);
    }
 
    huffNode *root = pq.top();
    pq.pop();
    ////////////DELETE PRIO QUEUE NO NEED

    inOrderT(root, "");

    return 0;
}