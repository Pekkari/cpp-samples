#include <cstring>
#include <iostream>
#include <libassignment-01.hpp>

std::string test_title = "Yet another storyboard framework coming: YASBF";
std::string test_text = "New storyboard under development by Youwillregretit co.";
std::string test_tags[] = { "#software", "#opensource" };

int test_note_empty_constructor()
{
	Note * note = new Note();
	std::string * null_list = NULL;

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
	if (null_list != note->tags)
	{
		std::cout << "Tags mismatch\n";
		return -1;	
	}

	return 0;
}

int test_note_constructor(std::string title, std::string text, std::string * tags)
{
	Note * note = new Note(test_title, test_text, test_tags);

	if (note->title.compare(test_title))
	{
		std::cout << "Title mismatch\n";
		return -1;
	}
	if (note->text.compare(test_text))
	{
		std::cout << "Text mismatch\n";
		return -1;
	}
	if (test_tags != note->tags)
	{
		std::cout << "Tags mismatch\n";
		return -1;	
	}

	return 0;
}

int test_storyboard_empty_constructor()
{
	std::list<Note> empty_storyboard;
	Storyboard * storyboard = new Storyboard();

	if (storyboard->notes != empty_storyboard)
		return -1;

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
		std::cout << "Error creating note with title:\n" << test_title << \
			"\ntext: " << test_text << "\ntags:" ;
		for (const auto& tag: test_tags)
			std::cout << tag << ' ';
		return -1;
	}

/*	if (test_storyboard_empty_constructor())
	{
	}	

	if ()
	{
	}
*/

	return 0;
}
