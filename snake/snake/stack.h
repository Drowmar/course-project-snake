struct ListEdge
{
	struct List*start;
	struct List*end;
};

struct List
{
	int wt_x;
	int wt_y;
	int addr_x;
	int addr_y;
	struct List*next;
};

void Init(struct ListEdge * lstp);
int Add(struct ListEdge* lstp, int x, int y, int a_x, int a_y);
void DeleteEdge(struct ListEdge* lstp);
void Clear(struct ListEdge* list);