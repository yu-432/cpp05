/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:17:35 by yooshima          #+#    #+#             */
/*   Updated: 2025/01/29 15:25:33 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
  Bureaucrat b1("bur1", 5);
  Bureaucrat b2("bur2", 150);
  // AForm f1("cleaning", 140, 150);
  ShrubberyCreationForm s1("home");
  RobotomyRequestForm r1("Tom");
  PresidentialPardonForm p1("ara");

  b2.signForm(s1);
  b2.executeForm(s1);
  b1.executeForm(s1);
  b1.signForm(s1);
  b2.executeForm(s1);
  b1.executeForm(s1);
  
  b2.signForm(r1);
  b1.signForm(r1);
  b2.executeForm(r1);
  b1.executeForm(r1);

  b2.signForm(p1);
  b1.signForm(p1);
  b2.executeForm(p1);
  b1.executeForm(p1);
}
