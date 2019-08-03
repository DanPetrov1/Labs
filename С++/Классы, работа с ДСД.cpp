/*11. ѕостроить класс дл€ работы с двусв€зным списком. Ёлементы
списка Ц действительные числа. —оздать список List1, содержащий
последовательность x1 x2 , , ... , x(n). ѕостроить список List2, содержащий последовательность x1, x(n), x2, x(n-1), ... x(n), 1. */
#include<iostream>
using namespace std;
typedef struct list {
	double a;
	struct list *next;
	struct list *previous;
} List;
class lists {
public:
	List *root;
	List *last;
	lists();
	~lists();
};
lists::lists() {
	int i, n;
	cout << "¬ведите количество элементов списка: ", cin >> n;
	while (!cin || n < 1) {
		cin.clear();
		cin.get();
		cin >> n;
	}
	List *k = (List*)malloc(sizeof(List));
	if (!k)
		return;
	for (i = 0; i <= n; i++) {
		if (i == 0) {
			k->previous = NULL;
			k->next = NULL;
			cout << "¬ведите число: ", cin >> k->a;
			while (!cin) {
				cin.clear();
				cin.get();
				cin >> k->a;
			}
			root = k;
			last = k;
			i++;
		}
		else {
			List *z = (List*)malloc(sizeof(List));
			if (!z)
				return;
			cout << "¬ведите число: ", cin >> z->a;
			while (!cin) {
				cin.clear();
				cin.get();
				cin >> z->a;
			}
			z->next = NULL;
			last->next = z;
			z->previous = last;
			last = z;
		}
	}
}
void made(List *, List *);
int main() {
	system("chcp 1251>null");
	lists *list = new lists[1];
	List *current = list->root;
	List *prev = list->last;
	made(current, prev);
	getchar();
	getchar();
	return 0;
}
void made(List *current, List *prev) {
	List *now = NULL;
	List *head = NULL;
	while (current != NULL) {
		List*same = (List*)malloc(sizeof(List));
		if (!same)
			return;
		same->next = (List*)malloc(sizeof(List));
		if (!same->next)
			return;
		if (head == NULL) {
			same->a = current->a;
			same->previous = NULL;
			same->next->previous = same;
			same->next->a = prev->a;
			head = same;
			now = same;
			now = now->next;
		}
		else {
			same->previous = now;
			now->next = same;
			same->a = current->a;
			now = now->next;
			now->next = same->next;
			now->next->previous = now;
			same->next->a = prev->a;
			now = now->next;
			now->next = NULL;
		}
		current = current->next;
		prev = prev->previous;
	}
	current = head;
	while (current != NULL) {
		cout << current->a << " ";
		current = current->next;
	}
}
lists::~lists() {
	while (root != NULL) {
		List *q = root;
		root = root->next;
		free(q);
	}
}