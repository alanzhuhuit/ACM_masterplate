const int ChildNum=26;
struct node
{
	int cnt;//是否为该单词的最后一个节点
	node* child[ChildNum];//Tire每个节点的26个子节点（最多26个字母）
	node()//构造函数初始化
	{
		cnt = 0;
		memset(child,NULL,sizeof(child));
	}
};
//
const int maxt = 1e6+10;
//
node *root;
char str[maxt];
//
void insert(char str[])
{
	node* s = root;
	int i = 0, len = strlen(str);
	s->cnt++;
	while(i < len)
	{
		int id = str[i] - 'a';
		if (s->child[id] == NULL)
			s->child[id] = new node;
		s = s->child[id];
		s->cnt++;
		i++;
	}
	return;
}
//计算str出现的次数
int count(char str[])
{
	node* now = root;
	int i = 0, id, len = strlen(str);
	while (i < len)
	{
		id = str[i] - 'a';
		if (now->child[id] == NULL) return 0;
		now = now->child[id];
		i++;
	}
	return now->cnt;
}
//
void init(int n)
{
	root = new node;
	REP(i, n) cin >> str, insert(str);
	cin >> str, cout << count(str) << endl;
}
