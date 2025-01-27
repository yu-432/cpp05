/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:38:40 by yooshima          #+#    #+#             */
/*   Updated: 2025/01/27 14:58:58 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, const int signGrade, const int executeGrade)
    : _name(name),
      _isSigned(false),
      _requiredSignGrade(signGrade),
      _requiredExecuteGrade(executeGrade) {}

Form::Form(const Form& src)
    : _name(src._name),
      _isSigned(src._isSigned),
      _requiredSignGrade(src._requiredSignGrade),
      _requiredExecuteGrade(src._requiredExecuteGrade) {}

Form& Form::operator=(const Form& src) {
  if (this != &src) {
    _isSigned = src._isSigned;
  }
  return *this;
}

Form::~Form() {
}

