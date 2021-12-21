/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 02:22:24 by mjung             #+#    #+#             */
/*   Updated: 2021/12/22 02:23:52 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERSION_HPP
#define SCALARCONVERSION_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <cfloat>

class scalarConversion
{

public:
	scalarConversion();
	scalarConversion(char* _input);
	virtual ~ scalarConversion();
	scalarConversion(const scalarConversion &_target);
	scalarConversion &operator=(const scalarConversion &_target);

	void toChar();
	void toInt();
	void toFloat();
	void toDouble();

private:

	char *cInput_;
	std::string sInput_;
	double value_;
	bool isImpossible_;
};


#endif
