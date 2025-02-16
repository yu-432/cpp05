/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:38:40 by yooshima          #+#    #+#             */
/*   Updated: 2025/01/28 15:21:49 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const int AForm::minGrade = 150;
const int AForm::maxGrade = 1;

AForm::AForm()
    : _name("defaultAForm"),
      _isSigned(false),
      _requiredSignGrade(maxGrade),
      _requiredExecuteGrade(maxGrade) {}

AForm::AForm(const std::string& name, const int signGrade,
             const int executeGrade)
    : _name(name),
      _isSigned(false),
      _requiredSignGrade(signGrade),
      _requiredExecuteGrade(executeGrade) {
  if (signGrade < maxGrade || executeGrade < maxGrade)
    throw GradeTooHighException();
  if (signGrade > minGrade || executeGrade > minGrade)
    throw GradeTooLowException();
}

AForm::AForm(const AForm& src)
    : _name(src._name),
      _isSigned(src._isSigned),
      _requiredSignGrade(src._requiredSignGrade),
      _requiredExecuteGrade(src._requiredExecuteGrade) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& src) {
  if (this != &src) {
    _isSigned = src._isSigned;
  }
  return *this;
}

void AForm::beSigned(Bureaucrat& src) {
  if (src.getGrade() > _requiredSignGrade) throw GradeTooLowException();
  _isSigned = true;
}

const std::string& AForm::getName() const { return _name; }

bool AForm::getIsSigned() const { return _isSigned; }

int AForm::getSignGrade() const { return _requiredSignGrade; }

int AForm::getExecuteGrade() const { return _requiredExecuteGrade; }

void AForm::execute(Bureaucrat const& executor) const {
  if (!this->getIsSigned()) throw NotSignedException();
  if (_requiredExecuteGrade < executor.getGrade())
    throw NotExecutableException();
  executeAction();
}

const char* AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

const char* AForm::NotSignedException::what() const throw() {
  return "No signatures";
}

const char* AForm::NotExecutableException::what() const throw() {
  return "Grade is too low to execute";
}

std::ostream& operator<<(std::ostream& ostream, const AForm& src) {
  std::cout << src.getName() << ", isSigned: " << src.getIsSigned()
            << " signGrade: " << src.getSignGrade()
            << " executeGrade: " << src.getExecuteGrade() << std::endl;
  return ostream;
}
