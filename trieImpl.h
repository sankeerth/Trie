#ifndef TRIE_IMPL_H
#define TRIE_IMPL_H

#include <iostream>
#include <string.h>
#include <vector>
#include "log.h"

class Node;

class TrieImpl {
  public:
  	TrieImpl();
  	~TrieImpl();
  	void insert(const std::string& str);
  	bool search(const std::string& str);
  	void remove(const std::string& str);
  	int getWordCount();
  private:
    bool removeWord(const std::string& str, Node *node, unsigned index);
  	Node *m_node;
  	int m_wordCount;
};

class Node {
  public:
  	Node();
  	~Node();
  	void setChar(const char& c);
  	char getChar();
  	void setEnd(bool value);
  	bool getEnd();
  	void appendChild(Node *child);
  	Node* getChild(const char& c);
  	bool removeChild(Node *child);
    bool isLeafNode();
  private:
  	char m_character;
  	bool m_endOfString;
  	std::vector<Node*> m_children;
};

#endif // TRIE_IMPL_H