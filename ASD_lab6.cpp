#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
struct deque {
	int size;
	int *p;
	int pend;
	int pbeg;
};
void init_deque(deque *s, int n) {
	s->p = new int[n];
	s->size = n;
	s->pbeg = 0;
	s->pend = n;
}
int pop_begin_deque(deque *s) {
	int temp = s->p[s->pbeg];
	s->p[s->pbeg] = s->p[s->pbeg + 1];
	s->pbeg--;
	return temp;
}
int pop_end_deque(deque *s) {
	int temp = s->p[s->pend];
	s->p[s->pend] = s->p[s->pend - 1];
	s->pend++;
	return temp;
}
void push_begin_deque(deque *s, int i) {
	s->p[s->pbeg++] = i;
}
void push_end_deque(deque *s, int i) {
	s->p[s->pend--] = i;
}
void print_begin_deque(deque *s) {
	for (int i = 0; i < s->pbeg; i++)
		cout << s->p[i] << " ";
}
void print_end_deque(deque *s) {
	for (int i = s->pend + 1; i < s->size + 1; i++)
		cout << s->p[i] << " ";
	cout << endl;
}
void del_deque(deque *s) {
	delete[] s->p;
}
bool emptinnes_begin_deque(deque *s) {
	if (s->pbeg == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool emptinnes_end_deque(deque *s) {
	if (s->pend == s->size) {
		return true;
	}
	else {
		return false;
	}
}
struct queue {
	int size;
	int *p;
	int pend;
	int pbeg;
};
void init_queue(queue *s, int n) {
	s->p = new int[n];
	s->size = n;
	s->pbeg = 0;
	s->pend = 0;
}
void push_begin_queue(queue *s, int i) {
	s->p[s->pbeg++] = i;
}
int pop_queue(queue *s) {
	int temp = s->p[s->pend];
	s->pbeg--;
	return temp;
}
void print_begin_queue(queue *s) {
	for (int i = s->pend; i < s->pbeg; i++)
		cout << s->p[i] << " ";
	cout << endl;
}
void del_queue(queue *s) {
	delete[] s->p;
}
bool emptiness_queue(queue *s) {
	if (s->pbeg == 0) {
		return true;
	}
	else {
		return false;
	}
}
struct steck {
	int size;
	int *p;
	int top;
};
void init_steck(steck *s, int n) {
	s->p = new int[n];
	s->size = n;
	s->top = 0;
}
void push(steck *s, int i) {
	s->p[s->top++] = i;
}
int pop(steck *s) {
	s->top--;
	int temp = s->p[s->top];
	int del = s->top + 1;
	s->p[s->top] = s->p[del];
	return temp;
}
void del_steck(steck *s) {
	delete[]s->p;
}
void pop_as(steck *s) {
	for (int i = s->top - 1; i >= 0; i--)
		cout << s->p[i] << " ";
	cout << endl;

}
bool emptiness_steck(steck *s) {
	if (s->top == 0) {
		return true;
	}
	else {
		return false;
	}
}
//1-dirty dishes
//0-clean dishes
//2-no dishes
int main() {
	setlocale(0, "");
	int time = 1000;
	steck *stopka = new steck;
	init_steck(stopka, 100);
	for (int i = 0; i < 6; i++) {
		push(stopka, 1);
	}
	queue *dishw1 = new queue;
	init_queue(dishw1, 100);
	for (int i = 0; i < 5; i++) {
		push_begin_queue(dishw1, 1);
	}
	queue *dishw2 = new queue;
	init_queue(dishw2, 100);
	for (int i = 0; i < 5; i++) {
		push_begin_queue(dishw2, 1);
	}
	deque *shelf = new deque;
	init_deque(shelf, 100);
	for (int i = 0; i < 5; i++) {
		push_begin_deque(shelf, 0);
		push_end_deque(shelf, 0);
	}
	while (true) {
		int t = rand() % 7;
		for (int i = 0; i < t; i++) {
			system("cls");
			int temp;
			if (emptiness_steck(stopka)) {
				continue;
			}
			temp = pop(stopka);
			cout << "Dirty dishes: ";
			pop_as(stopka);
			if (rand() % 2) {
				push_begin_queue(dishw1, temp);
			}
			else {
				push_begin_queue(dishw2, temp);
			}
			cout << "Dishwasher?: ";
			print_begin_queue(dishw1);
			cout << "Dishwasher/: ";
			print_begin_queue(dishw2);
			cout << "Shelf: ";
			print_begin_deque(shelf);
			cout << "     ";
			print_end_deque(shelf);
			Sleep(time);
		}
		int g = rand() % 7;
		for (int i = 0; i < g; i++) {
			system("cls");
			int temp;
			cout << "Dirty dishes: ";
			pop_as(stopka);
			if (rand() % 2) {
				temp = 0;
				if (emptiness_queue(dishw1)) {
					continue;
				}
				pop_queue(dishw1);
			}
			else {
				temp = 0;
				if (emptiness_queue(dishw2)) {
					continue;
				}
				pop_queue(dishw2);
			}
			cout << "Dishwasher?: ";
			print_begin_queue(dishw1);
			cout << "Dishwasher/: ";
			print_begin_queue(dishw2);
			if (rand() % 2) {
				push_begin_deque(shelf, temp);
			}
			else {
				push_end_deque(shelf, temp);
			}
			cout << "Shelf: ";
			print_begin_deque(shelf);
			cout << "     ";
			print_end_deque(shelf);
			Sleep(time);
		}
		int h = rand() % 7;
		for (int i = 0; i < h; i++) {
			system("cls");
			int temp;
			if (rand() % 2) {
				temp = 1;
				if (emptinnes_begin_deque(shelf)) {
					continue;
				}
				pop_begin_deque(shelf);
			}
			else {
				temp = 1;
				if (emptinnes_end_deque(shelf)) {
					continue;
				}
				pop_end_deque(shelf);
			}
			push(stopka, temp);//fill with dirty dishes
			cout << "Dirty dishes: ";
			pop_as(stopka);
			cout << "Dishwasher?: ";
			print_begin_queue(dishw1);
			cout << "Dishwasher/: ";
			print_begin_queue(dishw2);
			cout << "Shelf: ";
			print_begin_deque(shelf);
			cout << "     ";
			print_end_deque(shelf);
			Sleep(time);
		}
	}
	system("pause");
	return 0;
}