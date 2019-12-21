#pragma once
typedef struct WordLinkNode{
	WordLinkNode *next;
	CString word;
}WordLinkNode;
class WordLink {
public:
	void Init() {
		head = new WordLinkNode;
		head->next = NULL;
	}
	void Insert(CString put_word) {
		WordLinkNode *n,*p;
		p = head;
		while (p->next)
		{
			p = p->next;
		}
		n= new WordLinkNode;
		n->next = NULL;
		(n->word) = put_word;
		p->next = n;
	}
	void Delete(CString delete_word) {
		WordLinkNode *p;
		p = head;
		while (p->next->next)
		{
			p = p->next;
		}
		p->next = NULL;
	}
	CString Search(CString search_word) {
		WordLinkNode *p;
		p = head->next;
		while (p) {
			int n = p->word.Find(search_word);
			if (n>=0) {
				return p->word;
			}
			p = p->next;
		}
		return "字典中无此单词";
	}
public:
	WordLinkNode * head;
	WordLinkNode *p;
};
class WordBase
{
public:
	WordBase();
	~WordBase();
	void WordBaseInit();
	CString WordSearch(CString serch_word);
public:
	WordLink wl;
};

