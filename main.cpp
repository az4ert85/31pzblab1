#include "storage.h"
#include <iostream>
#include <string>
using namespace std;
int
main ()
{
  int notes;
  string method;

  cout << " Enter the number of entries:" << endl;
  cout << ">>";
  cin >> notes;
  storage variant8(true);
  storage *allNotes = new storage[notes];
  for (;;)
    {
      cout << ">>";
      cin >> method;

      if (method == "add")
	variant8.add (allNotes, notes);
      if (method == "edit")
	variant8.edit (allNotes);
      if (method == "search")
	variant8.search (allNotes, notes);
      if (method == "triage")
	variant8.triage (allNotes, notes);
      if (method == "del")
	variant8.del (allNotes);
      if (method == "print")
	variant8.print (allNotes, notes);

}

  // variant8.del(allNotes,notes);
  // variant8.print(allNotes,notes);



  delete[]allNotes;
}
