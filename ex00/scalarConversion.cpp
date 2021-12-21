/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 02:22:06 by mjung             #+#    #+#             */
/*   Updated: 2021/12/22 02:22:20 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalarConversion.hpp"

scalarConversion::scalarConversion()
{
}

scalarConversion::scalarConversion(char* _input)
{
	cInput_ = _input;
	sInput_ = static_cast<std::string>(_input);

	try {
		value_ = std::stod(_input);
	}
	catch(...)
	{
		isImpossible_ = true;
	}
}

scalarConversion::~scalarConversion()
{
}

scalarConversion::scalarConversion(const scalarConversion &_target)
{
	cInput_ = _target.cInput_;
	sInput_ = _target.sInput_;
	value_ = _target.value_;
	isImpossible_ = _target.isImpossible_;
}

scalarConversion &scalarConversion::operator=(const scalarConversion &_target)
{
	cInput_ = _target.cInput_;
	sInput_ = _target.sInput_;
	value_ = _target.value_;
	isImpossible_ = _target.isImpossible_;

	return (*this);
}


void scalarConversion::toChar()
{
	std::cout << "char: ";
	if (isImpossible_ || isnan(value_))
		std::cout << "impossible";
	else if (isprint(value_) == false)
		std::cout << "Non displayable";
	else
		std::cout << static_cast<char>(value_);
	std::cout << std::endl;
}

void scalarConversion::toInt()
{
	std::cout << "int: ";
	if (isImpossible_ || isnan(value_) || value_ > INT_MAX)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value_);
	std::cout << std::endl;
}

void scalarConversion::toFloat()
{
	std::cout << "float: ";
	if (isImpossible_ || isnan(value_) || value_ > FLT_MAX)
		std::cout << "nanf";
	else
		std::cout << static_cast<float>(value_) << 'f';
	std::cout << std::endl;
}

void scalarConversion::toDouble()
{
	std::cout << "double: ";
	if (isImpossible_ || isnan(value_))
		std::cout << "nan";
	else
		std::cout << static_cast<double>(value_);
	std::cout << std::endl;
}

