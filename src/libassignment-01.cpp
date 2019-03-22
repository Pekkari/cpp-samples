#include <libassignment-01.hpp>

Note::Note()
{
	title = "";
	text  = "";
	tags  = NULL;
}

Note::Note(std::string title, std::string text, std::string *tags)
{
	this->title = title;
	this->text  = text;
	this->tags  = tags;
}

Storyboard::Storyboard()
{
	this->notes = std::list<Note>(2048);
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
