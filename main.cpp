#include <cstdlib>
#include <iostream>

#include "vector.h"

using namespace std;

/*segmentation fault core error
int convert_dimensions(int *current, int *size, int dimensions, int repetitions = 0)
{
	int part1 = *current;
	int part2 = *size;
	int part3 = 0;
	if(repetitions < dimensions)
		part3 = convert_dimensions(current+1,size+1,dimensions);
	else
		part3 = *(current+1);
	return part1 + part2 * part3;

}
template <typename T>
struct Dimensions {      
    int operator()(int* coordinates, int* sizes, int dimensions) {
    	return convert_dimensions(coordinates,sizes,dimensions);    
    }
};
*/
int convert_dimensions(int *start, int *current,int *size, int dimensions)
{
	
	int p1 = *current; 
	int p2 = *size;
	int p3 = 0;
	if((start+dimensions-1)!=(current+1))
		p3 = convert_dimensions(start,current+1,size+1,dimensions);
	else
		p3 = *(current+1);

	return p1+p2*p3; 
}

template <typename T>
struct Dimensions {      
    int operator()(int* coordinates, int* sizes, int dimensions) {
    	return convert_dimensions(coordinates,coordinates,sizes,dimensions);    
    }
};


struct Integer {
       typedef int T;
       typedef Dimensions<T> Operation;
};

int main(int argc, char *argv[]) {
	int coordinates[] = {0,0,0,0};
	int sizes[] = {1,1,1,0};
	int *crt = sizes;
	int *crt_coor = coordinates;
	Vector<Integer> vector_dimensions(4, crt);
	vector_dimensions.set(2,crt_coor);
	cout << vector_dimensions.get(crt_coor) << "\n";
    system("pause");
    return EXIT_SUCCESS;
}