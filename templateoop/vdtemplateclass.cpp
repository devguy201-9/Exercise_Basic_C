#include<iostream>
using namespace std;
template<class T>class Data {
private:
	T* data;
	size_t size;
public:
	Data(T*,size_t);
	void showData();
	void copyData(T*, size_t);
};
template<class T>Data<T>::Data(T* data, size_t size) {
	this->data = new T[size];
	this->size = size;
	this->copyData(data, size);
}
template<class T>void Data<T>::copyData(T* data, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		this->data[i] = data[i];
	}
}
template<class T>void Data<T>::showData() {
	for (size_t i = 0; i < size; i++)
	{
		cout << this->data[i] << " ";
	}
	cout << endl;
}
int main()
{
	int a[] = { 1,2,3,4,5,6,7,6 };
	Data<int> abc(a, sizeof(a) / sizeof(int));
	abc.showData();
	return 0;
}