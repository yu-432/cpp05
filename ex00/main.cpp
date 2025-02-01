/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:17:35 by yooshima          #+#    #+#             */
/*   Updated: 2025/02/01 10:08:47 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
  Bureaucrat b1("bur1", 2);
  Bureaucrat b2("bur2", 149);

  try {
    Bureaucrat b3("bur3", 0);
  } catch (std::exception& e) {
    std::cerr << e.what();
  }

  try {
    Bureaucrat b4("bur4", 151);
  } catch (std::exception& e) {
    std::cerr << e.what();
  }

  std::cout << b1;
  try {
    b1.incrementGrade();
    std::cout << b1;
    b1.incrementGrade();
    std::cout << b1;
    b1.incrementGrade();
    b1.incrementGrade();
  } catch (std::exception& e) {
    std::cerr << e.what();
  }
  std::cout << b1;

  std::cout << b2;
  try {
    b2.decrementGrade();
    std::cout << b2;
    b2.decrementGrade();
    std::cout << b2;
    b2.decrementGrade();
    b2.decrementGrade();
  } catch (std::exception& e) {
    std::cerr << e.what();
  }
}
