// Midterm #2 Handouts Midterm A

#ifndef BookClassH
#define BookClassH
#include "BookNode.h"

class BookClass : public BookNode
{
	BookNode *head;
	BookNode *curr;
	public
	BookClass();
	~BookClass();
};`

BookClass::BookClass() : head(NULL), curr(NULL)
{}

BookClass::~BookClass()
{
	for (BookNode *ptr = head, ptr, ptr = head)
	{
		head = ptr->next;
		delete ptr;
	}
}

BookList::insert(char *t, char *a)
{
	if (curr == NULL)
	{
		curr = head;

		if(curr == NULL)
		{
			head = new BookNode(t, a, NULL, NULL);
			return;
		} // first item
	} // if

	if(*curr->author < a)
	{
		while(curr->next && *curr->author < a)
			curr = curr->next;

		if(*curr->author < a)
			curr->next = new BookNode(t, a, curr, NULL);
		else
			if(*curr->author > a)
				curr->prev = curr->prev->next = new BookNode(t, a, curr->prev, curr);
	}
	else
		if(*curr->author > a)
		{
			while(curr->prev && *curr->author > a)
				curr = curr->prev;

			if(*curr->author > a)
				head = curr->prev = new BookNode(t, a, NULL, cur);
			else
				if(*curr->author < a)
					curr->next = curr->next->prev = new BookNode(t, a, curr, curr->next);
		}
} // insert

bool BookClass::find(char *titles)
{
	if (!curr)
	{
		curr = head;
		if (!curr)
			return false;
	}

	if (*curr->titles == *titles)
		return true;
	else
		if (*curr->titles > *titles)
		{
			while (*curr->titles > *titles)
				curr = curr->prev;
		}
		else
		{
			while (*curr->titles < *titles)
				curr = curr->next;
		}

	if (curr->*titles = *titles)
		return true;
	else
		return false;
}

bool BookClass::find(char *authors)
{
	if (!curr)
	{
		curr = head;
		if (!curr)
			return false;
	}

	if (*curr->authors == *authors)
		return true;
	else
		if (*curr->authors > *authors)
		{
			while (*curr->authors > *authors)
				curr = curr->prev;
		}
		else
		{
			while (*curr->authors < *authors)
				curr = curr->next;
		}

	if (curr->*authors
	 = *authors)
		return true;
	else
		return false;
}

bool BookList::operator== (const char *auth)
{
	return strcmp(author, auth) == 0;
}

bool BookList::operator< (const char *auth)
{
	return strcmp(author, auth) < 0;
}

bool BookList::operator> (const char *auth)
{
	return strcmp(author, auth) > 0;
}

BookNode(char *titles, char * authors)
{
	this->titles = new char(strlen(titles) + 1);
	strcpy(this->titles, titles);
	this->authors = new char(strlen(authors) + 1);
	strcpy(this->authors, authors);
}

~BookNode()
{
	delete []authors;
	delete []titles;
}