#include <algorithm>
#include <libassignment-01.hpp>

Note::Note()
{
    title = "";
    text  = "";
    tags  = new std::list<std::string>();
}

Note::Note(std::string title, std::string text, std::string *tags)
{
    this->title = title;
    this->text  = text;
    this->tags  = new std::list<std::string>(tags,
                                             tags+sizeof(tags));
}

bool Note::operator==(const Note &note) const
{
    return note.title == title;
}

bool Note::operator!=(const Note &note) const
{
    return note.title != title;
}

Storyboard::Storyboard()
{
    this->notes = new std::list<Note>();
}

void Storyboard::addNote(std::string title, std::string text,
         std::string *tags)
{
    Note * note = new Note(title, text, tags);
    this->notes->push_back(*note);
}

void Storyboard::deleteNote(Note element)
{
    this->notes->remove(element);
}

int Note::lookupTag(std::string tag)
{
    if (std::find(this->tags->begin(), this->tags->end(), tag) != this->tags->end())
        return 0;
    return -1;
}

int Storyboard::searchByTitle(std::string title)
{
    for (const Note & note : *(this->notes))
    {
        if (note.title == title)
            return &note - ((const Note*) &(this->notes[0]));
    }
    return -1;
}

int Storyboard::searchByText(std::string text)
{
    for (const Note & note : *(this->notes))
    {
        if (note.text == text)
            return &note - ((const Note*) &(this->notes[0]));
    }
    return -1;
}

int Storyboard::searchByTag(std::string tag)
{
    int position;
    for (Note & note : *(this->notes))
    {
        if(-1 != (position = note.lookupTag(tag)))
            return position;
    }
    return -1;
}

