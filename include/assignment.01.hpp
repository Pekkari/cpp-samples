/* In this exercise we want to design a Storyboard. Our version of the Storyboard
 * contains arbitrary many notes (imagine it like putting sticky notes on a board).
 * Every note has a title, a text and a set of tags. E.g.
 * 	- title: "Test Traceplayer"
 * 	- text: "Implement a unit test for the class Traceplayer of the spark core framework."
 * 	- tags: {"unit test", "traceplayer", "testing", "spark core"}
 * 
 * Our Storyboard should enable us to search for notes by title, text and tags.
 * E.g.:
 *      searchByTitle("Test Traceplayer")
 *      searchByTag({"testing", "unit test"})
 *   	searchByText("Implement a unit test for the class Traceplayer of the spark core framework.")
 * For the sake of simplicity we don't want to do any similiarity or prefix matching when
 * searching for a title, tag or text. Only an exact match should give results.
 * 
 * The skeleton code below can be used as a starting point but doesn't have to.
 * The comments "fill in" are placeholders where you definitely have to put in some code when 
 * you use this skeleton code. But this doesn't mean that you shouldn't or can't put code anywhere else.
 * 
 * Also write some simple unit tests to show how you would test the functionality of the Storyboard.
 * Don't use any testing framework. Simple if-statements are sufficient for this exercise.
 * 
 * Hint: Think about performance versus memory tradeoffs in your design, so you can give good 
 *       reasons for your decision. 
 */

#ifndef ASSIGNMENT_01_HPP
#define ASSIGNMENT_01_HPP
#include <string>
#include <list>

class Note
{
public:
	std::string title;
	std::string text;
	std::list<std::string> tags;
	Note();
	Note(std::string title, std::string text, std::string *tags);
	bool operator==(const Note &note) const;
};
 
class Storyboard
{
public:
	void addNote(std::string title, std::string text,
		     std::string *tags);
	void deleteNote(Note element);
	int searchByTitle(std::string title);
	int searchByText(std::string text);
	int searchByTag(std::string tag);
	Storyboard();
	
private:
	std::list<Note> notes;
};
#endif
