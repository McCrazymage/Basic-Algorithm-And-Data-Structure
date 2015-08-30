/*

Appropriate for most kind of data type

email crazymage@pku.edu.cn
*/

template<typename T1, typename T2>
class node
{
public:
	T1 key;
	T2 value;
	int next;
	node()
	{
		next = -1;
	}
};

template<typename T1, typename T2>
class hashmap
{
	int temp;
	int *head;
	int n;
	node<T1,T2> *nodes;


	int (*hash)(T1 t);
	bool (*cmp)(T1 t1, T1 t2);
public:
	hashmap(int(*hash)(T1 t), bool(*cmp)(T1 t1, T1 t2),int n)
	{
		this->n = n;
		this->hash = hash;
		this->cmp = cmp;
		this->head = (int*)malloc(sizeof(int)*n);
		this->nodes = (node<T1, T2> *)malloc(sizeof(node<T1, T2>)*n);
		temp = 0;
		for (size_t i = 0; i < n; i++)
		{
			head[i] = -1;
		}
	}
	bool set(T1 a, T2 b)
	{
		if (find(a) != NULL)
		{
			return false;
		}
		int key = hash(a);
		if (head[key] != -1)
		{
			nodes[temp].next = head[key];
		}
		head[key] = temp;
		nodes[temp].key = a;
		nodes[temp].value = b;
		temp++;
		return true;
	}

	T2 find(T1 a)
	{
		int key = hash(a);
		if (head[key] == -1)
		{
			return NULL;
		}
		else
		{
			for (int temp2 = head[key]; temp2 != -1; temp2 = nodes[temp2].next)
			{
				if (!cmp(a, nodes[temp2].key))
				{
					return nodes[temp2].value;
				}
			}
			return NULL;
		}
	}

};

/*

for string key and value

*/
class node
{
public:
	char key[11];
	char value[11];
	int next;
	node()
	{
		next = -1;
	}
};

class hashmap
{
	int temp;
	int head[100001];
	node nodes[100001];
	bool cmp(char *a, char *b)
	{
		return !strcmp(a, b);
	}

	int hash(char *a)
	{
		int va=0;
		int len = strlen(a);
		for (int i = 0; i < len;i++)
		{
			va = a[i] + va * 10;
			va %= 100001;
		}
		return va;
	}
public:
	hashmap()
	{
		temp = 0;
		for (size_t i = 0; i < 100001; i++)
		{
			head[i] = -1;
		}
	}
	bool set(char *a, char *b)
	{
		if (find(a)!=NULL)
		{
			return false;
		}
		int key = hash(a);
		if (head[key] != -1)
		{
			nodes[temp].next = head[key];
		}
		head[key] = temp;
		strcpy(nodes[temp].key, a);
		strcpy(nodes[temp].value, b);
		temp++;
		return true;
	}

	char* find(char *a)
	{
		int key = hash(a);
		if (head[key]==-1)
		{
			return NULL;
		}
		else
		{
			for (int temp2 = head[key]; temp2 != -1;temp2=nodes[temp2].next)
			{
				if (!strcmp(a,nodes[temp2].key))
				{
					return nodes[temp2].value;
				}
			}
			return NULL;
		}
	}

};


