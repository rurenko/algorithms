#pragma once

#include <string>

struct Seq
{
	int value;
	Seq* Next;

	Seq* AddNext(int val)
	{
		Seq* tmp = new Seq;
		tmp->value = val;
		tmp->Next = nullptr;
		Next = tmp;
		return Next;
	}
};

Seq* RevertLinkedList(Seq* head);
std::string PrintLinkedList(Seq* head);