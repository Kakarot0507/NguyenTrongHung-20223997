//Ex1 
#include <iostream>

// Hàm hoán đổi giá trị giữa hai biến
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sortColors(int colors[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (colors[mid] == 0) { // Đỏ
            swap(colors[low], colors[mid]);
            low++;
            mid++;
        }
        else if (colors[mid] == 1) { // Trắng
            mid++;
        }
        else { // Xanh
            swap(colors[mid], colors[high]);
            high--;
        }
    }
}

int main() {
    int n;
    std::cout << "Nhập số lượng đối tượng: ";
    std::cin >> n;

    int colors[100]; // Giả sử tối đa 100 đối tượng
    std::cout << "Nhập các đối tượng (0: đỏ, 1: trắng, 2: xanh): ";
    for (int i = 0; i < n; ++i) {
        std::cin >> colors[i];
    }

    sortColors(colors, n);

    std::cout << "Kết quả sắp xếp: ";
    for (int i = 0; i < n; ++i) {
        std::cout << colors[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
//EX2 
#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int songuyento(int n){
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0){
			return 0;
		} 
	}
	return 1;
} 
int soNUAnguyento(int n){
	for(int i=2; i<n; i++ ){
		for(int j=2; j<n; j++){
			if(songuyento(i)&&songuyento(j)==1){
				if(i*j==n){
					return 1;
				}
			}
		}
	}return 0;
}
int main(){
	int a[100], blumNumber[100];
	int count=0;
	for(int i=0;i<100;i++){
		a[i]=i+1;
	}
	for(int i=0;i<100;i++){
		if(soNUAnguyento(a[i])==1){
			blumNumber[count++]=a[i];	 
		}	
	}
	for(int i=0;i<count;i++){
		for(int j=0;j<count;j++){
			int sum=blumNumber[j]+blumNumber[i];
			for(int k=0;k<count;k++){
				if(sum==blumNumber[k]){  //tong 2 so blum bang so 1 blum trong day blumNumber
					cout << "(" << blumNumber[i] << ", " << blumNumber[j] << ")" << endl;
				}
			}
		}		
	}
	int M;
	bool check=false;
	cout<<"nhap M:";
	cin>>M;
	for(int i=0;i<count;i++){
		if(M==blumNumber[i]){
			check=true;//cout<<"M co ton tai trong day Blum"<< endl;
		} 
	}
	if(check==true){
		cout<<"M co ton tai trong day Blum"<< endl;
	} else cout<<"khong ton tai";	 
}
    return 0;
}
