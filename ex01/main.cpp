#include <iostream>

// 임의의 데이터 구조
typedef struct s_Data
{
	std::string data;
} Data;

// reinterpret_cast : 임의의 포인터끼리 변환 가능한 캐스팅
uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}



int main(void)
{
	Data test;

	test.data = "mjung";

	uintptr_t a;
	Data *b;

	a = serialize(&test);
	b = deserialize(a);

// 원본 주소값과 deserialize의 리턴값이 같은지 확인
	std::cout << &test << std::endl;
	std::cout << b << std::endl;

	return (0);
}
