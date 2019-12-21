#pragma once
typedef struct {
	CString txt_username;
	CString txt_password;
}USER;
class UserBaseInit
{
public:
	UserBaseInit();
	~UserBaseInit();
	void Input();
	void ReadData();
	bool Check(CString username,CString password);
	
public:
	CString username;
	CString password;
	USER *user;
	int data_base_size=0;
};

