/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:28:31 by yooshima          #+#    #+#             */
/*   Updated: 2025/01/27 15:57:14 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, const int grade) : _name(name) {
  if (grade < 1) throw GradeTooHighException();
  if (grade > 150) throw GradeTooLowException();
  _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) { *this = src; }

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
  if (this != &src) {
    _name = src._name;
    _grade = src._grade;
  }
  return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low\n";
}

void Bureaucrat::incrementGrade() {
  if (_grade == 1) throw GradeTooHighException();
  _grade--;
}

void Bureaucrat::decrementGrade() {
  if (_grade == 150) throw GradeTooLowException();
  _grade++;
}

const std::string& Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

std::ostream& operator<<(std::ostream& ostream, const Bureaucrat& src) {
  std::cout << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
  return ostream;
}
