/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:30:56 by yooshima          #+#    #+#             */
/*   Updated: 2025/01/27 15:44:31 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form {
 public:
  Form(const std::string& name, const int signGrade, const int executeGrade);
  Form(const Form& src);
  ~Form();
  Form& operator=(const Form& src);
  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };
  void beSigned(Bureaucrat& src);
  const std::string& getName() const;
  const bool getIsSigned() const;
  const int getSignGrade() const;
  const int getExecuteGrade() const;

 private:
  const std::string _name;
  bool _isSigned;
  const int _requiredSignGrade;
  const int _requiredExecuteGrade;
};

std::ostream& operator<<(std::ostream& ostream, const Form& src);

#endif
