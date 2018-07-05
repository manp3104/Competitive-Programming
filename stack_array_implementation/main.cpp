#include <iostream>
#include <cstdio>

using namespace std;

struct stack {
	int top;
	int capacity;
	int* array;
};

struct stack* createStack(int n) {
	struct stack* st = new struct stack;

	st->top = -1;
	st->capacity = n;
	st->array = new int[n];

	return st;
}

bool isEmpty(struct stack* st) {
	return (st->top==-1);
}

bool isFull(struct stack* st) {
	return (st->top==st->capacity-1);
}

void push(struct stack* st, int num) {
	if(isFull(st)) {
		cout << "Overflow!!!...";
		return;
	}
	st->array[++st->top] = num;
}

int pop(struct stack* st) {
	if(isEmpty(st)) {
		cout << "Underflow!!!...";
		return 0;
	}
	st->top = st->top-1;
	return st->array[st->top-1];
}

void deleteStack(struct stack* st) {
	if(st) {
		if(st->array)
			delete[] st->array;
		delete st;
	}
}

void print(struct stack* st) {
	if(!isEmpty(st)) {
		for(int i=0;i<=st->top;i++)
			cout << st->array[i] << " ";
		cout << endl;
	}
}

void findTop(struct stack* st) {
	if(isEmpty(st)) {
		cout << "No elements are available.";
		return;
	}
	cout << st->array[st->top] << endl;
}

int main() {
	freopen("input.txt","r", stdin);
	// freopen("ouput.txt", "w", stdout);b

	int n;
	cin >> n;

	struct stack* st = createStack(n);

	push(st, 10);
	push(st, 20);
	push(st, 30);

	print(st);
	cout << pop(st) << endl;
	print(st);
	findTop(st);



	return 0;

}