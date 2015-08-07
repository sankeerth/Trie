#include "trie.h"
#include <string>

Trie trie;

void insert()
{
	std::string s1 = "107.108.11.123";
	std::string s2("hell");
	std::string s3("helli");

	trie.insert(s1);
	trie.insert(s2);
	trie.insert(s3);
}	

int main()
{
	insert();
    trie.remove("hello");
    trie.remove("hell");

	if (trie.search("107.108.11.123")) {
		std::cout << "String found 107.108.11.123!!" << std::endl;
    } else {
        std::cout << "want to add hello?" << std::endl;
    }

	if (trie.search("helli")) {
		std::cout << "String found helli!!" << std::endl;
    } else {
        std::cout << "want to add helli?" << std::endl;
    }

	if (trie.search("hell")) {
		std::cout << "String found hell!!" << std::endl;
	} else {
		std::cout << "want to add hell?" << std::endl;
	}
    trie.remove("helli");
	return 0;
}

