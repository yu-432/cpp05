/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:17:41 by yooshima          #+#    #+#             */
/*   Updated: 2025/02/02 13:08:22 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#include "Form.hpp"

class Form;

class Bureaucrat {
 public:
  Bureaucrat();
  Bureaucrat(const std::string& name, const int grade);
  Bureaucrat(const Bureaucrat& src);
  ~Bureaucrat();

  Bureaucrat& operator=(const Bureaucrat& src);

  const std::string& getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();
  void signForm(Form& form);

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
  int _grade;
  static const int maxGrade;
  static const int minGrade;
};

std::ostream& operator<<(std::ostream& ostream, const Bureaucrat& src);

#endif
