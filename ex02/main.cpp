/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:03:39 by mjung             #+#    #+#             */
/*   Updated: 2021/12/22 18:03:40 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <random>

// 무작위로 A,B,C를 인스턴스화 하고 Base 포인터로 리턴
Base *generate(void)
{
	Base *rtn;

	// 시드값을 얻기 위한 random_device 생성.
	std::random_device rd;
	// random_device 를 통해 난수 생성 엔진을 초기화 한다.
	std::mt19937 gen(rd());
	// 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	std::uniform_int_distribution<int> dis(1, 3);
	int random = dis(gen);
	if (random == 1)
		rtn = new A;
	else if (random == 2)
		rtn = new B;
	else if (random == 3)
		rtn = new C;
	return (rtn);
}

// dynamic_cast 형변환 실패시 NULL pointer 리턴
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

// dynamic_cast 형변환 실패시 NULL pointer 리턴
void identify(Base &p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(std::bad_cast) {
	}
	try {
		B &b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch(std::bad_cast) {
	}
	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(std::bad_cast) {
	}

}

int main(void)
{

	for(int i=0; i<3; i++)
	{
		Base *base = generate();
		identify(base);
		identify(*base);
	}
}
