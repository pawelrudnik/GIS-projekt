#pragma once

#include "stdafx.h"

string PL(const char * text)
{
	string result;
	for (; *text; text++)
		switch (*text)
		{
		case '�': result += static_cast < char >(0xa5); break;
		case '�': result += static_cast < char >(0x86); break;
		case '�': result += static_cast < char >(0xa9); break;
		case '�': result += static_cast < char >(0x88); break;
		case '�': result += static_cast < char >(0xe4); break;
		case '�': result += static_cast < char >(0xa2); break;
		case '�': result += static_cast < char >(0x98); break;
		case '�': result += static_cast < char >(0xbe); break;
		case '�': result += static_cast < char >(0xab); break;
		case '�': result += static_cast < char >(0xa4); break;
		case '�': result += static_cast < char >(0x8f); break;
		case '�': result += static_cast < char >(0xa8); break;
		case '�': result += static_cast < char >(0x9d); break;
		case '�': result += static_cast < char >(0xe3); break;
		case '�': result += static_cast < char >(0xe0); break;
		case '�': result += static_cast < char >(0x97); break;
		case '�': result += static_cast < char >(0xbd); break;
		case '�': result += static_cast < char >(0x8d); break;
		default: result += *text; break;
		}
	return result;
}
