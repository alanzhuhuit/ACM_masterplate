const int ChildNum=26;
struct node
{
	node* fail;//失败指针
	int cnt;//是否为该单词的最后一个节点
	node* child[ChildNum];//Tire每个节点的26个子节点（最多26个字母）
	node()//构造函数初始化
	{
		fail = NULL;
		cnt = 0;
		memset(child,NULL,sizeof(child));
	}
};
//
const int MAXT = 1e6+10;
//
node *root;
char str[100], Text[MAXT];
//
void insert(char* str)
{
	node* s = root;
	int i = 0, len = strlen(str);
	while(i < len)
	{
		int id = str[i] - 'a';
		if (s->child[id] == NULL) s->child[id] = new node;
		s = s->child[id];
		i++;
	}
	s->cnt++;
	return;
}
//
void makeFail()
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* now = q.front();
		q.pop();
		REP(i, ChildNum)
		if (now->child[i] != NULL)//父结点有孩子i，则找孩子i的fail指针
		{
			q.push(now->child[i]);
			if (now == root)
				now->child[i]->fail = root;//与根结点相连的结点的fail指针都指向根结
			else
			{
				node* tmp = now;
				while(tmp->fail != NULL) //父结点fail指针非空
				{
					if (tmp->fail->child[i] != NULL)//父结点fail指针指向的结点
						{ now->child[i]->fail = tmp->fail->child[i]; break;}
					tmp = tmp->fail;//父结点向上转移
				}
				if (tmp->fail == NULL)
				now->child[i]->fail = root;
			}
		}
	}
	return;
}
//
int COMPARE()
{
	int ans = 0;
	node* now = root;
	int len = strlen(Text);
	int i = 0;
	while(i < len)
	{
		int id = Text[i] - 'a';
		while(now != root && now->child[id] == NULL)
			now = now->fail;
		if (now->child[id] != NULL)
		{
			now = now->child[id];
			node* tmp = now;
			while(tmp != root && tmp->cnt != 0)
			{
				ans += tmp->cnt;
				tmp->cnt = 0;
				tmp = tmp->fail;
			}
		}
		i++;
	}
	return ans;
}
//
void init(int n)
{
	REP(i, n) cin >> str, insert(str);
        makeFail();
        cin >> Text;
	cout << COMPARE() << endl;
}

