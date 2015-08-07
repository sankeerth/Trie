#include "trie.h"
#include "trieImpl.h"

Trie::Trie()
	: m_impl(new TrieImpl)
{}

Trie::~Trie()
{
	LOG("Trie deleted");
	if (m_impl)
		delete m_impl;
}

Trie::Trie(Trie& )
{
	// disable copy ctor since this makes only
	// a shallow copy of Trie which will contain
	// the same m_impl object
	// Hence deletion could cause crash
}

void Trie::insert(const std::string& str)
{
	m_impl->insert(str);
}

bool Trie::search(const std::string& str)
{
	return m_impl->search(str);
}

void Trie::remove(const std::string& str)
{
	return m_impl->remove(str);
}

int Trie::getWordCount()
{
	return m_impl->getWordCount();
}