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
        
        static Seq* AddFirst(Seq* head, int val)
        {
            Seq* newHead = new Seq;
            newHead->value = val;
            newHead->Next = head;
            return newHead;
        }
        
        int Size() const
        {
            int s = 1;
            Seq* next = Next;
            while (next)
            {
                s++;
                next = next->Next;
            }
            return s;
        }
};

Seq* RevertLinkedList(Seq* head);
std::string PrintLinkedList(Seq* head);