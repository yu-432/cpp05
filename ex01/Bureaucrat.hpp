/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:17:41 by yooshima          #+#    #+#             */
/*   Updated: 2025/02/01 10:09:16 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Form;

class Bureaucrat {
 public:
  Bureaucrat(const std::string& name, const int grade);
  Bureaucrat(const Bureaucrat& src);
  ~Bureaucrat();
  void incrementGrade();
  void decrementGrade();
  void signForm(Form& form);
  const std::string& getName() const;
  int getGrade() const;
  Bureaucrat& operator=(const Bureaucrat& src);
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
};

std::ostream& operator<<(std::ostream& ostream, const Bureaucrat& src);

#endif
