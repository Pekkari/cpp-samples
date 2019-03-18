#include <stdio.h>
#include <assignment.01.hpp>

Note::Note()
{
	title = "";
	text  = "";
	tags  = std::list<std::string>(128);
}

Note::Note(std::string title, std::string text, std::string *tags)
{
	title = title;
	text  = text;
	tags  = tags;
}

Storyboard::Storyboard()
{
	notes = std::list<Note>(2048);
}

void Storyboard::addNote(std::string title, std::string text,
	     std::string *tags)
{
	Note * note = new Note(title, text, tags);
	notes.push_back(*note);
}
void Storyboard::deleteNote(Note element)
{
	notes.remove(element);
}

bool Note::operator==(const Note &note) const
{
	return note.title == title;
}

int main(void)
{
	return 0;
}
