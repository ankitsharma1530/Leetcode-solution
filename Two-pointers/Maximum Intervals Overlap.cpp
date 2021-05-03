class Solution{
	
	public:
	vector<int> findMaxGuests(int Entry[], int Exit[], int N)
	{
	   // Sort arrival and exit arrays
	   sort(Entry, Entry+N);
	   sort(Exit, Exit+N);
	 
	   // guests_in indicates number of guests at a time
	   int guests_in = 1, max_guests = 1, time1 = Entry[0];
	   int i = 1, j = 0;
	 
	   // Similar to merge in merge sort to process
	   // all events in sorted order
	   while (i < N && j < N)
	   {
	      // If next event in sorted order is arrival,
	      // increment count of guests
	      if (Entry[i] <= Exit[j])
	      {
	          guests_in++;
	 
	          // Update max_guests if needed
	          if (guests_in > max_guests)
	          {
	              max_guests = guests_in;
	              time1 = Entry[i];
	          }
	          i++;  //increment index of arrival array
	      }
	      else // If event is exit, decrement count
	      {    // of guests.
	          guests_in--;
	          j++;
	      }
	   }
	    vector<int> res;
	    res.push_back(max_guests);
	    res.push_back(time1);
	    
	    return res;
	}

};
