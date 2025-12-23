#include<iostream>
class student {
	//ÓÑÔªÉùÃ÷ 
	friend std::ostream& operator<<(std::ostream& create_cout, student& other);
	friend std::istream& operator>>(std::istream& create_cin, student& other);
private:
	int m_num1;
	int m_num2;
};
//×óÒÆÔËËã·ûÖØÔØ
std::ostream& operator<<(std::ostream& create_cout, student& other) {
	create_cout << "m_num1 = " << other.m_num1 << ' ' << "m_num2 = " << other.m_num2 << std::endl;
	return create_cout;
}
//ÓÒÒÆÔËËã·ûÖØÔØ
std::istream& operator>>(std::istream& create_cin, student& other) {
	create_cin >> other.m_num1 >> other.m_num2;
	return create_cin;
}
void test() {
	student p1,p2;
	std::cin >> p1 >> p2 ;
	std::cout << p1 << p2 << "LOVE C++";
}
int main() {
	test();
	return 0;
}
