/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:30:56 by yooshima          #+#    #+#             */
/*   Updated: 2025/02/02 13:08:07 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 public:
  Form();
  Form(const std::string& name, const int signGrade, const int executeGrade);
  Form(const Form& src);
  ~Form();

  Form& operator=(const Form& src);

  const std::string& getName() const;
  bool getIsSigned() const;
  int getSignGrade() const;
  int getExecuteGrade() const;

  void beSigned(Bureaucrat& src);

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };

 private:
  const std::string _name;
  bool _isSigned;
  const int _requiredSignGrade;
  const int _requiredExecuteGrade;
  static const int minGrade;
  static const int maxGrade;
};

std::ostream& operator<<(std::ostream& ostream, const Form& src);

#endif
