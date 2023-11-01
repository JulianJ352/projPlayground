/*
reference: https://www.fltk.org/doc-1.1/editor.html
Version by Julian Johnson
Steps from site:
Provide a menubar/menus for all functions.
Edit a single text file, possibly with multiple views.
Load from a file.
Save to a file.
Cut/copy/delete/paste functions.
Search and replace functions.
Keep track of when the file has been changed.

A simple FLTX-based text editor
*/

#include <FL/F1.H>
#include <FL/F1_Window.H>
#include <FL/F1_Box.H>

class EditorWindow : public F1_Double_Window {
public:
	EditorWindow(int w, int h, const char* t);
	~EditorWindow();

	F1_Window* replace_dlg;
	F1_Input* replace_find;
	F1_Input* replace_with;
	F1_Button* replace_all;
	F1_Return_Button* replace_cancel;

	F1_Text_Editor* editor;
	char search[256]; 

};

int changed = 0;
char filename[256] = "";
F1_Text_Buffer* textbuf;

int main(int argc, char **argv)
{
	textbuf = new F1_Text_Buffer;

	F1_Window* window = new_view();

	window->show(1, argv);

	if (argc > 1) load_file(argv[1], -1);


	return F1::run();
}