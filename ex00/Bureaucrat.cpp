/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:28:31 by yooshima          #+#    #+#             */
/*   Updated: 2025/02/02 12:40:55 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const int Bureaucrat::minGrade = 150;
const int Bureaucrat::maxGrade = 1;

Bureaucrat::Bureaucrat() : _name("defaultBureaucrat"), _grade(minGrade) {};

Bureaucrat::Bureaucrat(const std::string& name, const int grade) : _name(name) {
  if (grade < maxGrade) throw GradeTooHighException();
  if (grade > minGrade) throw GradeTooLowException();
  _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) { *this = src; }

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
  if (this != &src) {
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
  if (_grade == maxGrade) throw GradeTooHighException();
  _grade--;
}

void Bureaucrat::decrementGrade() {
  if (_grade == minGrade) throw GradeTooLowException();
  _grade++;
}

const std::string& Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

std::ostream& operator<<(std::ostream& ostream, const Bureaucrat& src) {
  std::cout << src.getName() << ", bureaucrat grade " << src.getGrade()
            << std::endl;
  return ostream;
}
