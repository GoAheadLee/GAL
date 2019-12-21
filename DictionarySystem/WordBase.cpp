#include "stdafx.h"
#include "WordBase.h"


WordBase::WordBase()
{
	WordBaseInit();
}


WordBase::~WordBase()
{
}
void WordBase::WordBaseInit() {
	wl.Init();
	CString base_word;
	CStdioFile file;
	file.Open(_T("Ó¢ºº´Êµä.txt"), CFile::modeRead);
	while (file.ReadString(base_word)) {
		wl.Insert(base_word);
	}
}
CString WordBase::WordSearch(CString search_word) {
	return wl.Search(search_word);
}