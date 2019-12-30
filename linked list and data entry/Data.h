#pragma once
#include "kit.h"

class Data
{
private:
	class Element
	{
	public:
		Element(int val, Element* pNext)
			:
			value(val),
			pNext(pNext)
		{}
		Element(const Element& src)
			:
			value(src.value)
		{
			if (src.pNext != nullptr)
			{
				pNext = new Element(*src.pNext);
			}
		}
		~Element()
		{
			delete pNext;
			pNext = nullptr;
		}
		int GetValue()
		{	
			return value;
		}
		Element* Disconnect()
		{
			if (pNext != nullptr)
			{
				Element* temp = nullptr;
				temp = pNext;
				pNext = nullptr;
				return temp;
			}
		}
		void Display(char* buffer)
		{
			if (pNext != nullptr)
			{
				kit::print("\n");
				kit::int2str(buffer, value);
				kit::print(buffer);
				kit::print("\n");
				pNext->Display(buffer);
			}
		}
	public:
		int value;
		Element* pNext = nullptr;
	};
public:
	Data() = default;
	Data(const Data& source)
	{
		if (!source.Empty())
		{
			pHead = new Element(*source.pHead);
		}
	}
	Data& operator=(const Data& source)
	{
		delete pHead;
		pHead = nullptr;
		if (!source.Empty())
		{
			pHead = new Element(*source.pHead);
		}
		return *this;
	}
	void PushTop(int val)
	{
		pHead = new Element(val, pHead);
	}
	void PushAnywhere(int val, int pos)
	{
		Element* prev = nullptr;
		Element* curr = nullptr;
		Element* temp = nullptr;
		curr = pHead;
		if (!Empty())
		{
			for (int i = 0; i < pos && curr!=nullptr; i++)
			{
				prev = curr;
				curr = curr->pNext;
			}
			temp = new Element(val, curr);
			prev->pNext = temp;
		}
	}
	int PopTop()
	{
		if (!Empty())
		{
			int tempval = pHead->GetValue();
			Element* temp = nullptr;
			temp = pHead;
			pHead = pHead->Disconnect();
			delete temp;
			return tempval;
		}
		else
			return -1;
	}
	int PopAnywhere(int pos)
	{
		if (!Empty())
		{
			Element* prev1 = nullptr;
			Element* curr = nullptr;
			Element* prev = nullptr;
			curr = pHead;
			for (int i = 0; i < pos && curr != nullptr; i++)
			{
				prev1 = prev;
				prev = curr;
				curr = curr->pNext;
			}
			int tempval = prev->GetValue();
			prev1->pNext = prev->Disconnect();
			delete prev;
			return tempval;
		}
		else
			return -1;
	}
	void Display(char* buffer)
	{
		if (!Empty())
		{
			pHead->Display(buffer);
		}
	}
	bool Empty()const
	{
		return pHead == nullptr;
	}
private:
	Element* pHead = nullptr;
};