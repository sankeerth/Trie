#include <algorithm>
#include "trieImpl.h"

TrieImpl::TrieImpl()
	: m_node (new Node)
	, m_wordCount(0)
{

}

TrieImpl::~TrieImpl()
{
	// TODO: need to delete all the nodes
}

void TrieImpl::insert(const std::string& str)
{
	if (str.empty() && !m_node->getEnd()) {
		// set empty string as a word
		m_node->setEnd(true);
		m_wordCount++;
		return;
	}

	Node *current, *child;
	current = m_node;

	for (unsigned i = 0; i < str.length(); ++i) {
		child = current->getChild(str[i]);
		if (child != NULL) {
			current = child;
		} else {
			child = new Node();
			child->setChar(str[i]);
			current->appendChild(child);
			current = child;
		}
	}
	current->setEnd(true);
	m_wordCount++;
}

bool TrieImpl::search(const std::string& str)
{
	Node *child, *current = m_node;
	for (unsigned i = 0; i < str.length(); ++i) {
		child = current->getChild(str[i]);
		if (child) {
			current = child;
		} else {
			return false;
		}
	}

	if (current->getEnd()) {
		return true;
	} else {
		return false;
	}
}

void TrieImpl::remove(const std::string& str)
{
	removeWord(str, m_node, 0);
}

bool TrieImpl::removeWord(const std::string& str, Node *node, unsigned index)
{
	Node *current = node, *child;
	child = current->getChild(str[index]);

	if (!child) {
		return false;
	}

	if (index == str.length()-1) {
		if (current->removeChild(child))
			return true;
		else
			return false;
	} else {
        if (removeWord(str, child, index+1) && child->isLeafNode()) {
			return current->removeChild(child);
		}
	}
	return false;
}

int TrieImpl::getWordCount()
{
	return m_wordCount;
}

// Node Implementation

Node::Node()
	: m_character(' ')
	, m_endOfString(false)
{}

Node::~Node()
{}

void Node::setChar(const char& c)
{
	m_character = c;
}

char Node::getChar()
{
	return m_character;
}

void Node::setEnd(bool value)
{
	m_endOfString = value;
}

bool Node::getEnd()
{
	return m_endOfString;
}

void Node::appendChild(Node *child)
{
	m_children.push_back(child);
}

Node* Node::getChild(const char& c)
{
	std::vector<Node*>::iterator it;
	for (it = m_children.begin(); it != m_children.end(); ++it) {
		if ((*it)->m_character == c) {
			return *it;
		}
	}
	return NULL;
}

bool Node::removeChild(Node *child)
{
	if (child->m_children.size()) {
		child->setEnd(false);
		return false;
	} else {
		m_children.erase(std::remove(m_children.begin(), m_children.end(), child));
		delete(child);
		return true;	
	}
}

bool Node::isLeafNode()
{
	return m_children.empty();
}
