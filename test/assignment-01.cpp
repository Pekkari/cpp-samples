#include <cstring>
#include <iostream>
#include <libassignment-01.hpp>

std::string test_title = "Yet another storyboard framework coming: YASBF";
std::string test_text = "New storyboard under development by Youwillregretit co.";
std::string tags[] = { "#software", "#opensource" };
std::list<std::string> test_tags = new std::list<std::string>(tags, tags+sizeof(tags) / sizeof(std::string *));

int test_note_empty_constructor()
{
    Note * note = new Note();
    std::string * null_list;

    if (note->title.compare(""))
    {
        std::cout << "Title mismatch\n";
        return -1;
    }
    if (note->text.compare(""))
    {
        std::cout << "Text mismatch\n";
        return -1;
    }
    if (!note->tags->empty())
    {
        std::cout << "Tags mismatch\n";
        return -1;    
    }

    return 0;
}

int test_note_constructor(std::string title, std::string text,
                          std::string * tags)
{
    Note * note = new Note(title, text, tags);
    std::list<std::string> * listed_test_tags = \
        new std::list<std::string>(tags, tags+sizeof(tags) /
                                   sizeof(std::string *)); 

    if (note->title.compare(title))
    {
        std::cout << "Title mismatch\n";
        return -1;
    }
    if (note->text.compare(text))
    {
        std::cout << "Text mismatch\n";
        return -1;
    }
    if (listed_test_tags != note->tags)
    {
        std::cout << "Tags mismatch\n";
        return -1;    
    }

    return 0;
}

int test_storyboard_empty_constructor()
{
    Storyboard * sb = new Storyboard();
    return !sb->notes->empty();
}

int test_note_lookup_tag()
{
    Note * note = new Note(test_title, test_text, test_tags);
    return !note->lookupTag("#opensource");
}

int test_add_note(std::string title,std::string text,
          std::string * tags)
{
    Storyboard * sb = new Storyboard();
    sb->addNote(test_title, test_text, test_tags);
    return sb->notes->empty();
}

int test_delete_note()
{
    Storyboard * sb = new Storyboard();
    Note * note = new Note(test_title, test_text, test_tags);
    sb->addNote(test_title, test_text, test_tags);
    if (sb->notes->empty())
    {
        std::cout << "Error adding the note\n";
        return -1;
    }
    sb->deleteNote(*note);
    return !sb->notes->empty();
}

int test_search_by_title(std::string title)
{

    return 0;
}

int test_search_by_text(std::string text)
{

    return 0;
}

int test_search_by_tag(std::string tag)
{

    return 0;
}

int main(void)
{
    if (test_note_empty_constructor())
    {
        std::cout << "Error creating empty note\n";
        return -1;
    }

    if (test_note_constructor(test_title, test_text, test_tags))
    {
        std::cout << "Error creating note with title:\n" << \
            test_title << "\ntext: " << test_text << "\ntags:" ;
        for (const auto& tag: test_tags)
            std::cout << tag << ' ';
        return -1;
    }

    if(test_note_lookup_tag())
        std::cout << "Error finding the tag in note\n";
        return -1;

    if (test_storyboard_empty_constructor())
    {
        std::cout << "Error creating empty Storyboard\n";
        return -1;
    }    

    if (test_add_note(test_title, test_text, test_tags))
    {
        std::cout << "Error adding a note\n";
        return -1;
    }

    if (test_delete_note())
    {
        std::cout << "deleting note\n";
        return -1;
    }

    return 0;
}
