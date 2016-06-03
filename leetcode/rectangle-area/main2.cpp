#include <iostream>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int area = (D-B)*(C-A) + (H-F)*(G-E);
		if(C<=E || H<=B || A>=G || D<=F){
			return area;
		}
		int top = min(H,D);
		int right = min(C,G);
		int bottom = max(B,F);
		int left = max(A,E);
		return area-(top-bottom)*(right-left);
    }
};

int main(){
	return 0;
}
