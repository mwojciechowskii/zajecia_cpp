#include <iostream>

int f(int x) {
	return 2*x+2;
}
int absolute(int x) {
	if (x < 0)
		return -x;
	else
		return x;

}


int main(){
	int x;
	
	std::cin >> x;
	int y = f(x);
	
	std::cout << y << std::endl;
	return 0;


}
