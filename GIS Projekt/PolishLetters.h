#pragma once

#include "stdafx.h"

string PL(const char * text)
{
	string result;
	for (; *text; text++)
		switch (*text)
		{
		case 'π': result += static_cast < char >(0xa5); break;
		case 'Ê': result += static_cast < char >(0x86); break;
		case 'Í': result += static_cast < char >(0xa9); break;
		case '≥': result += static_cast < char >(0x88); break;
		case 'Ò': result += static_cast < char >(0xe4); break;
		case 'Û': result += static_cast < char >(0xa2); break;
		case 'ú': result += static_cast < char >(0x98); break;
		case 'ø': result += static_cast < char >(0xbe); break;
		case 'ü': result += static_cast < char >(0xab); break;
		case '•': result += static_cast < char >(0xa4); break;
		case '∆': result += static_cast < char >(0x8f); break;
		case ' ': result += static_cast < char >(0xa8); break;
		case '£': result += static_cast < char >(0x9d); break;
		case '—': result += static_cast < char >(0xe3); break;
		case '”': result += static_cast < char >(0xe0); break;
		case 'å': result += static_cast < char >(0x97); break;
		case 'Ø': result += static_cast < char >(0xbd); break;
		case 'è': result += static_cast < char >(0x8d); break;
		default: result += *text; break;
		}
	return result;
}
