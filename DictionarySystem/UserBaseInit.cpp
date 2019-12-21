#include "stdafx.h"
#include "UserBaseInit.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
#include <stdlib.h>
using namespace std; 
UserBaseInit::UserBaseInit()
{
	
}
UserBaseInit::~UserBaseInit()
{
}

void UserBaseInit::Input() {
	CFile of;
	of.Open(_T("UserBase.txt"), CFile::modeReadWrite | CFile::modeNoTruncate);
	//WORD unicode = 0xFEFF;  //’‚æ‰÷ÿ“™****************
	of.SeekToEnd();
	of.Write(username,strlen(username));
	of.Write("\r\n", 2);
	of.Write(password, strlen(password));
	of.Write("\r\n", 2);
	of.Close();
	data_base_size++;
}
void UserBaseInit::ReadData() {
	CString judge;
	int i = 0;
	CStdioFile file;
	file.Open(_T("UserBase.txt"), CFile::modeRead);
	for (int i = 0; i < data_base_size; i++) {
		file.ReadString(user[i].txt_username);
		file.ReadString(user[i].txt_password);
		i++;
	}
	file.Close();
}

bool UserBaseInit::Check(CString username,CString password) {
	CString judge_username;
	CString judge_password;
	CStdioFile file;
	file.Open(_T("UserBase.txt"), CFile::modeRead);
	while (file.ReadString(judge_username) && file.ReadString(judge_password)) {
		if (judge_username == username && judge_password == password) {
			return true;
		}
	}
	return false;
}
