void search(char *, char **);
struct pos {
	struct items *begin;
	struct items *end;
	int items;
};
struct items {
	char a[40];
	struct items *next;
};
bool getQ(char item[40], struct pos *number);
void deleteAll(struct pos *);
void deleteQ(struct pos *);
