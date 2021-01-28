#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0)
#define ll long long
#define mod 1000000007
#define endl '\n'
#define PI 3.14159265359

#define pre(x, y) fixed << setprecision(y) << x
#define deb(x) cout << #x << " => " << x << endl;

ll power(ll base, ll exp, ll md = mod)
{
    base %= md;
    ll res = 1;
    while (exp != 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % md;
        exp >>= 1;
        base = (base * base) % md;
    }
    return res;
}

struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
class List
{
public:
    node *root;
    List()
    {
        root = NULL;
    }
    void insert(int x)
    {
        node *curr = root;
        if (root == NULL)
        {
            curr = new node(x);
            root = curr;
            return;
        }
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = new node(x);
    }
    void print()
    {
        node *cur = root;
        while (cur != NULL)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

/////////////////////////////////Merge sort on Linked List////////////////////////////////////////

void splitList(node *head, node **aList, node **bList)
{
    node *fast = head->next, *slow = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *aList = head;
    *bList = slow->next;
    slow->next = NULL;
}
node *merge(node *a, node *b)
{
    node *res = NULL;
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    if (a->data < b->data)
    {
        res = a;
        res->next = merge(a->next, b);
    }
    else
    {
        res = b;
        res->next = merge(a, b->next);
    }
    return res;
}
void mergeSort(node **head_ref)  // Time Complexity - O(nlog(n))
{
    node *head = *head_ref;
    node *a, *b;

    if (head == NULL || head->next == NULL)
        return;

    splitList(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *head_ref = merge(a, b);
}

///////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    FIO;

    ll t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        List lst;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            lst.insert(x);
        }
        // lst.print();
        mergeSort(&lst.root);
        lst.print();
    }
    return 0;
}
