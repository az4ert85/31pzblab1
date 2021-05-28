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
  storage variant14(true);
  storage *allNotes = new storage[notes];
  for (;;)
    {
      cout << ">>";
      cin >> method;

      if (method == "add")
	variant14.add (allNotes, notes);
      if (method == "edit")
	variant14.edit (allNotes);
      if (method == "search")
	variant14.search (allNotes, notes);
      if (method == "triage")
	variant14.triage (allNotes, notes);
      if (method == "del")
	variant14.del (allNotes);
      if (method == "print")
	variant14.print (allNotes, notes);

}

  // variant14.del(allNotes,notes);
  // variant14.print(allNotes,notes);



  delete[]allNotes;
}
