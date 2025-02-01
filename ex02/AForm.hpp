/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:30:56 by yooshima          #+#    #+#             */
/*   Updated: 2025/02/01 13:31:38 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
 public:
  AForm();
  AForm(const std::string& name, const int signGrade, const int executeGrade);
  AForm(const AForm& src);
  virtual ~AForm();
  AForm& operator=(const AForm& src);
  void beSigned(Bureaucrat& src);
  void execute(Bureaucrat const& executor) const;
  const std::string& getName() const;
  bool getIsSigned() const;
  int getSignGrade() const;
  int getExecuteGrade() const;
  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };
  class NotSignedException : public std::exception {
   public:
    const char* what() const throw();
  };
  class NotExecutableException : public std::exception {
   public:
    const char* what() const throw();
  };

 protected:
  virtual void executeAction(void) const = 0;

 private:
  const std::string _name;
  bool _isSigned;
  const int _requiredSignGrade;
  const int _requiredExecuteGrade;
};

std::ostream& operator<<(std::ostream& ostream, const AForm& src);

#endif
