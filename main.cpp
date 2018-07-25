#include <iostream>

using std::cout;
using std::endl;

int Max (int*, int);
int Min (int*, int);
int Average(int*, int);

void DoSomething(int*, int, int(*)(int*, int));



int main(int argc, char* argv[]){

	int numbers[] = {7, 12, 11, 1, 90, 41, 22, 54, 2, 5};

	DoSomething(numbers, sizeof(numbers)/sizeof(numbers[0]), Min);
	DoSomething(numbers, sizeof(numbers)/sizeof(numbers[0]), Max);
	DoSomething(numbers, sizeof(numbers)/sizeof(numbers[0]), Average);

	return 0;
}



int Max (int* array, int size){
	int max = array[0];
	for (int i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}
int Min (int* array, int size){
	int min = array[0];
	for (int i = 1; i < size; i++)
		if (array[i] < min)
			min = array[i];
	return min;
}
int Average(int* array, int size){
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += array[i];
	return sum / size;
}


void DoSomething(int* data, int size, int(* operation)(int*, int)){
	cout << "Operation = " << operation(data, size) << endl;
}
