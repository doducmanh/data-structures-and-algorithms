/*Viết chương trình C++ cài đặt cấu trúc dữ liệu cây nhị phân tìm kiếm
  Họ và tên SV: Đỗ Đức Mạnh
  MSSV: 21880234
*/
#include <iostream>

using namespace std;

struct NODE {
    int key;
    NODE *pLeft;
    NODE *pRight;
};

/* Yêu cầu 1. Khởi tạo một NODE từ một số nguyên k chuẩn bị thêm vào cây nhị phân tìm kiếm*/
NODE* createNode(int k) {
    NODE* p = new NODE();

    /*Sinh viên tự hoàn thành đoạn code này*/
	p->key = k;
	p->pLeft = NULL;
	p->pRight = NULL;
    return p;
}

/* Yêu cầu 2. Viết hàm thêm số nguyên k vào vào cây nhị phân tìm kiếm */
void insertNode(NODE* &pRoot, int k) {
	if (pRoot == NULL) {
		Node* p = createNode(k);	//Tạo NODE p từ số nguyên k
		pRoot = p;
	}
	else if (k < pRoot->key) {
		insertNode(pRoot->pLeft, k);
	}
	else if (k > pRoot->key) {
		insertNode(pRoot->pRight, k);
	}
}

/* Yêu cầu 3. Viết hàm duyệt trước NLR */
void NLR(NODE* pRoot) {
    /*Sinh viên tự hoàn thành đoạn code này*/
	if(pRoot == NULL) return; //ĐK dừng đệ quy
	count << pRoot->key;	  //N
	NLR(pRoot->pLeft);		  //L
	NLR(pRoot->pRight);	      //R
}

/* Yêu cầu 4. Viết hàm duyệt giữa LNR */
void LNR(NODE* pRoot) {
    /*Sinh viên tự hoàn thành đoạn code này*/
	if(pRoot == NULL) return; //ĐK dừng đệ quy
	NLR(pRoot->pLeft);		  //L
	count << pRoot->key;	  //N
	NLR(pRoot->pRight);	      //R
}

/* Yêu cầu 5. Viết hàm duyệt sau LRN */
void LRN(NODE* pRoot) {
    /*Sinh viên tự hoàn thành đoạn code này*/
	if(pRoot == NULL) return; //ĐK dừng đệ quy
	NLR(pRoot->pLeft);		  //L
	NLR(pRoot->pRight);	      //R
	count << pRoot->key;	  //N
}

/* Yêu cầu 6. Viết hàm tìm kiếm số nguyên k trong cây nhị phân tìm kiếm. 
Nếu có trả về true. Ngược lại trả về false. */
bool searchData(NODE *pRoot, int k) {

	/*Sinh viên tự hoàn thành đoạn code này*/
	if(pRoot == NULL) {
		return false;
	}
	else if (k == pRoot->key) {
		return true
	}
	else if (k < pRoot->key) {
		return searchData(pRoot->pLeft,k);
	}
	else if (k > pRoot->key) {
		return searchData(pRoot->pRight,k);
	}

}

/* Yêu cầu 6. Hoàn thành hàm main() theo yêu cầu */
int main() {
    Node* pRoot = NULL;
	int k;
	int m;
	do
	{
		cout << "Nhap gia tri cua Node (Nhap -1 de ngung thao tac): ";
		cin >> k;		
		if (k != -1)
		{
			/*Thêm k vào cây nhị phân tìm kiếm - Sinh viên tự hoàn thành đoạn code này*/
			insertNode(pRoot, k);
		}		
	} while (input != -1);

    /*In toàn bộ số nguyên trong cây theo phép duyệt trước - Sinh viên tự hoàn thành đoạn code này*/
    cout << "NLR: ";
	NLR(pRoot);

    /*In toàn bộ số nguyên trong cây theo phép duyệt giữa - Sinh viên tự hoàn thành đoạn code này*/
    cout << "LNR: ";
	LNR(pRoot);

    /*In toàn bộ số nguyên trong cây theo phép duyệt sau - Sinh viên tự hoàn thành đoạn code này*/
    cout << "LRN: ";
	LRN(pRoot);

    /*Nhập vào số nguyên k và kiểm tra k có trong cây hay không - Sinh viên tự hoàn thành đoạn code này*/	
	cout << "Nhập vào số nguyên k và kiểm tra k có trong cây hay không: ";
	cin >> m;
	searchData(pRoot, m);

    return 0;
}

