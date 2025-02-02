/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:09:02 by yooshima          #+#    #+#             */
/*   Updated: 2025/02/02 13:11:05 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 public:
  Intern();
  Intern(const Intern& src);
  ~Intern();

  Intern& operator=(const Intern& src);

  AForm* makeForm(const std::string formName, const std::string formTarget);

 private:
  struct FormType {
    const char* formName;
    AForm* (*createForm)(const std::string&);
  };
  static FormType _FormType[];
};
