struct list_edge
{
	struct list* start;
	struct list* end;
};

struct list
{
	int wt_x;
	int wt_y;
	int addr_x;
	int addr_y;
	struct list* next;
};

void Init(struct list_edge* lstp);
int Add(struct list_edge* lstp, int x, int y, int a_x, int a_y);
void DeleteEdge(struct list_edge* lstp);
void Clear(struct list_edge* list);