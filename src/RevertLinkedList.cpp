#include "RevertLinkedList.h"

#include <sstream>

Seq* RevertLinkedList(Seq* head)
{
	if (!head || !head->Next)
		return head;
	
	Seq* prev = head;
	Seq* cur = head->Next;
	prev->Next = nullptr;
	
	while(cur)
	{
		Seq* next = cur->Next;
		cur->Next = prev;
		prev = cur;
		cur = next;
	}
	
	return prev;
}

std::string PrintLinkedList(Seq* head)
{
	std::ostringstream os;
	while(head)
	{
		os << head->value;
		if (head->Next)
			os << "->";
		head = head->Next;
	}
	return os.str();
}