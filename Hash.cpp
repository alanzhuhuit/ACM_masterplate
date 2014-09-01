struct HashNode
{
    long long f,num;
    HashNode *Next;
}Hash[MAXN];
long long Sum[MAXN];
int N;
long long Ans;

HashNode *FindHash(long long t)
{
    long long h = ((t % MAXN)+MAXN)%MAXN;
    HashNode *Node = Hash[h].Next;
    while(Node != NULL)
    {
        if (Node->f == t) break;
        Node = Node->Next;
    }
    return Node;
}

void InsertHash(long long t)
{
    long long h = ((t % MAXN)+MAXN)%MAXN;
    HashNode *Node;
    Node = FindHash(t);
    if (Node == NULL)
    {
        Node = new HashNode;
        Node->f = t;
        Node->num = 1;
        Node->Next = Hash[h].Next;
        Hash[h].Next = Node;
    }
    else Node->num++;
}