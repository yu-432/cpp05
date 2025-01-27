/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:17:35 by yooshima          #+#    #+#             */
/*   Updated: 2025/01/26 16:59:52 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
  Bureaucrat b1("bur1", 2);
  Bureaucrat b2("bur2", 149);

  std::cout << b1 << std::endl;
  try {
    b1.incrementGrade();
    std::cout << b1 << std::endl;
    b1.incrementGrade();
    std::cout << b1 << std::endl;
    b1.incrementGrade();
    b1.incrementGrade();
  } catch (std::exception& e) {
    std::cerr << e.what();
  }
  std::cout << b1 << std::endl;

  std::cout << b2 << std::endl;
  try {
    b2.decrementGrade();
    std::cout << b2 << std::endl;
    b2.decrementGrade();
    std::cout << b2 << std::endl;
    b2.decrementGrade();
    b2.decrementGrade();
  } catch (std::exception& e) {
    std::cerr << e.what();
  }
}
