#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <string.h>

class TrieImpl;

class Trie {
  public:
  	Trie();
  	~Trie();
  	void insert(const std::string& str);
  	bool search(const std::string& str);
  	void remove(const std::string& str);
  	int getWordCount();
  private:
  	Trie(Trie& );
  	TrieImpl* m_impl;
};

#endif