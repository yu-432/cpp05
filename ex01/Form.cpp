/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:38:40 by yooshima          #+#    #+#             */
/*   Updated: 2025/02/01 13:25:49 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("defaultForm"), _isSigned(false), _requiredSignGrade(1), _requiredExecuteGrade(1) {}

Form::Form(const std::string& name, const int signGrade, const int executeGrade)
    : _name(name),
      _isSigned(false),
      _requiredSignGrade(signGrade),
      _requiredExecuteGrade(executeGrade) {
        if (signGrade < 1 || executeGrade < 1) throw GradeTooHighException();
        if (signGrade > 150 || executeGrade > 150) throw GradeTooLowException();
      }

Form::Form(const Form& src)
    : _name(src._name),
      _isSigned(src._isSigned),
      _requiredSignGrade(src._requiredSignGrade),
      _requiredExecuteGrade(src._requiredExecuteGrade) {}

Form::~Form() {}

Form& Form::operator=(const Form& src) {
  if (this != &src) {
    _isSigned = src._isSigned;
  }
  return *this;
}

const char* Form::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

void Form::beSigned(Bureaucrat& src) {
  if (src.getGrade() > _requiredSignGrade) throw GradeTooLowException();
  _isSigned = true;
}

const std::string& Form::getName() const {
  return _name;
}

bool Form::getIsSigned() const {
  return _isSigned;
}

int Form::getSignGrade() const {
  return _requiredSignGrade;
}

int Form::getExecuteGrade() const {
  return _requiredExecuteGrade;
}

std::ostream& operator<<(std::ostream& ostream, const Form& src) {
  std::cout << src.getName() << ", isSigned: " << src.getIsSigned() << " signGrade: " << src.getSignGrade() << " ecuteGrade: " << src.getExecuteGrade() << std::endl;
  return ostream;
}
