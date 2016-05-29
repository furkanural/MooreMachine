#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN(x)  (sizeof(x) / sizeof((x)[0]))

typedef struct State State;
typedef struct Path Path;

struct State {
	char in[20];
	char out[20];
	State *next;
	Path *start;
};

struct Path{
	char value[20];
	State *current;
	State *next_state;
	Path *next;
};

State *head=NULL;

State *new_state(char in[20], char out[20]) {
	State *node = (State *)malloc(sizeof(State));
	strcpy_s(node->in, in);
	strcpy_s(node->out, out);
	node->next = NULL;
	node->start = NULL;
	return node;
}
Path *new_path(char val[20], State *current, State *next) {
	Path *node = (Path *)malloc(sizeof(Path));
	strcpy_s(node->value, val);
	node->next = NULL;
	node->next_state = next;
	node->current = current;
	return node;
}
State *add_state(State *node) {
	if (head == NULL)
		head = node;
	else
	{
		State *start = head;
		while ((*start).next != NULL)
		{
			start = (*start).next;
		}
		(*start).next = node;
	}
	return node;
}

State *add_state(char in[20], char out[20], bool finish){
	State *node = new_state(in, out);
	return add_state(node);
}


Path *add_path(Path *node) {
	if (node->current->start == NULL)
		node->current->start = node;
	else {
		Path *start = node->current->start;
		while ((*start).next != NULL)
		{
			start = (*start).next;
		}
		(*start).next = node;
	}
	return node;
}

Path *add_path(char val[20], State *current, State *next){
	Path *node = new_path(val,current,next);
	return add_path(node);
}

void initialize() {
	State states[4];
	states[0] = *new_state("q0", "0");
	states[1] = *new_state("q1", "0");
	states[2] = *new_state("q2", "1");
	states[3] = *new_state("q3", "0");

	Path paths[8];
	paths[0] = *new_path("a", &states[0], &states[3]);
	paths[1] = *new_path("b", &states[0], &states[2]);
	paths[2] = *new_path("a", &states[1], &states[1]);
	paths[3] = *new_path("b", &states[1], &states[0]);
	paths[4] = *new_path("a", &states[2], &states[2]);
	paths[5] = *new_path("b", &states[2], &states[3]);
	paths[6] = *new_path("a", &states[3], &states[0]);
	paths[7] = *new_path("b", &states[3], &states[1]);

	for (int i = 0; i < LEN(states); i++)
	{
		add_state(&states[i]);
	}
	for (int i = 0; i < LEN(paths); i++)
	{
		add_path(&paths[i]);
	}
}

char *run_machine(char inputs[][20], int pattern_size) {
	/*State *iterator = head;
	char *output = "";
	for (int i = 0; i < pattern_size; i++)
	{
		char * str3 = (char *)malloc(1 + strlen(output) + strlen(iterator->out));
		strcpy(str3, output);
		strcat(str3, iterator->out);
		strcpy(output, str3);

		Path *start_path = iterator->start;
		while (start_path != NULL)
		{
			if (strcmp(start_path->value, inputs[i]) == 0)
			{
				break;
			}
			start_path = start_path->next;
		}
		if (start_path == NULL)
			output = "This machine not works";
		else
			iterator = start_path->next_state;
	}*/
	return "";
}


void main() {
	
	initialize();
	char inputs[7][20];
	strcpy(inputs[0], "b");
	strcpy(inputs[1], "a");
	strcpy(inputs[2], "b");
	strcpy(inputs[3], "a");
	strcpy(inputs[4], "b");
	strcpy(inputs[5], "b");
	strcpy(inputs[6], "b");
	run_machine(inputs, 7);




	return void(0);
}