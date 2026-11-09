// Q19. Generate Huffman codes for characters and frequencies.
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char ch;
    int f;
    Node *l, *r;
    Node(char c, int x) : ch(c), f(x), l(nullptr), r(nullptr) {}
    Node(Node *a, Node *b) : ch('\0'), f(a->f + b->f), l(a), r(b) {}
};
struct Cmp
{
    bool operator()(Node *a, Node *b) { return a->f > b->f; }
};
void print(Node *r, string s)
{
    if (!r)
        return;
    if (!r->l && !r->r)
    {
        cout << r->ch << ": " << (s.empty() ? "0" : s) << "\n";
        return;
    }
    print(r->l, s + "0");
    print(r->r, s + "1");
}
int main()
{
    int n;
    cout << "Enter number of characters: ";
    cin >> n;
    if (n <= 0)
        return 0;
    priority_queue<Node *, vector<Node *>, Cmp> pq;
    cout << "Enter character and frequency:\n";
    for (int i = 0; i < n; i++)
    {
        char c;
        int f;
        cin >> c >> f;
        pq.push(new Node(c, f));
    }
    while (pq.size() > 1)
    {
        Node *a = pq.top();
        pq.pop();
        Node *b = pq.top();
        pq.pop();
        pq.push(new Node(a, b));
    }
    cout << "Huffman codes:\n";
    print(pq.top(), "");
}
