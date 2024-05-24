#include <iostream>
#include "decorator.h"


int main() {
	auto paragraph_block = new Paragraph(new Text());
	paragraph_block->render("Paragraph");
	std::cout << std::endl;

	auto reverse_text_block = new Reversed (new Text());
	reverse_text_block->render("Reverse_Text");
	std::cout << std::endl;

	auto link_block = new Link(new Text());
	link_block->render("netology.ru", "Link");
	std::cout << std::endl;

	return 0;
}